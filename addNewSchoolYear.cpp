#include "Structures.h"

bool checkSyntaxOfSchoolYear (string year_name)
{
    int startyear = 0; int indexstring = 0; int len_year = year_name.size();

    while (indexstring < len_year && year_name[indexstring] >= '0' && year_name[indexstring] <= '9')
    {
        startyear = startyear * 10 + (int)year_name[indexstring] - 48;
        indexstring++;
    }

    if (indexstring == len_year)
        return false;
    else
    {
        if (year_name[indexstring] != '-')
            return false;

        indexstring++;
    }

    int endyear = 0;

    while (indexstring < len_year && year_name[indexstring] >= '0' && year_name[indexstring] <= '9')
    {
        endyear = endyear * 10 + (int)year_name[indexstring] - 48;
        indexstring++;
    }

    if (indexstring == len_year)
    {
        if (endyear - startyear == 1)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool checkExistingYear (Year* &year_head, string year_name)
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

    ofs.open("temp.txt");
    if (!ofs.is_open())
    {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }

    //Create new node for linked list year_head
    Year* new_year = new Year;

    cout << "Principles when inputing a new school year\n";
    cout << "1. Your typed school year must be follows the syntax startyear-endyear, and the end year will after the start year exactly 1 year, for instance: 2019-2020\n";
    cout << "2. Don't input an available school year!\n";
    cout << "3. Your input will be false if it includes another letter that is not number and a hyphen between 2 years\n\n";

    cout << "Please type the school year you want to add (Ensure that your syntax follows our given principles: ";
    getline(cin, new_year->year_name);

    while (!checkSyntaxOfSchoolYear(new_year->year_name) || !checkExistingYear(year_head, new_year->year_name))
    {
        if (!checkSyntaxOfSchoolYear(new_year->year_name))
        {
            cout << "Your input was wrong in its syntax, please input again: ";
            getline(cin, new_year->year_name);
        }
        else
        {
            cout << "Your inputed school year was existed, please input another school year: ";
            getline(cin, new_year->year_name);
        }
    }

    new_year->class_head = nullptr;
    new_year->semester_head = nullptr;

    new_year->year_next = nullptr;

    if (!year_head)
    {
        year_head = new_year;
    }
    else
    {
        Year* temp = year_head;
        while (temp->year_next)
        {
            temp = temp->year_next;
        }
        temp->year_next = new_year;
    }

    Year* temp_year = year_head;
    while (temp_year)
    {
        ofs << temp_year->year_name << "\n";
        temp_year = temp_year->year_next;
    }

    ofs.close();
    remove("schoolyear.txt");
    rename("temp.txt", "schoolyear.txt");

    cout << "You created a new school year successfully!\n\n";

    int option;
    cout << "Please type the number 0 for returning back: ";
    cin >> option;

    while (option)
    {
        cout << "the number is different from 0, please input again!: ";
        cin >> option;
    }
}