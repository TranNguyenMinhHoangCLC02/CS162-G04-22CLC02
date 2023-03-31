#include "Structures.h"

void convertTime_slot(Course *a)
{
    if (a->Session == "S1")
        cout << "7:30";
    else if (a->Session == "S2")
        cout << "9:30";
    else if (a->Session == "S3")
        cout << "13:30";
    else if (a->Session == "S4")
        cout << "15:30";
    else
        cout << "Invalid time slot";
}