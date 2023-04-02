#include "Staff.h"

int accessClass(string username, Year* &year_head, Class *class_head)
{
    system("cls");
    cout << "\n";
    cout << "------------"<< class_head->class_name <<"--------------\n";
    cout << "0." << setw(2) << right << "Return back\n";
    cout << "1." << setw(2) << right << "Import new students to class from file student_info.csv\n";
    cout << "2." << setw(2) << right << "View all students in this class\n";
    int option;
    do
    {
        cout << "Input option: ";
        cin >> option;
    } while (option < 0 || option > 2);

    if (option == 0)
    {
        return accessSchoolYear(username, year_head);
    }
    else if(option == 1)
    {
        system ("cls");
        year_head->class_head->student_head= getStudentListFromFile(year_head);
        return addNewStudent(username, year_head, class_head);
    }
    else if(option == 2){
        viewStudentInClass(username, year_head, class_head);
    }

    return 0;
}