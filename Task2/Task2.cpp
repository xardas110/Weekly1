//Will not use precompiled headers since it's a short program
#include "../Weekly1/ErrorCodes.h"
#include "../Weekly1/Helpers.h"
#include "../Weekly1/Person.h"
#include <iostream>
using namespace std;
int main()
{
    Person person;
    char nameBuffer[100]{};
    unsigned short age = (unsigned short)0;
    char yn = ' ';
    char coffeeBuff[40] = "[No Input]";
INPUT:
    cInput("Name(Firstname Lastname): ", nameBuffer, 100);
REDOAGE:
    if (!CheckAge(cin, age))
    {
        cin.clear();
        cin.ignore(LLONG_MAX, '\n');
        goto REDOAGE;
    }
REDOCOFFEE:
    iInput("Do you drink coffee? y/n: ", yn);
    cin.clear();
    cin.ignore(LLONG_MAX, '\n');
    if (yn == 'y')
        strcpy_s(coffeeBuff, "Seems you like coffee");
    else if (yn == 'n')
        strcpy_s(coffeeBuff, "Oh you don't like coffee");
    else
        goto REDOCOFFEE;
TRY:
    try
    {
        person.SetName(nameBuffer);
        person.SetAge(age);
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
                cin.ignore(LLONG_MAX, '\n');
                cInput("Name: ", nameBuffer, 100);
                goto TRY;
            }
            break;
            case -1:
            {
                cin.clear();
                cin.ignore(LLONG_MAX, '\n');
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
                if (!CheckAge(cin, age))
                {
                    cin.clear();
                    cin.ignore(LLONG_MAX, '\n');
                    goto AGESTART;
                }
                goto TRY;
            }
            break;
            case -1:
            {
                cin.clear();
                cin.ignore(LLONG_MAX, '\n');
                goto AGESTART;
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
    cout << "----------------------------------" << endl;
    if (person.GetName())
        cout << "Your name is: " << person.GetName() << "\n\n";
    else
        cout << "Your name is: " << "[No input]\n\n";
    if (person.GetAge())
        cout << "You are " << person.GetAge() << " years old\n\n";
    else
        cout << "You are " << "[No Input]" << " years old\n\n";
    cout << coffeeBuff << endl;
    cout << "----------------------------------" << endl;


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

