#include "Student.h"
#include "Structures.h"

void viewCoursesInSemester(Student* student, Semester* semester) {
    // Browse through the list of courses for the semester
    Course* course = semester->course_head;
    while (course != nullptr) {
        // Browse through the list of students for the course
        Student* courseStudent = course->student_head;
        while (courseStudent != nullptr) {
            // Search for a student in the list of students for the course
            if (courseStudent->student_ID == student->student_ID) {
                // Print out information about the course
                cout << "Course ID: " << course->course_ID << endl;
                cout << "Course name: " << course->course_name << endl;
                cout << "Teacher: " << course->teacher_name << endl;
                cout << "Day in week: " << course->dayInWeek << endl;
                cout << "Session: " << course->Session << endl;
                break;
            }
            courseStudent = courseStudent->student_next;
        }
        course = course->course_next;
    }
}