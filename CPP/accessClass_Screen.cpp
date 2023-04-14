#include "../Header/Staff.h"

void accessClass(string username, Year* &year_head, Class *class_head)
{
    system("cls");
    cout << "\n";
    cout << "------------"<< class_head->class_name <<"--------------\n";
    cout << "0." << setw(2) << right << "Return back\n";
    cout << "1." << setw(2) << right << "Import new students to class from file student_info.csv\n";
    cout << "2." << setw(2) << right << "View all students in this class\n";
    cout << "3." << setw(2) << right << "View Scoreboard for this class\n";
    int option;
    do
    {
        cout << "Input option: ";
        cin >> option;
    } while (option < 0 || option > 3);

    if (option == 0)
    {
        system("cls");
        accessSchoolYear(username, year_head);
        return;
    }
    else if (option == 1)
    {
        system("cls");
        year_head->class_head->student_head = getStudentListFromFile(year_head, class_head);
        addNewStudent(username, year_head, class_head);
        deallocateStudents(year_head->class_head->student_head);
        return;
    }
    else if(option == 2)
    {
        viewStudentInClass(username, year_head, class_head);
    }
    else if (option == 3)
    {
        system("cls");
        viewScoreBoard_Class(username, year_head, class_head);
    }
}