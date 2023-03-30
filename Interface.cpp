#include "Staff.h"
#include "Student.h"
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
    cout << "\n\n0." << setw(2) << right << "Out program\n\n";

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

int Main_Staff_Screen(string &username, Year *&year_head)
{
    int option; bool check;
    cout << "0." << setw(2) << right << "Log out\n";
    cout << "1." << setw(2) << right << "View profile\n";
    cout << "2." << setw(2) << right << "Add a new school year\n";
    cout << "3." << setw(2) << right << "Access a school year\n";

    do
    {
        cout << "Input option: ";
        cin >> option;
    } while (option != 0 && option != 1 && option != 2 && option != 3);

    if (option == 0)
    {
        system("cls");
        return main();
    }
    if (option == 1)
    {
        system("cls");
        staff_info(username);
        system("cls");
        return Main_Staff_Screen(username, year_head);
    }
    else if (option == 2)
    {
        system("cls");
        year_head = getYearListFromFile();
        addNewSchoolYear(year_head);
        system("cls");
        return Main_Staff_Screen(username, year_head);
    }
    else if (option == 3)
    {
        system("cls");
        viewSchoolYear_Screen(username, year_head);
    }

    return 0;
}


int Main_Student_Screen(string username)
{
    int option; bool check;
    cout << "0." << setw(2) << right << "Log out\n";
    cout << "1." << setw(2) << right << "View profile\n";
    cout << "2." << setw(2) << right << "View courses\n";
    
    do
    {
        cout << "Input option: ";
        cin >> option;
    } while (option != 0 && option != 1 && option != 2);

    if (option == 0){
        system("cls");
        return main();
    }
    else if(option == 1)
    {
        system("cls");
        student_info(username);
        system("cls");
        return Main_Student_Screen(username);
    }
    else if (option == 2)
    {

    }

    return 0;
}

void interface(int option, Year* &year_head)
{
    system("cls");
    string username;
    if (option == 1)
    {
        login(option - 1, username);
        system("cls");
        Main_Staff_Screen(username, year_head);
    }
    else
    {
        login(option - 1, username);
        system("cls");
        Main_Student_Screen(username);
    }
}