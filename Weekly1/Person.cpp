#include "Person.h"
#include <ctime>
#include <iostream>
#include <stdlib.h>


const char* Person::GetName() const
{
    return name;
}

const char Person::GetInitial() const
{
    return initial;
}

const unsigned short Person::GetAge() const
{
    return age;
}

const unsigned long long Person::GetNumber() const
{
    return number;
}

const char* Person::GetBirthDay() const
{
    return birthDate;
}

void Person::SetName(char* name)
{
    //std::cout << name << std::endl;
    if (IsValidName(name))
        this->name = name;
    else
        throw ErrorCodes::InvalidName;
}

void Person::SetInitial(char init)
{
    if (IsValidInitial(init))
        this->initial = init;
    else
        throw ErrorCodes::InvalidInitial;
}

void Person::SetAge(unsigned short age)
{
    if (IsValidAge(age))
        this->age = age;
    else
        throw ErrorCodes::InvalidAge;
}

void Person::SetNumber(unsigned long long number)
{
    if (IsValidNumber(number))
        this->number = number;
    else
        throw ErrorCodes::InvalidPhoneNumber;
}

void Person::SetBirthday(char* date)
{
    if (IsValidBirthday(date))
        birthDate = date;
    else
        throw ErrorCodes::InvalidBirthday;
}

bool Person::IsValidBirthday(char* birthday)
{
    std::regex m("([0-9]{1,2}/[0-9]{1,2}/[0-9]{4})");
    if (std::regex_match(birthday, m))
    { 
        //Gotta make a copy, code after this will change the buffer
        char buff[40];
        memcpy(buff, birthday, strlen(birthday));
        //Do a last check to see if the date exist, will do this in integer format, since I know it can't be negative inside this block, will make my next calculations easier
        //splitting string by / then converting it to int    
        char* tok = NULL;  
        const int day = atoi(strtok_s(buff, "/", &tok));
        const int month = atoi(strtok_s(NULL, "/", &tok));
        const int year = atoi(strtok_s(NULL, "/", &tok));
        //std::cout << day << " " << month << " " << year << std::endl;
            
        const __m128i dmy = _mm_setr_epi32(day, month, year, 0); //{ day, month, year, 0 };
        if (IsDateValid(dmy))
            return false;

        return true;
    }
    return false;
}

bool Person::IsValidNumber(unsigned long long number)
{
    //TODO: add a check here later if required
     return true;

}

bool Person::IsValidAge(unsigned short age)
{
    if (age < (unsigned short)150)
        return true;
    return false;
}

bool Person::IsValidInitial(char init)
{
    std::regex search(" |-|_");
    auto result = std::regex_replace(name, search, "");
    std::regex r('['+result+']');

    if (std::regex_match(&init, r))
    {
        if (memcmp(&result[0], &init, 1))
            return false;//Can make this optional -> printf("Initial doesn't match the first letter in your name");
        return true;
    }
       
    return false;
}

bool Person::IsValidName(char* name)
{
    std::regex r("[a-å- |A-Å-]+");
    if (std::regex_match(name, r))
        return true;

    return false;
}
