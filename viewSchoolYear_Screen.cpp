#include "Structures.h"
#include "Staff.h"
#include "Student.h"
int viewSchoolYear_Screen(string username, Year* year_head){
    cout << "Choose the year: ";
    Year* cur = year_head;
    if(cur == nullptr){
        cout << "\n\nNothing to choose";
    }
    cout << endl;
    int i = 1;
    cout << "0." << setw(2) << right << "Go Back\n";
    while(cur){
        cout << i << "." << setw(2) << right << cur->year_name << "\n";
        cur = cur->year_next;
        i++;
    }
    cur = year_head;
    int option;
    do
    {
        cout << "Input option: ";
        cin >> option;
    } while (option < 0 && option > i);
    if (option == 0){
        system("cls");
        return Main_Staff_Screen(username, year_head);
    }
    else if(option == 1){
        accessSchoolYear(username, year_head);
    }
    else if(option == 2){
        accessSchoolYear(username, year_head->year_next);
    }
    else if(option == 3){
        accessSchoolYear(username, year_head->year_next->year_next);
    }
    else if(option == 4){
        accessSchoolYear(username, year_head->year_next->year_next->year_next);
    }
    return 0;
}