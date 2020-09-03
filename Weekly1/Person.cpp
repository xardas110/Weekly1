#include "Person.h"
#include <ctime>
#include <iostream>
#include "Helpers.h"
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

const unsigned long Person::GetNumber() const
{
    return number;
}

const char* Person::GetBirthDay() const
{
    return birthDate;
}

void Person::SetName(char* name)
{
    if (ValidName(name))
        this->name = name;
    else
        throw std::exception("Invalid name");
}

void Person::SetInitial(char init)
{
    if (ValidInitial(init))     
        this->initial = init;
    else
        throw std::exception("Initial doesn't match name or first letter in your name doesn't match");
}

void Person::SetAge(unsigned short age)
{
    if (ValidAge(age))
        this->age = age;
    else
        throw std::exception("Invalid age, max age is 149");
}

void Person::SetNumber(unsigned long number)
{
    if (ValidNumber(number))
        this->number = number;
    else
        throw std::exception("Invalid number");
}

void Person::SetBirthday(char* date)
{
    if (ValidBirthDay(date))
        birthDate = date;
    else
        throw std::exception("Invalid birthday");
}

bool Person::ValidBirthDay(char* birthday)
{
    std::regex m("([0-9]{1,2}/[0-9]{1,2}/[0-9]{4})");
    if (std::regex_match(birthday, m))
    { 
        //Do a last check to see if the date exists, will do this in integer format, since I know it can't be negative inside this block, will make my next calculations easier
        //splitting string by / then converting it to int
        char* tok = NULL;  
        const int day = atoi(strtok_s(birthday, "/", &tok));
        const int month = atoi(strtok_s(NULL, "/", &tok));
        const int year = atoi(strtok_s(NULL, "/", &tok));
        //std::cout << day << " " << month << " " << year << std::endl;
            
        const __m128i container = _mm_setr_epi32(day, month, year, 0); //{ day, month, year, 0 };
        if (IsDateValid(container))
            return false;
        return true;
    }
    return false;
}

bool Person::ValidNumber(unsigned long number)
{
    if (number < 99999999UL)
        return true;
    return false;
}

bool Person::ValidAge(unsigned short age)
{
    if (age < (unsigned short)150)
        return true;
    return false;
}

bool Person::ValidInitial(char init)
{
    std::regex search(" |-");
    auto result = std::regex_replace(name, search, "");
    std::regex r('['+result+']');

    if (std::regex_match(&init, r))
    {
        if (memcmp(&result[0], &init, 1))
            printf("Initial doesn't match the first letter in your name");
        return true;
    }
       
    return false;
}

bool Person::ValidName(char* name)
{
    std::regex r("[a-å- |A-Å-]+");
    if (std::regex_match(name, r))
        return true;

    return false;
}
