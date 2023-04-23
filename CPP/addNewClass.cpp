#include "../Header/Staff.h"
#include "../Header/Design.h"

/*Class Creation Function: Academic staff members will be able to create new classes for a school year.*/

void addNewClass (Year* &year_head, string username)
{
    system("cls");
    SetScreenBufferSize(10000,10000);
    system("color E0");
    SetColor1(14, 0);
    ofstream ofs;
    Class* new_class = new Class();
    new_class->class_name="";
    // Keep asking for input until a valid class name is provided
    bool valid_class_name = false;
    int counter=0;
    Create_A_Box_2(1, 3, 2, 30, 14, 14, 0, "INPUT NEW CLASS");
    while (valid_class_name != true) 
    {
        // cout << "Input class: ";
        // getline(cin, new_class->class_name);
        gotoXY(1 + 2, 3 + 1);
        ShowConsoleCursor(true);
        char c;
        int x_temp=1;
        int y_temp=3;
        int pos_classname = 0;
        while (true)
        {
            c = _getch();

            if (c == ENTER)
            {
                if (new_class->class_name != "")
                    break;
            }
            else if (c == BACKSPACE)
            {
                if (new_class->class_name != "" && pos_classname > 0)
                {
                    std::cout << "\b \b";
                    new_class->class_name.pop_back();
                }
            }
            else if (c == LEFT)
            {
                if (pos_classname > 0)
                {
                    pos_classname--;
                    gotoXY(x_temp + pos_classname + 2, y_temp + 1);
                }

                continue;
            }
            else if (c == RIGHT)
            {
                int len = new_class->class_name.size();

                if (pos_classname < len)
                {
                    pos_classname++;
                    gotoXY(x_temp + pos_classname + 2, y_temp + 1);
                }

                continue;
            }
            else
            {
                int len = new_class->class_name.size();

                if (c >= 32 && c <= 126 && len < 26)
                {
                    pos_classname++;
                    new_class->class_name += c;
                    std::cout << c;
                }
            }
        }
        // Check if class already exists in class.txt file
        ifstream ifs("../Txt_Csv/class.txt");
        bool check=true;
        if (ifs.is_open()) 
        {
            string line;
            while (getline(ifs, line)) 
            {
                if (line == new_class->class_name) 
                {
                    check=false;
                    break; // exit inner loop
                }
            }
        }
        ifs.close();
        if (check==true)
            valid_class_name = true; // class name is valid, exit outer loop
        else if (check==false)
        {
            Create_A_Box_2(1, 3, 2, 30, 14, 14, 0, "CLASS ALREADY EXISTS! PLEASE INPUT AGAIN");
            new_class->class_name="";
        }
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
    ofs.open("../Txt_Csv/class.txt", ios::app);
    if (!ofs.is_open()) {
        // cerr << "Error: Unable to open file for writing\n";
        Create_A_Box_1(1, 8, 2, 41, 14, 14, 0, "Error: Unable to open file for writing");
        return;
    }
    ofs << new_class->class_name << "\n";
    // Append new class to a specific class year
    ofs.close();
    string filename = "class_" + year_head->year_name + ".txt";
    filename = "../Txt_Csv/" + filename;
    ofs.open(filename, ios::app);
    if (!ofs.is_open())
    {
        // cerr << "Error: Unable to open file for writing\n";
        Create_A_Box_1(1, 8, 2, 41, 14, 14, 0, "Error: Unable to open file for writing");
        return;
    }
    ifstream checkEmpty;
    checkEmpty.open(filename);
    if (checkEmpty.peek() == ifstream::traits_type::eof())
        ofs << new_class->class_name;
    else
        ofs << "\n" << new_class->class_name;
    ofs.close();
    checkEmpty.close();
    // cout << "You created a new class successfully!\n\n";
    Create_A_Box_1(1, 8, 2, 41, 14, 14, 0, "You created a new class successfully!");
    string name_file = new_class->class_name + "-" + year_head->year_name + ".txt";
    name_file = "../Txt_Csv/" + name_file;
    ofs.open(name_file);
    if (!ofs.is_open()) 
    {
        // cerr << "Error: Unable to open file for writing\n";
        Create_A_Box_1(1, 14, 2, 41, 14, 14, 0, "Error: Unable to open file for writing");
        return;
    }
    ofs.close();

    // string option;
    // cout << "Please type the number 0 for returning back: ";
    // cin >> option;
    // cin.ignore();

    // while (option != "0") {
    //     cout << "The number is different from 0, please input again: ";
    //     cin >> option;
    //     cin.ignore();
    // }
    // if (option == "0") {
    //     system ("cls");
    //     accessSchoolYear(username, year_head);
    // }
    Create_A_Box_1(1, 14, 2, 14, 14, 14, 0, " RETURN BACK");
        SetColor1(15,0);
        for (int i = 1 + 1; i <= 14; ++i)
        {
            gotoXY(i, 15);
            std::cout << " ";
        }
        gotoXY(1 + 1, 15);
        std::cout << " RETURN BACK";
        ShowConsoleCursor(false);
        while (true)
        {
            if (_kbhit())
            {
                char c = _getch();
                if (c == ENTER)
                {
                    break;
                }
            }
        }
        system("color E0");
        system("cls");
        accessSchoolYear(username, year_head);
        return;
}