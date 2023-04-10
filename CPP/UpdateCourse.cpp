#include "../Header/Staff.h"

void viewUpdateCourseInformation (string username, Year* year_head, Semester* semester_head)
{
    system("cls");
    cout << setw(2) << "------------UPDATE-A-COURSE--------------\n";
    cout << "Please choose the course you have created you want to access for seeing information";
    
    Course* cur = year_head->semester_head->course_head; int numCourses = 0;

    //Show list of years the staff has created before
    if (cur == nullptr) //Data is empty
        cout << "\n" << "Oops, there is nothing for you to choose" << "\n";
    else
    {
        cout << "\n\n" << "Here are some semesters you created" << "\n";

        while (cur)
        {
            cout << numCourses + 1 << "\t" << setw(2) << right << cur->course_name << "-" << cur->course_ID << "_" << cur->class_name << "\n";
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
            system("cls");
            updateACourse(username, year_head, semester_head, cur);
            return;
        }
        else
        {
            system("cls");
            accessSemester(username, year_head, semester_head);
            return;
        }
    }

    string opt;
    cout << "Please type the number 0 for returning back: ";
    getline(cin, opt);

    while (opt != "0")
    {
        cout << "The number is different from 0, please input again: ";
        getline(cin, opt);
    }
    
    system("cls");
    accessSemester(username, year_head, semester_head);
}

void updateACourse (string username, Year* year_head, Semester* semester_head, Course* course_head)
{
    system("cls");
    cout << "\n";
    cout << "------------UPDATE_COURSE_" << course_head->class_name << "--------------\n";
    cout << "0." << setw(2) << right << "Return back\n";
    cout << "1." << setw(2) << right << "Upload student file\n";
    cout << "2." << setw(2) << right << "Add a student\n";
    cout << "3." << setw(2) << right << "Remove a student\n";
    cout << "4." << setw(2) << right << "Delete course\n";

    int option;
    do
    {
        cout << "Input option: ";
        cin >> option;
    } while (option < 0 || option > 4);

    if (option == 0)
    {   
        system("cls");
        accessSemester(username, year_head, semester_head);
        return;
    }
    else if (option == 1)
    {
        system ("cls");
        uploadStudentFileToCourse(username, year_head, semester_head, course_head);
        return;
    }
    else if (option == 2)
    {
        system("cls");
        viewCourse_Screen(username, year_head, semester_head);
        return;
    }
    else if (option == 3)
    {
        system("cls");
        
        return;
    }
}