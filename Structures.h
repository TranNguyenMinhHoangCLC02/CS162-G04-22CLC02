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

string time_slot[] = {"S1", "S2", "S3", "S4"};

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
    Student *student_head;
    Class *next_class;
    string slot;
};

#endif