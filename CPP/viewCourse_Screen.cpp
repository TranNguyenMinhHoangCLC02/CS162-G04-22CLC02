#include "../Header/Staff.h"

void viewCourse_Screen(string username, Year* year_head, Semester* semester_head)
{
    system("cls");
    cout << setw(2) << "------------ACCESS-A-COURSE--------------\n";
    cout << "Please choose the course you have created you want to access";
    
    Course* cur = year_head->semester_head->course_head; int numCourses = 0;

    //Show list of years the staff has created before
    if (cur == nullptr) //Data is empty
        cout << "\n" << "Oops, there is nothing for you to choose" << "\n";
    else
    {
        cout << "\n\n" << "Here are some semesters you created" << "\n";

        while (cur)
        {
            cout << numCourses + 1 << "." << setw(2) << right << cur->course_name << "-" << cur->course_ID << "_" << cur->class_name << "\n";
            cur = cur->course_next;
            numCourses++;
        }
    }
    cout << "\n";

    //If users don't want to manipulate with this page, they can return back
    cout << "0. Return back" << "\n";

    //Move the pointer cur to the pointer semester_head again
    cur = year_head->semester_head->course_head;

    if (cur)
    {
        //Allow users to input their option
        int option;
        do
        {
            cout << "Please input your option: ";
            cin >> option;
        } while (option < 0 || option > numCourses);

        if (option)
        {
            //Move it to the Node including suitable year
            for (int i = 0; i < option - 1; ++i)
            {
                cur = cur->course_next;
            }

            //Show some more options
            accessCourse(username, year_head, semester_head, cur);
            return;
        }
        else
        {
            system("cls");
            accessSemester(username, year_head, semester_head);
            return;
        }
    }

    int opt;
    cout << "Please input 0 for returning back to the previous screen: ";
    cin >> opt;

    while (opt != 0)
    {
        cout << "Please input again: ";
        cin >> opt;
    }
    
    system("cls");
    accessSemester(username, year_head, semester_head);
}