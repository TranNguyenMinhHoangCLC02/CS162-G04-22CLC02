#include "Staff.h"

Course* getCourseListFromFile(Year* &year_head)
{
    /*
    ifstream ifs;

    //Open file
    string file_name = year_head->year_name + "_semester.txt";
    ifs.open(file_name);
    if (!ifs.is_open())
    {
        cerr << "Error: Unable to open file for reading\n";
        return nullptr;
    }

    //Get semester list from file
    Semester* temp = nullptr;
    int ordinal_term;

    while (!ifs.eof())
    {
        ifs >> ordinal_term;

        if (ifs.eof())
            break;

        Semester* new_semester = new Semester;

        new_semester->Semester_Ord = ordinal_term;
        new_semester->course_head = nullptr;
        new_semester->semester_next = nullptr;

        if (!year_head->semester_head)
        {
            year_head->semester_head = new_semester;
            temp = year_head->semester_head;
        }
        else
        {
            temp->semester_next = new_semester;
            temp = temp->semester_next;
        }
    }

    //Close file and return created list
    ifs.close();
    return year_head->semester_head;
    */

    ifstream ifs;

    //Open file
    string file_name = year_head->year_name + "_semester" + (char)(year_head->semester_head->Semester_Ord + 48) + "_course.csv";
    ifs.open(file_name);
    if (!ifs.is_open())
    {
        cerr << "Error: Unable to open file for reading\n";
        return nullptr;
    }

    //Get course list from file
    Course* temp = nullptr;
    int ordinal_term;

    while (!ifs.eof())
    {
        ifs >> ordinal_term;

        if (ifs.eof())
            break;

        Semester* new_semester = new Semester;

        new_semester->Semester_Ord = ordinal_term;
        new_semester->course_head = nullptr;
        new_semester->semester_next = nullptr;

        if (!year_head->semester_head)
        {
            year_head->semester_head = new_semester;
            temp = year_head->semester_head;
        }
        else
        {
            temp->semester_next = new_semester;
            temp = temp->semester_next;
        }
    }

    //Close file and return created list
    ifs.close();
}