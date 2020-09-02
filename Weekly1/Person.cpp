#include "Person.h"

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
    {       
        this->initial = init;
        if (memcmp(&name[0], &init, 1))
            throw std::exception("Your first initial doesn't match the first letter in your name, are you sure this is right?");
    }
    else
        throw std::exception("Initial doesn't match name");
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
        throw std::exception("Invalid birth date");
}

bool Person::ValidBirthDay(char* birthday)
{
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
#include <iostream>
bool Person::ValidInitial(char init)
{
    std::regex search(" |-");
    auto result = std::regex_replace(name, search, "");
    std::regex r('['+result+']');

    if (std::regex_match(&init, r))
        return true;
    return false;
}

bool Person::ValidName(char* name)
{
    std::regex r("[a-�- |A-�-]+");
    if (std::regex_match(name, r))
        return true;

    return false;
}
