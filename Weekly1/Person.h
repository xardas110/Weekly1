#pragma once
#include <regex>

class Person
{
public:
    Person()
    {};
    Person operator=(Person copy) = delete;
private:
    //**For practice purpose I choose to make these private, only way to access is trought Set functions **//
    char* name;//4bytes
    char initial;
    unsigned short age;
    unsigned long number; //4bytes
    char* birthDate;

public:
    const char* GetName() const;
    const char GetInitial() const;
    const char* GetBirthDay() const;
    const unsigned short GetAge() const;
    const unsigned long GetNumber() const;
    
    void SetName(char* name);
    void SetInitial(char init);
    void SetAge(unsigned short age);
    void SetNumber(unsigned long number);
    void SetBirthday(char* date);

    bool ValidBirthDay(char* birthday);
    //**Only support Norwegian numbers, just for illustrative purpose **//
    bool ValidNumber(unsigned long number);
    bool ValidAge(unsigned short age);
    bool ValidInitial(char init);
    //** I don't want to make regex too restrictive, should I?**//
    bool ValidName(char *name);
};
