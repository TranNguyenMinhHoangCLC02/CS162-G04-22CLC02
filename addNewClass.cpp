#include "Staff.h"

/*Class Creation Function: Academic staff members will be able to create new classes for a school year.*/

Class* getClassListFromFile(Year *&year_head)
{
    ifstream ifs;
    ifs.open("class.txt");
    if (!ifs.is_open())
    {
        cerr << "Error: Unable to open file for reading\n";
        return nullptr;
    }
    year_head->class_head=nullptr;
    Class* temp = nullptr;
    string class_name;

    while (!ifs.eof())
    {
        getline(ifs, class_name, '\n');
        if (ifs.eof())
            break;

        Class* new_class = new Class();
        new_class->class_name = class_name;
        new_class->student_head = nullptr;
        new_class->next_class = nullptr;

        if (!year_head->class_head)
        {
            year_head->class_head = new_class;
            temp = year_head->class_head;
        }
        else
        {
            temp->next_class = new_class;
            temp = temp->next_class;
        }
    }

    ifs.close();
    return year_head->class_head;
}

int addNewClass (Year* &year_head, string username)
{
    ofstream ofs;
    Class* new_class = new Class();
    string class_name_pattern = "\\d{2}[A-Z]{3}\\d{2}";

    // Keep asking for input until a valid class name is provided
    bool valid_class_name = false;
    cin.ignore();
    while (!valid_class_name) 
    {
        cout << "Input class (format: 00ABC00): ";
        getline(cin, new_class->class_name);

        // Check if input format is correct
        if (regex_match(new_class->class_name, regex(class_name_pattern)))
        {
            // Check if class already exists in class.txt file
            ifstream ifs("class.txt");
            if (ifs.is_open()) 
            {
                string line;
                while (getline(ifs, line)) 
                {
                    if (line == new_class->class_name) 
                    {
                        cout << "Class already exists! Please input class again.\n";
                        break; // exit inner loop
                    }
                }
                ifs.close();
                if (line == new_class->class_name)
                    continue; // class name already exists, try again
            }
            valid_class_name = true; // class name is valid, exit outer loop
        }
        else
            cout << "Invalid format! Please input class again.\n";
    }
    // Class name input is valid
    year_head->class_head->student_head = nullptr;
    year_head->class_head->next_class= nullptr;
    if (year_head->class_head==nullptr) {
        year_head->class_head= new_class;
    }
    else {
        Class *temp= year_head->class_head;
        while (temp->next_class!=nullptr) {
            temp = temp->next_class;
        }
        temp->next_class = new_class;
    }

    // Append new class to class.txt file
    ofs.open("class.txt", ios::app);
    if (!ofs.is_open()) {
        cerr << "Error: Unable to open file for writing\n";
        return 0;
    }
    ofs << new_class->class_name << "\n";
    ofs.close();

    cout << "You created a new class successfully!\n\n";
    string name_file = new_class->class_name + "-" + year_head->year_name + ".txt";
    ofs.open(name_file);
    if (!ofs.is_open()) {
        cerr << "Error: Unable to open file for writing\n";
        return 0;
    }
    ofs.close();

    string option;
    cout << "Please type the number 0 for returning back: ";
    cin >> option;
    cin.ignore();

    while (option!="0") {
        cout << "The number is different from 0, please input again: ";
        cin >> option;
        cin.ignore();
    }
    if (option == "0") {
        system ("cls");
        return viewSchoolYear_Screen(username, getYearListFromFile());
    }
    return 0;
}