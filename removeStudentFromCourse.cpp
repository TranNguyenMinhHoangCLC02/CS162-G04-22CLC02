#include "Student.h"
#include "Structures.h"

void removeStudentFromCourse(Course* &course, Student* &student) 
{
    // Check if the course and student exist
    if (course == nullptr) 
    {
        cout << "Course does not exist." << endl;
        return;
    }
    if (student == nullptr) 
    {
        cout << "Student does not exist." << endl;
        return;
    }

    // Find the student in the course's list of students
    Student* currentStudent = course->student_head;
    Student* previousStudent = nullptr;
    while (currentStudent != nullptr) 
    {
        if (currentStudent == student) 
        {
            // Remove the student from the course's list of students
            if (previousStudent == nullptr) 
                course->student_head = currentStudent->student_next;
            else 
                previousStudent->student_next = currentStudent->student_next;
            // Remove the course from the student's list of courses
            Course* currentCourse = student->course_head;
            Course* previousCourse = nullptr;
            while (currentCourse != nullptr) 
            {
                if (currentCourse == course) 
                {
                    if (previousCourse == nullptr) 
                        student->course_head = currentCourse->course_next;
                    else 
                        previousCourse->course_next = currentCourse->course_next;
                    cout << "Student " << student->student_ID << " removed from course " << course->course_name << endl;
                    delete currentStudent;
                    delete currentCourse;
                    return;
                }
                previousCourse = currentCourse;
                currentCourse = currentCourse->course_next;
            }
            return;
        }
        previousStudent = currentStudent;
        currentStudent = currentStudent->student_next;
    }
    cout << "Student " << student->student_ID << " is not enrolled in course " << course->course_name << endl;
}


