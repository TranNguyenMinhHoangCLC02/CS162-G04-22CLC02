#include "Staff.h"
#include "Student.h"
int accessSchoolYear(string username, Year* &year_head){
    system("cls");
    cout << "------------"<< year_head->year_name <<"--------------\n";
    cout << "0." << setw(2) << right << "Return back\n";
    cout << "1." << setw(2) << right << "Add a semester\n";
    cout << "2." << setw(2) << right << "Access a semester\n";
    cout << "3." << setw(2) << right << "Add a class\n";
    cout << "4." << setw(2) << right << "Access a class\n";

    int option;
    do
    {
        cout << "Input option: ";
        cin >> option;
    } while (option < 0 || option > 4);
    if (option == 0){
        return viewSchoolYear_Screen(username, year_head);
    }
    else if(option == 1)
    {
        system ("cls");
        year_head->semester_head = getSemesterListFromFile(year_head);
        return addNewSemester(username, year_head);
    }
    else if(option == 2){
        
    }
    else if(option == 3){
        
    }
    else if(option == 4){
        
    }
    return 0;
}