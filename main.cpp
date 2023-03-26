#include "Staff.h"
#include "Student.h"
#include "Interface.cpp"

int main()
{
    bool check;
    int option=firstScreen(check);
    if (check==false)
        return 0;
    interface(option);
    return 0;
}