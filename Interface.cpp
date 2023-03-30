#include "Staff.h"
#include "Student.h"
#include "Structures.h"

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

int Main_Staff_Screen(string &username, Year* &year_head)
{
    cout << "------------------STAFF------------------\n";
    int option; bool check;

    cout << "0." << setw(2) << right << "Log out\n";
    cout << "1." << setw(2) << right << "View profile\n";
    cout << "2." << setw(2) << right << "Add a new school year\n";
    cout << "3." << setw(2) << right << "Access a school year\n";
    cout << "4." << setw(2) << right << "Change password\n";
    
    do
    {
        cout << "Input option: ";
        cin >> option;
    } while (option != 0 && option != 1 && option != 2 && option != 3 && option != 4);

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
        year_head = getYearListFromFile();
        viewSchoolYear_Screen(username, year_head);
    }
    else if (option == 4)
    {
        system("cls");
        changePass(username, false);
        interface(1);
    }

    return 0;
}


int Main_Student_Screen(string username)
{
    cout << "------------------STUDENT---------------\n";
    int option; bool check;
    cout << "0." << setw(2) << right << "Log out\n";
    cout << "1." << setw(2) << right << "View profile\n";
    cout << "2." << setw(2) << right << "View courses\n";
    cout << "3." << setw(2) << right << "Change password\n";
    do
    {
        cout << "Input option: ";
        cin >> option;
    } while (option != 0 && option != 1 && option != 2 && option != 3);

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
    else if (option==3)
    {
        system("cls");
        changePass(username, true);
        interface(0);
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