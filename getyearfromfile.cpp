#include "Structures.h"

Year* getYearListFromFile()
{
    std::ifstream ifs;

    ifs.open("schoolyear.txt");
    if (!ifs.is_open())
    {
        cerr << "Error: Unable to open file for reading\n";
        return nullptr;
    }

    Year* year_head = nullptr; Year* temp = nullptr;
    string year_name;

    while (!ifs.eof())
    {
        getline(ifs, year_name, '\n');

        if (ifs.eof())
            break;

        Year* new_year = new Year;
        new_year->year_name = year_name;
        new_year->class_head = nullptr;
        new_year->semester_head = nullptr;
        new_year->year_next = nullptr;

        if (!year_head)
        {
            year_head = new_year;
            temp = year_head;
        }
        else
        {
            temp->year_next = new_year;
            temp = temp->year_next;
        }
    }

    ifs.close();
    return year_head;
}