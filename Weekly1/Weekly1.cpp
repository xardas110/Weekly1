#include "Person.h"
#include <iostream>
using namespace std;

//Helper functions
void CheckCin(istream &cin)
{
    if (!cin)
        throw exception("Invalid format to cin");
}



int main()
{
    Person person;
    char nameBuffer[100] = {};
    char birthDayBuffer[40] = {};
    char initialBuffer[2] = {};
    unsigned short age = (unsigned short)0;
    unsigned long phoneNumberBuffer = 0UL;
    
 /*
    cout << "Please enter your full name: ";
    cin.getline(nameBuffer, _countof(nameBuffer));
    cin.clear(); 
    cout << "What's your initial? ";
    cin.getline(initialBuffer, _countof(initialBuffer));
    cin.clear();
    cout << "Phone Number: ";
    cin >> phoneNumberBuffer;
    
    cout << "Enter age: ";
    cin >> age;
    cout << "Your age is: " << age << endl;
    */
    cout << "Enter birthDay(dd/mm/yyyy): ";
    cin.getline(birthDayBuffer, _countof(birthDayBuffer));

    try
    {
        /*
        person.SetName(nameBuffer);
        person.SetInitial(initialBuffer[0]);
        person.SetNumber(phoneNumberBuffer);
        person.SetAge(age);
        */
    }
    catch (exception err)
    {
        cout << "Error occured: " << err.what() << endl;
    }


    cout << "Your initial is: " << initialBuffer << endl;
    cout << "Your phone number is: " << phoneNumberBuffer << endl;
}

