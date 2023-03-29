#include "Staff.h"

/*
Access School Year Function: This function allows academic staff members to access 
any school years that they created
*/

int accessSchoolYear(string username, Year* &year_head)
{
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

    if (option == 0)
    {
        system("cls");
        return viewSchoolYear_Screen(username, getYearListFromFile());
    }
    else if(option == 1){
        
    }
    else if(option == 2){
        
    }
    else if(option == 3){
        
    }
    else if(option == 4){
        
    }
    return 0;
}