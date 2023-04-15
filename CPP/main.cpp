#include "../Header/Staff.h"
#include "../Header/Student.h"

Year *year_head = nullptr;
int main()
{
    bool check;
    int option = firstScreen(check);

    if (check == false) //Out the program
        return 0;

    Myinterface(option, year_head); //Continue with 1 of 2 rest options

    return 0;
}