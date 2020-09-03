#pragma once
#include <regex>

class Person
{
public:
    Person()
        :name(nullptr), initial(NULL), age(NULL), number(NULL), birthDate(nullptr)
    {};
    Person operator=(Person copy) = delete;
private:
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

    bool IsValidBirthday(char* birthday);
    //**Only supports Norwegian numbers**//
    bool IsValidNumber(unsigned long number);
    bool IsValidAge(unsigned short age);
    bool IsValidInitial(char init);
    bool IsValidName(char *name);
};
