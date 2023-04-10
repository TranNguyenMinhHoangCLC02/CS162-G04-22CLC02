#ifndef Student_h
#define Student_h

#include "Structures.h"

void student_info(string username);
void viewScoreBoard_Student(string username);

void addTail(Student* &student_head, Student* tmp);
void getDate(Student* &tmp , string date_string);
Class* upload_info_class(ifstream &file);

int numOfStudent(Course* course);
void addStudentToCourse(Course* &course, Student* &student);

void printCourseInfo(Course* course);
void viewCoursesInSemester(Student* student, Semester* semester);

bool isLoggedIn();
void login(bool isStudent, string &username);

#endif