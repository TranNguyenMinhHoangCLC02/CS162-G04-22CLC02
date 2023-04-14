#include "../Header/Staff.h"

void accessCourse(string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{
    system("cls");
    cout << "\n";
    cout << "------------"<< course_head->course_name <<"--------------\n";
    cout << "0. " << setw(2) << right << "Return back\n";
    cout << "1. " << setw(2) << right << "Add student one by one\n";
    cout << "2. " << setw(2) << right << "View all students in this course\n";
    cout << "3. " << setw(2) << right << "View the scoreboard of this course\n";
    cout << "4. " << setw(2) << right << "Update the scoreboard of this course\n";
    cout << "5. " << setw(2) << right << "Export file scoreboard.csv for teacher\n";
    cout << "6. " << setw(2) << right << "Update file scoreboard.csv to the system\n";
    int option;
    do
    {
        cout << "Input option: ";
        cin >> option;
    } while (option < 0 || option > 5);

    if (option == 0)
    {
        system("cls");
        viewCourse_Screen(username, year_head, semester_head);
        return;
    }
    else if(option == 1){
        system("cls");
        addStudentToCourse(course_head);
        deallocateStudents(course_head->student_head);
        accessCourse(username, year_head, semester_head, course_head);
        return;
    }
    else if(option == 2)
    {
        system ("cls");
        viewStudentInCourse(username, year_head, semester_head, course_head);
        return;
    }
    else if (option == 3)
    {
        system("cls");
        string filename;
        char ch_semester = static_cast<char>(semester_head->Semester_Ord + 48);
        filename = course_head->course_name + "_" + "Semester" + ch_semester + "_" + year_head->year_name + "_Scoreboard.csv";
        filename = "../Txt_Csv/" + filename;
        viewScoreBoard_Course(filename, username, year_head, semester_head, course_head);
        return;
    }
    else if (option == 4)
    {
        system("cls");
        string filename;
        char ch_semester = static_cast<char>(semester_head->Semester_Ord + 48);
        filename = course_head->course_name + "_" + "Semester" + ch_semester + "_" + year_head->year_name + "_Scoreboard.csv";
        filename = "../Txt_Csv/" + filename;
        updateStudentsScore(filename, username, year_head, semester_head, course_head);
        return;
    }
    else if (option == 5)
    {
        system("cls");
        string filename;
        char ch_semester = static_cast<char>(semester_head->Semester_Ord + 48);
        filename = course_head->course_name + "_" + "Semester" + ch_semester + "_" + year_head->year_name;
        filename = "../Txt_Csv/" + filename;
        export_scoreboard(filename, username, year_head, semester_head, course_head);
        return;
    }
    else if (option == 6)
    {
        system("cls");
        string filename;
        update_scoreBoard(filename, username, year_head, semester_head, course_head);
        return;
    }
}