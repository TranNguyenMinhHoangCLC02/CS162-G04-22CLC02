#ifndef Structures_h
#define Structures_h

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Scoreboard;
struct Course;
struct Student;
struct Class;
struct Semester;
struct Year;
struct Date;

string time_slot[] = {"S1", "S2", "S3", "S4"};

struct Date
{
    unsigned int day, month, year;
};

void convertTime_slot(Class *a)
{
    if (a->slot == time_slot[0])
        cout << "7:30";
    else if (a->slot == time_slot[1])
        cout << "9:30";
    else if (a->slot == time_slot[2])
        cout << "13:30";
    else if (a->slot == time_slot[3])
        cout << "15:30";
    else
        cout << "Invalid time slot";
}

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
    unsigned int stu_No;
    string stu_ID;
    string stu_name;
    Class stu_class;
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

#endif