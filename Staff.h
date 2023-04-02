#ifndef Staff_h
#define Staff_h

#include "Structures.h"

bool checkSyntaxOfSchoolYear (string year_name);
bool checkExistingYear (Year* &year_head, string year_name);
void addNewSchoolYear (Year* &year_head);
Year* getYearListFromFile();
void staff_info(string username);
void accessSchoolYear(string username, Year* &year_head);

Semester* getSemesterListFromFile(Year* &year_head);
bool checkInvalidSemester (string input);
bool checkExistingSemester (Semester* &semester_head, string input);
void addNewSemester (string username, Year* &year_head);
void viewClass_Screen(string username, Year* &year_head);
Class* getClassListFromFile(Year *&year_head);
void addNewClass (Year* &year_head, string username);
void addTail(Student* &student_head, Student* tmp);
void getDate(Student* &tmp , string date_string);
Student* getStudentListFromFile(Year *year_head);
void addNewStudent(string username, Year *&year_head, Class *cur);
void accessClass(string username, Year* &year_head, Class *class_head);

void convertTime_slot(Course *course_head);

void accessSemester(string username, Year* &year_head, Semester* &semester_head);
void accessCourse(string username, Year* &year_head, Semester* &semester_head, Course* &course_head);

void viewSemester_Screen(string username, Year* year_head);
void viewCourse_Screen(string username, Year* year_head, Semester* semester_head);

#endif