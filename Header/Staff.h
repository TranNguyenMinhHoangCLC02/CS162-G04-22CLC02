#ifndef Staff_h
#define Staff_h

#include "Structures.h"

//View info function
void staff_info(string username, Year* &year_head);

//Year functions
bool checkSyntaxOfSchoolYear (string year_name);
bool checkExistingYear (Year* &year_head, string year_name);
void addNewSchoolYear (Year* &year_head);
Year* getYearListFromFile();
void accessSchoolYear(string username, Year* &year_head);

//Semester functions
Semester* getSemesterListFromFile(Year* &year_head);
bool checkExistingSemester (Semester* &semester_head, int semester_ord);
void addNewSemester (string username, Year* &year_head);
bool checkInvalidDayOfDate (int year, int month, int day);
bool checkStartDateAndEndDate (int startyear, int startmonth, int startday, int endyear, int endmonth, int endday);

//Class functions
int CLASS_Interface(string &username, Year* &year_head, Class *class_head);
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
int COURSE_Interface(string username, Year* &year_head, Semester* &semester_head, Course* &course_head);
Course* getCourseListFromFile(Year* year_head, Semester* &semester_head);
void accessCourse(string username, Year* &year_head, Semester* &semester_head, Course* &course_head);
void viewCourse_Screen(string username, Year* year_head, Semester* semester_head);
void updateInformationOfCourse (string username, Year* year_head, Semester* semester_head, Course* accessed_course);
void viewUpdateCourseInformation (string username, Year* year_head, Semester* semester_head);
void deleteCourse(Course *&course_head, Course* course);
void printStudentList(Student* student_head);
Student* findStudentByID(string studentID, Student* head);
void deleteStudent(Student *&student_head, string studentID);
Student* getListStuFromFile(string filename);
void removeStudent(string filename, string studentID);
void removeStudentFromCourse(string username, Course* &course, Year* &year_head, Semester* semester_head) ;
void addNewCourse (string username, Year* year_head, Semester* semester_head);
void viewStudentInCourse(string username, Year* &year_head, Semester* &semester_head, Course* &course_head);
int numOfStudent(Course* course);
bool isStudentInCourse(Course* course, Student* student);
Student* findStudentInClass(Class* class_head, string studentID);
void addStudentToCourse(string username, Course* &course, Year* &year_head, Semester* semester_head);
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