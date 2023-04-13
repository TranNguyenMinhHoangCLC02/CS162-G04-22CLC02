#ifndef Staff_h
#define Staff_h

#include "Structures.h"

//View info function
void staff_info(string username);

//Year functions
bool checkSyntaxOfSchoolYear (string year_name);
bool checkExistingYear (Year* &year_head, string year_name);
void addNewSchoolYear (Year* &year_head);
Year* getYearListFromFile();
void accessSchoolYear(string username, Year* &year_head);

//Semester functions
Semester* getSemesterListFromFile(Year* &year_head);
bool checkInvalidSemester (string input);
bool checkExistingSemester (Semester* &semester_head, string input);
void addNewSemester (string username, Year* &year_head);

//Class functions
void viewClass_Screen(string username, Year* &year_head);
Class* getClassListFromFile(Year *&year_head, string filename);
void addNewClass (Year* &year_head, string username);
void accessClass(string username, Year* &year_head, Class *class_head);
void viewStudentInClass(string username, Year* &year_head, Class *class_head);
Class* upload_info_class(ifstream &file);

//Student functions
Student* getStudentListFromFile(Year *year_head, Class* class_head);
void addNewStudent(string username, Year *&year_head, Class *cur);

//Semester functions
void accessSemester(string username, Year* &year_head, Semester* &semester_head);
void viewSemester_Screen(string username, Year* year_head);
void viewCoursesInSemester(Student* student, Semester* semester);

//Course functions
Course* getCourseListFromFile(Year* year_head, Semester* &semester_head);
void accessCourse(string username, Year* &year_head, Semester* &semester_head, Course* &course_head);
void viewCourse_Screen(string username, Year* year_head, Semester* semester_head);
void updateInformationOfCourse (string username, Year* year_head, Semester* semester_head, Course* accessed_course);
void viewUpdateCourseInformation (string username, Year* year_head, Semester* semester_head);
void deleteCourse(Course *&course_head, Course* course);
void removeStudentFromCourse(Course* &course, Student* &student);
void addNewCourse (string username, Year* year_head, Semester* semester_head);
void viewStudentInCourse(string username, Year* &year_head, Semester* &semester_head, Course* &course_head);
int numOfStudent(Course* course);
bool isStudentInCourse(Course* course, Student* student);
Student* createStudent();
void addStudentToCourse(Course* &course);
void printCourseInfo(Course* course);

//Helper functions for course
bool checkCourseID (string Course_ID);
string Normalization (string input);
bool checkClassName (string Class_Name);
bool checkTeacherName (string Teacher_Name);
void showDayOptions();
void showSessionOptions();

//Update course functions
void updateACourse (string username, Year* year_head, Semester* semester_head, Course* course_head);
void updateCourseID (string username, Year* year_head, Semester* semester_head, Course* accessed_course);
void updateCourseName (string username, Year* year_head, Semester* semester_head, Course* accessed_course);
void updateClassName(string username, Year* year_head, Semester* semester_head, Course* accessed_course);
void updateTeacherName (string username, Year* year_head, Semester* semester_head, Course* accessed_course);
void updateNumCredits (string username, Year* year_head, Semester* semester_head, Course* accessed_course);
void updateMaxStudents (string username, Year* year_head, Semester* semester_head, Course* accessed_course);
void updateDayOfCourse (string username, Year* year_head, Semester* semester_head, Course* accessed_course);
void updateSession (string username, Year* year_head, Semester* semester_head, Course* accessed_course);
void uploadStudentFileToCourse (string username, Year* year_head, Semester* semester_head, Course* course_head);

//Scoreboard functions
void export_scoreboard(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head);
void viewScoreBoard_Course(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head);
void updateStudentsScore(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head);
void viewScoreBoard_Class(string username, Year *&year_head, Class *class_head);
void update_scoreBoard(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head);

#endif