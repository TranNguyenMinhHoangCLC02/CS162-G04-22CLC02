#include "Structures.h"

void convertTime_slot(Class *a)
{
    if (a->slot == "S1")
        cout << "7:30";
    else if (a->slot == "S2")
        cout << "9:30";
    else if (a->slot == "S3")
        cout << "13:30";
    else if (a->slot == "S4")
        cout << "15:30";
    else
        cout << "Invalid time slot";
}