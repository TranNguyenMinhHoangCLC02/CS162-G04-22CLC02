#ifndef Student_h
#define Student_h

#include "Structures.h"

void student_info(string username);
void viewScoreBoard_Student(string username);

int numOfStudent(Course* course);
void addStudentToCourse(Course* &course, Student* &student);

void printCourseInfo(Course* course);
void viewCoursesInSemester(Student* student, Semester* semester);

void deleteCourse(Course *&course_head, Course* course);

bool isLoggedIn();
void login(bool isStudent, string &username);

void removeStudentFromCourse(Course* &course, Student* &student) ;

#endif