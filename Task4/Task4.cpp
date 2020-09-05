//Will not use precompiled headers since it's a short program
#include "../Weekly1/Helpers.h"
#include <iostream>
using namespace std;

int main()
{
    unsigned short option = 0;
    constexpr unsigned short maxOptions = 3;
    char textBuff[40] = "[No Input]";

INPUT:
    iInput("What is your favorite drink?\n 1. Coffee\n 2. Tea\n 3. Coca Cola\n Select between 1 to 3: ", option);
    if (option > maxOptions or !cin or option == 0)
    {
        OPTERR:
        char r = ' ';
        cout << "Invalid input, try again? y/n:";
        cin >> r;
        switch (CheckYN(r))
        {
        case 1:
        {
            system("CLS");
            cin.clear();
            cin.ignore(LLONG_MAX, '\n');
            goto INPUT;
        }
        break;
        case -1:
        {
            cin.clear();
            cin.ignore(LLONG_MAX, '\n');
            goto OPTERR;
        }
        break;
        default:
            break;
        }
    } 
    system("CLS");
    switch (option)
    {
    case 1:
        strcpy_s(textBuff, "Coffee is delicious");
        break;
    case 2:
        strcpy_s(textBuff, "Tea gives peace of mind");
        break;
    case 3:
        strcpy_s(textBuff, "Coke will give you a white smile");
        break;
    default:
        break;
    }
    cout << "----------------------------------" << endl;
    cout << textBuff << endl;
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
        system("CLS");
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

