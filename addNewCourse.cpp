#include "Staff.h"

//Check Validation of Course ID
//Normalize Course Name
//Normalize Teacher Name

//Convert Session to Time
void convertTime_slot(Course *course_head)
{
    if (course_head->Session == "S1")
        cout << "7:30";
    else if (course_head->Session == "S2")
        cout << "9:30";
    else if (course_head->Session == "S3")
        cout << "13:30";
    else if (course_head->Session == "S4")
        cout << "15:30";
    else
        cout << "Invalid time slot";
}