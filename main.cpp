#include "Staff.h"
#include "Student.h"

int main()
{
    bool check;

    int option = firstScreen(check);
    if (check == false)
        return 0;

    interface(option);
    return 0;
}