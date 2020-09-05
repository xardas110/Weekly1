//Will not use precompiled headers since it's a short program
#include "../Weekly1/ErrorCodes.h"
#include "../Weekly1/Helpers.h"
#include "../Weekly1/Person.h"
#include <iostream>
using namespace std;
constexpr char young[] = "You are young";
constexpr char grownUp[] = "You are a grown up";
constexpr char old[] = "You are old";
constexpr char rlyOld[] = "You ARE really old";
__declspec(align(4)) struct arrText
{
    arrText()
    {
       
        yPtr = young;
        gPtr = grownUp;
        oPtr = old;
        roPtr = rlyOld;
    }
    const char* yPtr;
    const char* gPtr;
    const char* oPtr;
    const char* roPtr;
};
int main()
{
    Person person;
    arrText arr;
    unsigned short age = (unsigned short)0;
    cout << &arr+4 << endl;
INPUT:
REDOAGE:
    if (!CheckAge(cin, age))
    {
        cin.clear();
        cin.ignore(LLONG_MAX, '\n');
        goto REDOAGE;
    }
TRY:
    try
    {
        person.SetAge(age);
    }
    catch (ErrorCodes e)
    {
        switch (e)
        {
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
                cin.ignore(LLONG_MAX, '\n');
                iInput("Age: ", age);
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
    if (person.GetAge())
        cout << "You are " << person.GetAge() << " years old\n\n";
    else
        cout << "You are " << "[No Input]" << " years old\n\n";
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

