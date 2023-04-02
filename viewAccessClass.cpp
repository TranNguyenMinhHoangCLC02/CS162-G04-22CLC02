#include "Staff.h"
#include "Student.h"

int viewAccessClass(string username, Year* &year_head, Class *cur)
{
    system("cls");
    cout << "\n";
    cout << "------------"<< year_head->year_name <<"--------------\n";
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
        return accessSchoolYear(username, year_head);
    }
    else if(option == 1)
    {
        system ("cls");
        year_head->class_head->student_head= getStudentListFromFile(year_head);
        return addNewStudent(username, year_head, cur);
    }

    return 0;
}