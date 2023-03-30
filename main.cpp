#include "Staff.h"
#include "Student.h"
Year *year_head = nullptr;
int main()
{
    //Design the introduction for project
    cout << "-----------------------------------------";
    cout << "\n---------WELCOME-TO-OUR-PROGRAM----------\n";

    bool check;
    int option = firstScreen(check);

    if (check == false) //Out the program
        return 0;

    interface(option, year_head); //Continue with 1 of 2 rest options

    return 0;
}