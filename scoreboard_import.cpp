#include "Staff.h"
#include "Student.h"

void import_scoreboard(Course *course_head){    
    string name = course_head->course_name;
    //Check if any students existed
    if(!course_head->student_head){
        cout << "There is no student in this course. Please input 0 to return back.\n Your option:";
        int opt = 1;
        cin >> opt;

        while (opt != 0)
        {
            cout << "Please input again: ";
            cin >> opt;
        }
        //Return to the .....
        return;
    }
    
    //Create a CSV file
    ofstream ofs (name);
    int i = 1;

    Student *cur = course_head->student_head;
    while(cur){
        ofs << i << ",";
        ofs << cur->student_ID << ",";
        ofs << cur->student_fisrtname << " " << cur->student_lastname << ",";
        ofs << ",,,," << endl;
        cur = cur->student_next;
    }
    cout << endl;
    cout << "Please input 0 to return back.\n Your option:" << "\n";
    int opt = 1;
    cin >> opt;

    while (opt != 0)
    {
        cout << "Please input again: ";
        cin >> opt;
    }
    ofs.close();
}