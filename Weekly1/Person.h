#ifndef PERSON_H
#define PERSON_H
#include "Helpers.h"
#include "ErrorCodes.h"

#define AGELIMIT 150

class Person
{
public:
    Person()
        :name(nullptr), initial(NULL), age(NULL), number(NULL), birthDate(nullptr)
    {};
    Person operator=(Person copy) = delete;
private:
    char* name;
    char initial;
    unsigned short age;
    unsigned long long number;
    char* birthDate;
public:
    const char* GetName() const;
    const char GetInitial() const;
    const char* GetBirthday() const;
    const unsigned short GetAge() const;
    const unsigned long long GetNumber() const;
    
    void SetName(char* name);
    void SetInitial(char init);
    void SetAge(unsigned short age);
    void SetNumber(unsigned long long number);
    void SetBirthday(char* date);

    bool IsValidBirthday(char* birthday);
    bool IsValidNumber(unsigned long long number);
    bool IsValidAge(unsigned short age);
    bool IsValidInitial(char init);
    bool IsValidName(char *name);
};
#endif // !PERSON