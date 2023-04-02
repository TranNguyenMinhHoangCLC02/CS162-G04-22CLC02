#include "Staff.h"

int viewSemester_Screen(string username, Year* year_head)
{
    system("cls");
    cout << setw(2) << "------------ACCESS-A-SEMESTER--------------\n";
    cout << "Please choose the semester you have created you want to access";
    
    Semester* cur = year_head->semester_head; int numSemesters = 0;

    //Show list of years the staff has created before
    if (cur == nullptr) //Data is empty
        cout << "\n" << "Oops, there is nothing for you to choose" << "\n";
    else
    {
        cout << "\n\n" << "Here are some semesters you created" << "\n";

        while (cur)
        {
            cout << numSemesters + 1 << "." << setw(2) << right << "Semester " << cur->Semester_Ord << "\n";
            cur = cur->semester_next;
            numSemesters++;
        }
    }
    cout << "\n";

    //If users don't want to manipulate with this page, they can return back
    cout << "0. Return back" << "\n";

    //Move the pointer cur to the pointer semester_head again
    cur = year_head->semester_head;

    if (cur)
    {
        //Allow users to input their option
        int option;
        do
        {
            cout << "Please input your option: ";
            cin >> option;
        } while (option < 0 || option > numSemesters);

        if (option)
        {
            //Move it to the Node including suitable year
            for (int i = 0; i < option - 1; ++i)
            {
                cur = cur->semester_next;
            }

            //Show some more options
            accessSemester(username, year_head, cur);
        }
        else
        {
            system("cls");
            return accessSchoolYear(username, year_head);
        }
    }
    else
    {
        int opt;
        cout << "Please input 0 for returning back to the previous screen: ";
        cin >> opt;

        while (opt != 0)
        {
            cout << "Please input again: ";
            cin >> opt;
        }
    }
    system("cls");
    return accessSchoolYear(username, year_head);
}