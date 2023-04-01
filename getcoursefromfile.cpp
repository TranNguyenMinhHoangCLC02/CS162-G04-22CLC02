#include "Staff.h"

Course* getCourseListFromFile(Year* &year_head)
{
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
    string line;
    getline(ifs, line);

    while (getline(ifs, line))
    {
        Course* new_course = new Course;
        string tmp;
        stringstream ss(line);

        getline(ss, tmp, ',');
        new_course->course_ID = tmp;
        getline(ss, tmp, ',');
        new_course->course_name = tmp; 
        getline(ss, tmp, ','); 
        new_course->class_name = tmp;
        getline(ss, tmp, ',');
        new_course->teacher_name = tmp;
        getline(ss, tmp, ',');
        new_course->numCredits = stoi(tmp);
        getline(ss, tmp, ',');
        new_course->maxNumStudents = stoi(tmp);
        getline(ss, tmp, ',');
        new_course->dayInWeek = tmp;
        getline(ss, tmp, '\n');
        new_course->Session = tmp;
        
        new_course->student_head = nullptr;
        new_course->scoreboard_head = nullptr;
        new_course->course_next = nullptr;

        if (!year_head->semester_head->course_head)
        {
            year_head->semester_head->course_head = new_course;
            temp = year_head->semester_head->course_head;
        }
        else
        {
            temp->course_next = new_course;
            temp = temp->course_next;
        }
    }

    //Close file and return created list
    ifs.close();
    return year_head->semester_head->course_head;
}