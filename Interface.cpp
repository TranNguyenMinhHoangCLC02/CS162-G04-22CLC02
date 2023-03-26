#include "Staff.h"
#include "Student.h"

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
        cout << "Input option: ";
        cin >> option;
    } while (option != 0 && option != 1 && option != 2);

    if (option == 0)
        check = false;
    else
    {
        check = true;
        return option;
    }
    return 0;
}

int Main_Staff_Screen(string username)
{
    int option; bool check;

    cout << "0." << setw(2) << right << "Log out\n";
    cout << "1." << setw(2) << right << "View profile\n";
    cout << "2." << setw(2) << right << "Add a new school year\n";
    cout << "3." << setw(2) << right << "Access a school year\n";

    cout << "Input option: ";
    cin >> option;

    if (option == 0)
        return firstScreen(check);
    if (option == 1)
    {
        system("cls");
        staff_info(username);
    }
    else if (option == 2)
    {
        system("cls");
        Year *year_head = getYearListFromFile();
        addNewSchoolYear(year_head);
    }

    return 0;
}


void Main_Student_Screen(string username)
{
    int option; bool check;
    cout << "0." << setw(2) << right << "Log out\n";
    cout << "1." << setw(2) << right << "View profile\n";
    cout << "2." << setw(2) << right << "View courses\n";
}

void interface(int option)
{
    system("cls");
    string username;
    if (option == 1)
    {
        login(option, username);
        system("cls");
        Main_Staff_Screen(username);
    }
    else
    {
        login(option, username);
        system("cls");
        Main_Student_Screen(username);
    }
}