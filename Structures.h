#ifndef Structures_h
#define Structures_h

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

struct Scoreboard;
struct Course;
struct Student;
struct Class;
struct Semester;
struct Year;
struct Date;

struct Date
{
    unsigned int day, month, year;
};

struct Class
{
    string class_name;
    string class_id;
    Student *student_head; // Points to the Student
    Class *next_class; // Next class
    string slot;
};

struct Student
{   
    unsigned int student_No;
    string student_ID;
    string student_socialID;
    string student_fisrtname;
    string student_lastname;
    Class student_class;
    bool gender; //0: Male, 1: Female
    Date DOB; // Date of Birth
    Course *course_head; // Points to the Course
    Student *student_next; // Next student
};

struct Course
{
    string teacher_name;
    string course_ID;
    string course_name;
    Scoreboard *scoreboard_head; //Points to the ScoreBoard
    Course *course_next; //Next Course
    Student *student_head; //Points to the student
};

struct Year
{
    string year_name;
    Class *class_head; //Points to the Class
    Semester *semester_head; //Points to the Semester
    Year *year_next; //Next Year
};

struct Semester
{
    unsigned int Semester_Ord; //Ordinal number
    Course *course_head; //Points to the Course
    Semester *semester_next; //Next Semester
};

struct Scoreboard
{
    float total_mark;
    float midterm_mark;
    float final_mark;
    float other_mark;
    Student *student_head;
};

bool isLoggedIn();
void login(bool isStudent, string &username);
void logout();
void changePass(string username, bool isStudent);
int firstScreen(bool &check);
int viewSchoolYear_Screen(string username, Year* year_head);
int Main_Staff_Screen(string &username, Year *&year_head);
int Main_Student_Screen(string username);
void interface(int option, Year* &year_head);
void convertTime_slot(Class *a);
int main();
#endif