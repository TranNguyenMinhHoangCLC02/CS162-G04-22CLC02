#include "../Header/Staff.h"
#include "../Header/Student.h"

void viewStudentInCourse(string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{
    system("cls");
    cout << "------------"<< course_head->course_name <<"--------------\n";

    //Show list of students the staff has added before
    if (course_head->student_head == nullptr) //Data is empty
        cout << "\n" << "Oops, there is nothing for you to choose" << "\n";
    else
    {   
        Student* cur = course_head->student_head;
        cout << "\n\n" << "Here are some students you added" << "\n";
        int numStudents = 0;
        while (cur)
        {
            cout << numStudents + 1 << "." << setw(2) << right << cur->student_fisrtname << " " << cur->student_lastname << "\n";
            cur = cur->student_next;
            numStudents++;
        }
    }
    cout << "\n";
    cout << "0. Return back" << "\nInput option: ";
    int opt = 1;
    cin >> opt;

    while (opt != 0)
    {
        cout << "Please input again: ";
        cin >> opt;
    }
    system("cls");
    accessCourse(username, year_head, semester_head, course_head);
}