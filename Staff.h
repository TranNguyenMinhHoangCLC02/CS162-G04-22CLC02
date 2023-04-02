#ifndef Staff_h
#define Staff_h

#include "Structures.h"

bool checkSyntaxOfSchoolYear (string year_name);
bool checkExistingYear (Year* &year_head, string year_name);
void addNewSchoolYear (Year* &year_head);
Year* getYearListFromFile();
void staff_info(string username);
int accessSchoolYear(string username, Year* &year_head);

Semester* getSemesterListFromFile(Year* &year_head);
bool checkInvalidSemester (string input);
bool checkExistingSemester (Semester* &semester_head, string input);
int addNewSemester (string username, Year* &year_head);
int viewClass_Screen(string username, Year* &year_head);
Class* getClassListFromFile(Year *&year_head);
int addNewClass (Year* &year_head, string username);
void addTail(Student* &student_head, Student* tmp);
void getDate(Student* &tmp , string date_string);
Student* getStudentListFromFile(Year *year_head);
int addNewStudent(string username, Year *&year_head, Class *cur);
int accessClass(string username, Year* &year_head, Class *class_head);

int accessSemester(string username, Year* &year_head, Semester* &semester_head);
int accessCourse(string username, Year* &year_head, Semester* &semester_head, Course* &course_head);

int viewSemester_Screen(string username, Year* year_head);
int viewCourse_Screen(string username, Year* year_head, Semester* semester_head);

int viewStudentInClass(string username, Year* &year_head, Class *class_head);
int viewStudentInCourse(string username, Year* &year_head, Semester* &semester_head, Course* &course_head);
#endif