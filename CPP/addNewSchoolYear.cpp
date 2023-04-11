#include "../Header/Staff.h"

/*
School Year Creation Function: This function allows academic staff members to create 
a new school year in the system.
*/

bool checkSyntaxOfSchoolYear (string year_name)
{
    //Get start year in string year_name
    int startyear = 0; int indexstring = 0; int len_year = year_name.size();

    while (indexstring < len_year && year_name[indexstring] >= '0' && year_name[indexstring] <= '9')
    {
        startyear = startyear * 10 + (int)year_name[indexstring] - 48;
        indexstring++;
    }

    if (indexstring == len_year) //when year_name includes only number letters
        return false;
    else
    {
        if (year_name[indexstring] != '-') //Violate the first and third principles
            return false;

        indexstring++;
    }

    int endyear = 0;

    while (indexstring < len_year && year_name[indexstring] >= '0' && year_name[indexstring] <= '9')
    {
        endyear = endyear * 10 + (int)year_name[indexstring] - 48; // '0' = 48
        indexstring++;
    }

    if (indexstring == len_year) 
    {
        if (endyear - startyear == 1)
            return true;
        else //Violate the first principle
            return false;
    }
    else //Violate the first and third principles
        return false;
}

bool checkExistingYear (Year* &year_head, string year_name) //Check violation the second principle
{
    if (!year_head)
        return true;

    Year* temp_year = year_head;
    while (temp_year)
    {
        if (year_name == temp_year->year_name)
            return false;

        temp_year = temp_year->year_next;
    }

    return true;
}

void addNewSchoolYear (Year* &year_head)
{
    ofstream ofs;

    //Create new node for linked list year_head
    Year* new_year = new Year;

    cout << "Principles when inputing a new school year\n";
    cout << "1. Your typed school year must be follows the syntax startyear-endyear, and the end year will after the start year exactly 1 year, for instance: 2019-2020\n";
    cout << "2. Don't input an available school year!\n";
    cout << "3. Your input will be false if it includes another letter that is not number and a hyphen between 2 years\n";
    cout << "4. You can input 0 whenever you want to return back\n\n";

    cin.ignore();
    cout << "Please type the school year you want to add (Ensure that your syntax follows our given principles: ";
    getline(cin, new_year->year_name);

    if (new_year->year_name == "0")
        return;

    //If user's input is wrong, input again
    while (!checkSyntaxOfSchoolYear(new_year->year_name) || !checkExistingYear(year_head, new_year->year_name))
    {
        if (!checkSyntaxOfSchoolYear(new_year->year_name))
        {
            cout << "Your input was wrong in its syntax, please input again: ";
            getline(cin, new_year->year_name);

            if (new_year->year_name == "0")
                return;
        }
        else
        {
            cout << "Your inputed school year was existed, please input another school year: ";
            getline(cin, new_year->year_name);

            if (new_year->year_name == "0")
                return;
        }
    }

    new_year->class_head = nullptr;
    new_year->semester_head = nullptr;
    new_year->year_next = nullptr;

    //Add new_year node at the end of year list
    if (!year_head)
        year_head = new_year;
    else
    {
        Year* temp = year_head;

        while (temp->year_next)
            temp = temp->year_next;
    
        temp->year_next = new_year;
    }

    //Print year list after changed out file schoolyear.txt
    ofs.open("../Txt_Csv/schoolyear.txt");
    if (!ofs.is_open())
    {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }

    Year* temp_year = year_head;
    while (temp_year->year_next)
    {
        ofs << temp_year->year_name << "\n";
        temp_year = temp_year->year_next;
    }
    ofs << temp_year->year_name;

    ofs.close();

    //Announce for user
    cout << "You created a new school year successfully!\n\n";

    //Create file including semesters of created year
    string name_file = new_year->year_name + "_semester.txt";
    name_file = "../Txt_Csv/" + name_file;
    ofs.open(name_file);
    if (!ofs.is_open())
    {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }
    ofs.close();

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