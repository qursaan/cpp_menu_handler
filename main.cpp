#include <iostream>         // cin, cout
#include <cstdlib>          // cls
#include <windows.h>        // Sleep
#include <cstring>          // string, to_string
#include <bits/stdc++.h>    // stringstream
using namespace std;

inline void wait_or_clear(unsigned int sec, bool clear_screen = false)
{
    Sleep(sec*1000);
    if (clear_screen) system("cls");
}

inline void printline(string msg, bool end_line = true)
{
    cout << msg << (end_line?"\n":"\t");
}

int get_menu_choise(string menu, int level = 0)
{
    stringstream X(menu);
    string line;
    string padding;
    int i = 1;
    for(int p=0; p<level+1; ++p)
    {
        padding +="\t";
    }
    while (getline(X, line, ','))
    {
        printline(padding + to_string(i++) + ". " + line);
    }
    printline(level?padding+"0. Return Back":padding+"0. Exit App");
    int c;
    printline("Enter your choice:",false);
    cin >> c;
    return c;
}

void sub_sub_menu_1_1()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nSUB MENU 1....");
        c = get_menu_choise("add,edit",2);
        switch(c)
        {
        case 1:
            printline("Do it here 1");
            system("pause");
            break;
        case 2:
            printline("Do it here 2");
            system("pause");
        case 0:
            return;
        default:
            printline("Invalid Choice Try Again!!!!!!!!");
            wait_or_clear(3, 1);
        }
    }
}

void sub_menu_1()
{
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0, 1);
        printline("\n\nMENU 1....");
        c = get_menu_choise("add,edit,delete,search",1);
        switch(c)
        {
        case 1:
            sub_sub_menu_1_1();
            break;
        case 2:
            sub_sub_menu_1_1();
            break;
        case 3:
            sub_sub_menu_1_1();
            break;
        case 4:
            printline("Do it here 4");
            system("pause");
            break;
        case 0:
            return;
        default:
            printline("Invalid Choice Try Again!!!!!!!!");
            wait_or_clear(3, 1);
        }
    }
}

int main()
{

    printline("Start Application ....");
    wait_or_clear(1,1);
    int c = -1;
    while (c!=0)
    {
        wait_or_clear(0,1);
        printline("\n\nMAIN MENU ....");
        c = get_menu_choise("show all,add new,delete",0);
        switch(c)
        {
        case 1:
            sub_menu_1();
            break;
        case 2:
            sub_menu_1();
            break;
        case 3:
            printline("Do it here 4");
            system("pause");
            break;
        case 0:
            printline("\n\n\a\t\t\tGoodbye :) ......\n\n\n\n\n\n");
            break;
        default:
            printline("\n\n\n\aInvalid Choice Try Again!!!!!!!!");
            wait_or_clear(3, true);
        }
    }
    return 0;
}
