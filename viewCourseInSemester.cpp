#include "Student.h"

void printCourseInfo(Course* course) 
{
    // Create an array containing the names of the columns
    string column_names[8] = {"Teacher Name", "Course ID", "Course Name", "Class Name", "Number of Credits", "Max Number of Students", "Day of Week", "Session"};
    
    // Create an array containing the corresponding values of the columns
    string column_values[8] = {course->teacher_name, course->course_ID, course->course_name, course->class_name, to_string(course->numCredits), to_string(course->maxNumStudents), course->dayInWeek, course->Session};
    
    // Calculate the length of the longest column to align it correctly with the other rows
    int max_column_length = 0;
    for (int i = 0; i < 8; i++) {
        if (column_names[i].length() > max_column_length) {
            max_column_length = column_names[i].length();
        }
    }
    
    // Print out the table
    cout << "+";
    for (int i = 0; i < max_column_length + 2; i++) {
        cout << "-";
    }
    cout << "+";
    for (int i = 0; i < 25; i++) {
        cout << "-";
    }
    cout << "+" << endl;
    for (int i = 0; i < 8; i++) {
        cout << "| " << setw(max_column_length) << left << column_names[i] << " | " << setw(25) << left << column_values[i] << " |" << endl;
        cout << "+";
        for (int i = 0; i < max_column_length + 2; i++) {
            cout << "-";
        }
        cout << "+";
        for (int i = 0; i < 25; i++) {
            cout << "-";
        }
        cout << "+" << endl;
    }
}

void viewCoursesInSemester(Student* student, Semester* semester) 
{
    // Browse through the list of courses for the semester
    Course* course = semester->course_head;
    while (course != nullptr) 
    {
        // Browse through the list of students for the course
        Student* courseStudent = course->student_head;
        while (courseStudent != nullptr) 
        {
            // Search for a student in the list of students for the course
            if (courseStudent->student_ID == student->student_ID) 
            {
                // Print out information about the course
                printCourseInfo(course);
                break;
            }
            courseStudent = courseStudent->student_next;
        }
        course = course->course_next;
    }
}