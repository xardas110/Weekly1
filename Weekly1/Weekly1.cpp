#include "Person.h"
#include <iostream>
using namespace std;

//Helper functions
void CheckCin(istream& cin)
{
    if (!cin)
        throw exception("Invalid format to cin");
}

void EnterName(char* buff)
{
    cout << "Name(Firstname Lastname): ";
    cin.getline(buff, strlen(buff));   
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}


int main()
{
    Person person;
    char nameBuffer[100] = {};
    char birthDayBuffer[40] = {};
    char initialBuffer[2] = {};
    unsigned short age = (unsigned short)0;
    unsigned long phoneNumberBuffer = 0UL;
   
    EnterName(nameBuffer);
    
    cout << "Initial: ";
    cin.getline(initialBuffer, _countof(initialBuffer));
    cin.clear();
    cout << "Phone Number: ";
    cin >> phoneNumberBuffer;
    cin.clear();
    cout << "Age: ";
    cin >> age;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Birthday(dd/mm/yyyy): ";
    cin.getline(birthDayBuffer, _countof(birthDayBuffer));
   
    cin.clear();

    try
    {
        person.SetBirthday(birthDayBuffer);
        person.SetName(nameBuffer);
        person.SetInitial(initialBuffer[0]);
        person.SetNumber(phoneNumberBuffer);
        person.SetAge(age);
    }
    catch (exception err)
    {
        cout << "Error occured: " << err.what() << endl;
        if (memcmp(err.what(), "Invalid name", strlen(err.what())))
        {
            char temp = ' ';
            cout << "Name is invalid, do you want to fix? y/n:";
            if (temp == 'y')
                EnterName(nameBuffer);
        }
    }

    //cout << "Your initial is: " << initialBuffer << endl;
    //cout << "Your phone number is: " << phoneNumberBuffer << endl;
}

