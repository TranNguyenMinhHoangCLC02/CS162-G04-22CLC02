#include "../Header/Student.h"

int numOfStudent(Course* course)
{
    int count = 0;
    Student* currrent = course->student_head;
    while (currrent != NULL)
    {
        count ++;
        currrent = currrent->student_next;
    }
    return count;
}

void addStudentToCourse(Course* &course, Student* &student) 
{
    // Check if the Course has reached maxNumStudents or not
    if (numOfStudent(course) == course->maxNumStudents)
    {
        cout << "This course has reached its maximum limit of students.";
        return;
    }
    else if (numOfStudent(course) < course->maxNumStudents)
    {
        // Add the course to the student's list of courses
        student->course_head = course;

        // Add the student to the course's list of students
        if (course->student_head == NULL)
            course->student_head = student;
        else 
        {
            Student* current = course->student_head;
            while (current->student_next != NULL) 
                current = current->student_next;
            current->student_next = student;
        }
    }
}