#include "Staff.h"

void accessCourse(string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{
    system("cls");
    cout << "\n";
    cout << "------------"<< course_head->course_name <<"--------------\n";
    cout << "0." << setw(2) << right << "Return back\n";
    cout << "1." << setw(2) << right << "View all students in this course\n";
    int option;
    do
    {
        cout << "Input option: ";
        cin >> option;
    } while (option < 0 || option > 1);

    if (option == 0)
    {
        system("cls");
        return accessSemester(username, year_head, semester_head);
    }
    else if(option == 1)
    {
        system ("cls");
        return viewStudentInCourse(username, year_head, semester_head, course_head);
    }
    return ;
}