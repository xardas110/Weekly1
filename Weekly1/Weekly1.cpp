#include "Person.h"
#include "ErrorCodes.h"
#include <iostream>
using namespace std;
using BYTE = unsigned __int8;
//Helper functions
int CheckYN(char r)
{
    if (r == 'y')
        return 1;
    else if (r == 'n')
        return 0;
    else
        return -1;
}
void cInput(const char* text, char* buffer, const size_t size)
{
    cout << text;
    cin.getline(buffer, size);
}

template<class I>
void iInput(const char* text, I &val)
{
    cout << text;
    cin >> val;
}
template<class I>
void ilInput(const char* text, I& val)
{
    cout << text;
    wcin >> val;
}
//**Cin as first parameter just to be sure that it doesn't do the check at the wrong time **//
bool CheckAge(istream& cin, unsigned short& age)
{
    iInput("Age: ", age);
    if (!cin)
    { 
        cout << "Invalid age" << endl;
        return false;
    }
    return true;
}
//**Wcin as first parameter just to be sure that it doesn't do the check at the wrong time **//
bool CheckPhone(wistream& wcin, unsigned long long& phone)
{
    ilInput("Phone: ", phone);
    if (!wcin)
    {
        cout << "Invalid phonenumber" << endl;    
        return false;
    }
    return true;
}
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

