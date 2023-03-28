#include "Staff.h"
#include "Student.h"

int main()
{
    bool check;
    cout << "-----------------------------------------";
    cout << "\n---------WELCOME-TO-OUR-PROGRAM----------\n";
    int option = firstScreen(check);
    if (check == false)
        return 0;

    interface(option);
    return 0;
}