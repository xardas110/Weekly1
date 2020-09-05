//Will not use precompiled headers since it's a short program
#include "../Weekly1/ErrorCodes.h"
#include "../Weekly1/Helpers.h"
#include "../Weekly1/Person.h"
#include <iostream>
#include <type_traits>
using namespace std;
using DWORD = unsigned long;

struct arrText
{
    //Short program so I use static variables here, instead of decaring a new array then delete it in the destructor
    static constexpr char young[] = "You are young";
    static constexpr char grownUp[] = "You are a grown up";
    static constexpr char old[] = "You are old";
    static constexpr char rlyOld[] = "You ARE really old";
    __declspec(align(4)) struct ptr {
       constexpr ptr()
            :y(young), g(grownUp), o(old), ro(rlyOld){
           //Program won't compile if this data is not 4byte aligned, there are better methods
           if (alignment_of<ptr>::value != 4)
               cout << "Data not aligned\n";
       }
        const char* y;
        const char* g;
        const char* o;
        const char* ro;
    }ptrs;
    constexpr arrText(){ }
    ~arrText()
    {
        //If new is used
        /*
        delete[] young;
        delete[] grownUp;
        delete[] old;
        delete[] rlyOld;
        */
    }

};

int main()
{
    Person person;
    arrText arr;
    unsigned short age = (unsigned short)0;

    //I chose this approach because it has better runtime performance, but uses 150 more bytes of stack mem and personally I think it's easier to read over a nest of if else statements
    const DWORD baseA = (DWORD)&arr.ptrs.y;
    constexpr BYTE offset0 = (BYTE)0;
    constexpr BYTE offset1 = (BYTE)4;
    constexpr BYTE offset2 = (BYTE)8;
    constexpr BYTE offset3 = (BYTE)12;
    BYTE ageArr[AGELIMIT]{};
    for (int i = 0; i < 20; i++)
        ageArr[i] = offset0;
    for (int i = 20; i <= 40; i++)
        ageArr[i] = offset1;
    for (int i = 41; i < 60; i++)
        ageArr[i] = offset2;
    for (int i = 60; i < AGELIMIT; i++)
        ageArr[i] = offset3;

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
                //iInput("Age: ", age);
                goto REDOAGE;
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
    if (person.GetAge() >= 0) //To allow 0 as age    
        cout << (const char*)*(DWORD*)(baseA + (DWORD)ageArr[age]) << endl;
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

