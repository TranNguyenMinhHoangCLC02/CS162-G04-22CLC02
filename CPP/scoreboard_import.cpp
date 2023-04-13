#include "../Header/Staff.h"
#include "../Header/Student.h"

void export_scoreboard(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{    
    system("cls");
    cout << "------------"<< course_head->course_name << "_" << "Semester" << semester_head->Semester_Ord << "_" << year_head->year_name  <<"--------------\n";
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
    //Ask the staff if they want to continue
    cout << "If the file has been created before, the file will be rewrite.\n";
    cout << "Do you want to continue?\n";
    cout << "0. " << setw(2) << right << "Return back\n";
    cout << "1. " << setw(2) << right << "Continue\n";
    int choice = 2;
    cin >> choice;
    while(choice != 0 && choice != 1)
    {
        cout << "Please input again: ";
        cin >> choice;
    }
    if(choice == 0)
    {
        accessCourse(username, year_head, semester_head, course_head);
        return;
    }
    cout << "The name of this file will be CourseName_SemesterOrd_Year(eg: KY THUAT LAP TRINH_Semester2_2019-2020)\n";
    //Create a CSV file
    filename = "../Txt_Csv/" + filename + "_Scoreboard.csv";
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

void update_scoreBoard(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head){
    system("cls");
    cout << "------------"<< course_head->course_name << "_" << "Semester" << semester_head->Semester_Ord << "_" << year_head->year_name  <<"--------------\n";

    cout << "\nPlease input the name of the file you want to update.\nThe name of the file should be CourseName_SemesterOrd_Year(KY THUAT LAP TRINH_Semester2_2019-2020)\nYour input is: ";
    cin >> filename;
    filename = "../Txt_Csv/" + filename + "_Scoreboard.csv";
    ifstream ifs (filename);
    if(!ifs.is_open())
    {
        cout << "The file " << filename << " does not exist. Please input 0 to return back.\n Your option:";
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
    else{
        cout << "The file " << filename << " has been updated successfully.\n";
        cout << "0. " << setw(2) << right << "Return back\n";
        cout << "1. " << setw(2) << right << "View all student scoreboard\n";
        int opt = 2;
        cin >> opt;

        while (opt != 0 && opt != 1)
        {
            cout << "Please input again: ";
            cin >> opt;
        }
        if(opt == 0){
            accessCourse(username, year_head, semester_head, course_head);
        }
        else{
            viewScoreBoard_Course(filename, username, year_head, semester_head, course_head);
        }
    }
}