#include "../Header/Staff.h"

void accessSemester(string username, Year* &year_head, Semester* &semester_head)
{
    system("cls");
    cout << "\n";
    cout << "------------SEMESTER_"<< semester_head->Semester_Ord <<"--------------\n";
    cout << "0." << setw(2) << right << "Return back\n";
    cout << "1." << setw(2) << right << "Add a course\n";
    cout << "2." << setw(2) << right << "Access a course\n";
    cout << "3." << setw(2) << right << "Update a course\n";
    
    int option;
    do
    {
        cout << "Input option: ";
        cin >> option;
    } while (option < 0 || option > 3);

    if (option == 0)
    {   
        system("cls");
        viewSemester_Screen(username, year_head);
        return;
    }
    else if (option == 1)
    {
        system ("cls");
        semester_head->course_head = getCourseListFromFile(year_head, semester_head);
        addNewCourse(username, year_head, semester_head);
        return;
    }
    else if (option == 2)
    {
        system("cls");
        semester_head->course_head = getCourseListFromFile(year_head, semester_head);
        viewCourse_Screen(username, year_head, semester_head);
        return;
    }
    else if (option == 3)
    {
        system("cls");
        semester_head->course_head = getCourseListFromFile(year_head, semester_head);
        viewUpdateCourseInformation(username, year_head, semester_head);
        return;
    }
}