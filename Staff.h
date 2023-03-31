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
Class* getClassListFromFile(Year *&year_head);
int addNewClass (Year* &year_head, string username);

#endif