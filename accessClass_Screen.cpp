#include "Staff.h"

void accessClass(string username, Year* &year_head, Class *class_head)
{
    system("cls");
    cout << "\n";
    cout << "------------"<< class_head->class_name <<"--------------\n";
    cout << "0." << setw(2) << right << "Return back\n";
    cout << "1." << setw(2) << right << "Import new students to class from file student_info.csv\n";
    int option;
    do
    {
        cout << "Input option: ";
        cin >> option;
    } while (option < 0 || option > 1);

    if (option == 0)
    {
        system("cls");
        accessSchoolYear(username, year_head);
        return;
    }
    else if (option == 1)
    {
        system("cls");
        year_head->class_head->student_head = getStudentListFromFile(year_head);
        addNewStudent(username, year_head, class_head);
        return;
    }
}