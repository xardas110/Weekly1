//Will not use precompiled headers since it's a short program
#include "ErrorCodes.h"
#include "Helpers.h"
#include "Person.h"
#include <iostream>
using namespace std;
int main()
{
    Person person;
    char nameBuffer[100]{};
    char birthDayBuffer[40]{};
    char initialBuffer[2]{};
    unsigned short age = (unsigned short)0;
    unsigned long long phoneNumberBuffer = 0UL;
INPUT: 
    cInput("Name(Firstname Lastname): ", nameBuffer, 100);
    cInput("Initial: ", initialBuffer, 2);//Seems like the minimum buffer requirment for cin.getline is 2 bytes, can't seem to make it work with 1 byte
REDOAGE:
    if (!CheckAge(cin, age))
    { 
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        goto REDOAGE;
    }
REDOPHONE:
    if (!CheckPhone(wcin, phoneNumberBuffer))
    {
        wcin.clear();
        wcin.ignore(INT_MAX, '\n');
        goto REDOPHONE;
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cInput("Birthday(dd/mm/yyyy): ", birthDayBuffer, 40);
TRY:
    try
    {     
        person.SetName(nameBuffer);
        person.SetInitial(initialBuffer[0]);
        person.SetAge(age);
        person.SetNumber(phoneNumberBuffer);
        person.SetBirthday(birthDayBuffer);       
    }
    catch (ErrorCodes e)
    {
        switch (e)
        {
        case ErrorCodes::InvalidName:
        {      
            NAMESTART:
            char r = ' ';         
            cout << "Invalid name, try again? y/n:";
            cin >> r;
            switch (CheckYN(r))
            {
            case 1:
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cInput("Name: ", nameBuffer, 100);
                goto TRY;
            }
            break;
            case -1:
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                goto NAMESTART;
            }
            break;
            default:
                break;
            }
        }
            break;
        case ErrorCodes::InvalidAge:    
        {
            AGESTART:
            char r = ' ';
            cout << "Invalid age, try again? y/n:";
            cin >> r;
            switch (CheckYN(r))
            {
            case 1:
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                iInput("Age: ", age);
                goto TRY;
            }
            break;
            case -1:
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                goto AGESTART;
            }
            break;
            default:
                break;
            }
        }
            break;
        case ErrorCodes::InvalidBirthday:
        {
            BIRTHSTART:
            char r = ' ';
            cout << "Invalid birthday, try again? y/n:";
            cin >> r;
            switch (CheckYN(r))
            {
            case 1:
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cInput("Birthday(dd/mm/yyyy): ", birthDayBuffer, 40);
                goto TRY;
            }
            break;
            case -1:
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                goto BIRTHSTART;
            }
            break;
            default:
                break;
            }
        }
        break;
        case ErrorCodes::InvalidInitial:
        {
            INITIALSTART:
            char r = ' ';
            cout << "Invalid initial, try again? y/n:";
            cin >> r;
            switch (CheckYN(r))
            {
            case 1:
            {        
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cInput("Initial: ", initialBuffer, 2);                
                goto TRY;
            }
            break;
            case -1:
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                goto INITIALSTART;
            }
            break;
            default:
                break;
            }
        }
            break;
        case ErrorCodes::InvalidPhoneNumber:
        {
        PHONESTART:
            char r = ' ';
            cout << "Invalid age, try again? y/n:";
            cin >> r;
            switch (CheckYN(r))
            {
            case 1:
            {
                wcin.clear();
                wcin.ignore(INT_MAX, '\n');
                ilInput("Phone: ", phoneNumberBuffer);
                goto TRY;
            }
            break;
            case -1:
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                goto PHONESTART;
            }
            break;
            default:
                break;
            }
        }
            break;
        default:
            break;
        }
    }

    system("CLS");
    if (person.GetName())
        cout << "Name: " << person.GetName() << endl;
    else 
        cout << "Name: " << "No input recorded" << endl;
    if (person.GetInitial())
        cout << "Initial: " << person.GetInitial() << endl;
    else
        cout << "Initial: " << "No input recorded" << endl;
    if (person.GetAge())
        cout << "Age: " << person.GetAge() << endl;
    else
        cout << "Age: " << "No input recorded" << endl;
    if (person.GetNumber())
        wcout << L"Phone: " << person.GetNumber() << endl;
    else
        cout << "Phone: " << "No input recorded" << endl;
    if (person.GetBirthDay())
        cout << "Date: " << person.GetBirthDay() << endl;
    else
        cout << "Date: " << "No input recorded" << endl;
    
    END:
    cout << "Is all the information correct? y/n: ";
    char res = ' ';
    cin >> res;
    switch (CheckYN(res))
    {
    case 1:
        cout << "Thank you for using my program, have a great day!" << endl;
        break;
    case 0:
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        goto INPUT;
        break;
    case -1:
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        goto END;
        break;
    default:
        break;
    }

}

