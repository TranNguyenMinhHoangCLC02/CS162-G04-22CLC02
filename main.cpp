#include "Staff.h"
#include "Student.h"
Year *year_head = nullptr;
int main()
{
    bool check;
    cout << "-----------------------------------------";
    cout << "\n---------WELCOME-TO-OUR-PROGRAM----------\n";
    int option = firstScreen(check);
    if (check == false)
        return 0;

    interface(option, year_head);
    return 0;
}