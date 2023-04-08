#include "Staff.h"

void accessSemester(string username, Year* &year_head, Semester* &semester_head)
{
    system("cls");
    cout << "\n";
    cout << "------------SEMESTER_"<< semester_head->Semester_Ord <<"--------------\n";
    cout << "0." << setw(2) << right << "Return back\n";
    cout << "1." << setw(2) << right << "Add a course\n";
    cout << "2." << setw(2) << right << "Access a course\n";
    int option;
    do
    {
        cout << "Input option: ";
        cin >> option;
    } while (option < 0 || option > 2);

    if (option == 0)
    {   
        system("cls");
        accessSchoolYear(username, year_head);
        return;
    }
    else if(option == 1)
    {
        system ("cls");
        addNewCourse(username, year_head, semester_head);
        return;
    }
    else if(option == 2)
    {
        system("cls");
        viewCourse_Screen(username, year_head, semester_head);
        return;
    }
}