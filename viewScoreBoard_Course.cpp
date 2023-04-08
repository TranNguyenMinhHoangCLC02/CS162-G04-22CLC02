#include "Staff.h"
#include "Student.h"

void viewScoreBoard_Course(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{
    system("cls");
    cout << "------------"<< course_head->course_name <<"--------------\n";
    ifstream ifs;
    ifs.open(filename);
    if (!ifs.is_open())
    {
        cerr << "Error: Unable to open file for reading\n";
        return ;
    }
    string dummy;
    getline(ifs, dummy);
    int counter=1;
    string student_id, fullname;
    float total, final1, midterm, other;
    string temp;
    while (!ifs.eof())
    {
        getline(ifs, student_id, ',');
        getline(ifs, fullname, ',');
        getline(ifs, temp, ',');
        midterm = stof(temp);
        getline(ifs, temp, ',');
        final1 = stof(temp);
        getline(ifs, temp, ',');
        other = stof(temp);
        getline(ifs, temp, '\n');
        total = stof(temp);
        cout << setw(3) << right << "No." << counter << " ";
        cout << setw(10) << left << student_id << " ";
        cout << setw(25) << left << fullname << " ";
        cout << setw(5) << right << fixed << setprecision(1) << midterm << " ";
        cout << setw(5) << right << fixed << setprecision(1) << final1 << " ";
        cout << setw(5) << right << fixed << setprecision(1) << other << " ";
        cout << setw(5) << right << fixed << setprecision(1) << total << endl;
        counter++;
    }
    cout << "0. Return back" << "\n";
    int opt = 1;
    cin >> opt;

    while (opt != 0)
    {
        cout << "Please input again: ";
        cin >> opt;
    }
    system("cls");
    accessCourse(username, year_head, semester_head, course_head);
}