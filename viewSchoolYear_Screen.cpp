#include "Staff.h"

int viewSchoolYear_Screen(string username, Year* year_head)
{
    cout << "Please choose the year you want to access: ";
    
    Year* cur = year_head; int numYears = 0;

    //Show list of years the staff has created before
    if (cur == nullptr) //Data is empty
        cout << "\n\n" << "Oops, there is nothing for you to choose";
    else
    {
        cout << "\n\n" << "Here are some years you created";

        while (cur)
        {
            cout << numYears + 1 << "." << setw(2) << right << cur->year_name << "\n";
            cur = cur->year_next;
            numYears++;
        }
    }
    cout << "\n";

    cout << "0. Return back" << "\n";

    if (cur)
    {
        //Allow users to input their option
        int option;
        do
        {
            cout << "Please input your option: ";
            cin >> option;
        } while (option < 1 && option > numYears);

        //Move the pointer cur to the pointer year_head again
        cur = year_head;

        //Move it to the Node including suitable year
        for (int i = 0; i < option - 1; ++i)
        {
            cur = cur->year_next;
        }

        //Show some more options
        accessSchoolYear(username, cur);
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

        return Main_Staff_Screen(username, year_head);
    }

    return 0;
}