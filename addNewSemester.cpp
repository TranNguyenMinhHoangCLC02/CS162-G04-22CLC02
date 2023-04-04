#include "Staff.h"

bool checkInvalidSemester (string input)
{
    if (input != "0" && input != "1" && input != "2" && input != "3")
        return false;

    return true;
}

bool checkExistingSemester (Semester* &semester_head, string input)
{
    if (input[0] == '0')
        return true;
    
    int semester_ord = (int)input[0] - 48;
    
    if (!semester_head)
        return true;
    
    Semester* temp_semester = semester_head;

    while (temp_semester)
    {
        if (temp_semester->Semester_Ord == semester_ord)
            return false;

        temp_semester = temp_semester->semester_next;
    }

    return true;
}

void addNewSemester (string username, Year* &year_head) //Now, year_head is the school year you are accessing
{
    ofstream ofs;

    //Create new node for linked list semester_head
    cout << "Principles when inputing a new semester\n";
    cout << "1. You must input a number from 1 to 3 because there are at most 3 semesters in a school year\n";
    cout << "2. Don't input an available semester in your chosen school year!\n";
    cout << "3. You can input 0 if you want to return back\n\n";

    string input;
    cin.ignore();
    cout << "Please type the semester you want to add (Ensure that your input follows our given principles: ";
    getline(cin, input);

    //If user's input is wrong, input again
    while (!checkInvalidSemester(input) || !checkExistingSemester(year_head->semester_head, input))
    {
        if (!checkInvalidSemester(input))
        {
            cout << "Your input must include a number from 0 to 3, please input again: ";
            getline(cin, input);
        }
        else
        {
            cout << "Your inputed semester was existed in your chosen school year, please input another semester: ";
            getline(cin, input);
        }
    }

    if (input == "0")
    {
        system ("cls");
        viewSchoolYear_Screen(username, getYearListFromFile());
    }
    else
    {
        //Create new semester
        Semester* new_semester = new Semester;
        new_semester->Semester_Ord = (int)input[0] - 48;
        new_semester->course_head = nullptr;
        new_semester->semester_next = nullptr;

        //Add new semester at the end of semester list of corresponding year
        if (!year_head->semester_head)
            year_head->semester_head = new_semester;
        else
        {
            Semester* temp_semester = year_head->semester_head;

            while (temp_semester->semester_next)
                temp_semester = temp_semester->semester_next;

            temp_semester->semester_next = new_semester;
        }
    }

    //Print semester list after changed out file txt corresponding with the semester
    string file_name = year_head->year_name + "_semester.txt";
    ofs.open(file_name);
    if (!ofs.is_open())
    {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }

    Semester* temp_semester = year_head->semester_head;
    while (temp_semester)
    {
        ofs << temp_semester->Semester_Ord << "\n";
        temp_semester = temp_semester->semester_next;
    }
    ofs.close();

    //Announce for user
    cout << "You created a new semester successfully!\n\n";

    //Require user input 0 for returning back
    string option;
    cout << "Please type the number 0 for returning back: ";
    getline(cin, option);

    while (option != "0")
    {
        cout << "The number is different from 0, please input again: ";
        getline(cin, option);
    }
}