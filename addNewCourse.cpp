#include "Staff.h"

//Check Validation of Course ID
//Normalize Course Name
//Normalize Teacher Name
//Check user's input for session

//Convert Session to Time
void convertTime_slot(Course *course_head)
{
    if (course_head->Session == "S1")
        course_head->Session =  "7:30";
    else if (course_head->Session == "S2")
        course_head->Session = "9:30";
    else if (course_head->Session == "S3")
        course_head->Session = "13:30";
    else if (course_head->Session == "S4")
        course_head->Session = "15:30";
}

