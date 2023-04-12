#include "../Header/Staff.h"
#include "../Header/Student.h"

void import_scoreboard(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{    
    system("cls");
    //Check if any students existed
    if(!course_head->student_head)
    {
        cout << "There is no student in this course. Please input 0 to return back.\n Your option:";
        int opt = 1;
        cin >> opt;

        while (opt != 0)
        {
            cout << "Please input again: ";
            cin >> opt;
        }
        //Return to the access course screen
        accessCourse(username, year_head, semester_head, course_head);
        return;
    }
    
    //Create a CSV file
    filename = filename + "_Scoreboard.csv";
    ofstream ofs (filename);
    ofs << "StudentID,Fullname,Midterm Mark,Final Mark,Other Mark,Total Mark" << "\n";

    Student *cur = course_head->student_head;
    while(cur)
    {
        ofs << cur->student_ID << ",";
        ofs << cur->student_fisrtname << " " << cur->student_lastname << ",";
        ofs << ",,,," << endl;
        cur = cur->student_next;
    }
    cout << endl;
    cout << "The file " << filename << " has been created successfully.\n";
    cout << "Please input 0 to return back.\n Your option:" << "\n";
    int opt = 1;
    cin >> opt;

    while (opt != 0)
    {
        cout << "Please input again: ";
        cin >> opt;
    }
    accessCourse(username, year_head, semester_head, course_head);
    ofs.close();
}