#include "Student.h"
#include "Structures.h"

void addTail(Student* &student_head, Student* tmp)
{
    if(student_head == NULL)
        student_head = tmp;
    else 
    {
        Student* cur = student_head;
        while(cur->student_next != NULL)
            cur = cur->student_next;
        cur->student_next = tmp;
    }
}

void getDate(Student* &tmp , string date_string) 
{
    string day_string = date_string.substr(0, 2);
    string month_string = date_string.substr(3, 2);
    string year_string = date_string.substr(6, 4);
    tmp->DOB.day = stoi(day_string);
    tmp->DOB.month = stoi(month_string);
    tmp->DOB.year = stoi(year_string);
}

Class* upload_info_class(ifstream &file)
{
    Student* student_head = NULL;
    Class* class_return = new Class(); // initialize class_return
    string line;
    getline(file,line);
    unsigned int count = 1;
    while(getline(file,line))
    {
        Student* dummy = new Student(); 
        dummy->student_No = count;
        string tmp;
        stringstream ss(line);
        getline(ss, tmp, ',');
        dummy->student_ID = tmp;
        getline(ss, tmp, ',');
        dummy->student_socialID = tmp; 
        getline(ss, tmp, ','); 
        dummy->student_fisrtname = tmp;
        getline(ss, tmp, ',');
        dummy->student_lastname = tmp;
        getline(ss, tmp, ',');
        dummy->gender = stoi(tmp);
        getline(ss, tmp, ',');
        class_return->class_name = tmp;
        getline(ss, tmp, ',');
        getDate(dummy, tmp);
        dummy->student_next = NULL;
        addTail(student_head, dummy);
        count++;
    }
    class_return->student_head = student_head;
    class_return->slot = to_string(count-1);
    class_return->class_id = class_return->class_name;
    class_return->next_class = NULL;

    return class_return;
}
