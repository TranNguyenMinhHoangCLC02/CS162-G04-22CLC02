#include "Staff.h"

void accessSchoolYear(string username, Year* &year_head)
{
    system("cls");
    cout << "\n";
    cout << "------------"<< year_head->year_name <<"--------------\n";
    cout << "0." << setw(2) << right << "Return back\n";
    cout << "1." << setw(2) << right << "Add a semester\n";
    cout << "2." << setw(2) << right << "Access a semester\n";
    cout << "3." << setw(2) << right << "Add a class\n";
    cout << "4." << setw(2) << right << "Access a class\n";

    int option;
    do
    {
        cout << "Input option: ";
        cin >> option;
    } while (option < 0 || option > 4);

    if (option == 0)
    {
        system("cls");
        viewSchoolYear_Screen(username, getYearListFromFile());
        return;
    }

    if (option == 1)
    {
        system("cls");
        year_head->semester_head = getSemesterListFromFile(year_head);
        addNewSemester(username, year_head);
        return;
    }

    if (option == 2)
    {
        system("cls");
        viewSemester_Screen(username, year_head);
        return;
    }

    if (option == 3)
    {
        system("cls");
        string filename;
        filename = "class.txt";       
        year_head->class_head = getClassListFromFile(year_head, filename);
        addNewClass(year_head, username);
        return;
    }
    
    system("cls");
    viewClass_Screen(username, year_head);
}