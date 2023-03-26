#include "Structures.h"

/*
bool check;
int option=firstScreen(check);
if (check==false)
    return 0;
if (option==1)
    interface_Staff();
else
    interface_Student();
*/


int firstScreen(bool &check)
{
    cout << "0." << setw(2) << right << "Out program\n\n";
    cout << "Are you a student or staff?\n";
    cout << "1." << setw(2) << right << "Staff\n";
    cout << "2." << setw(2) << right << "Student\n";
    int option;
    do
    {
        cin >> option;
    } while (option != 0 && option != 1 && option != 2);
    if (option == 0)
        check = false;
    else
    {
        check = true;
        return option;
    }
}

void interface(int option)
{
    system("cls");
    if (option == 1)
    {
        login(option);
        Main_Staff_Screen();
    }
    else
    {
        login(option);
        Main_Student_Screen();
    }

}

int Main_Staff_Screen()
{
    int option; bool check;
    cout << "0." << setw(2) << right << "Log out\n";
    cout << "1." << setw(2) << right << "View profile\n";
    if (option==0)
        return firstScreen(check);
    

}

int Sub_Staff_Screen()
{
    cout << "1." << setw(2) << right << "Return back\n";
}

void Main_Student_Screen()
{

}
