#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

void updateStudentsScore(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{
    system("cls");
    gotoXY(24, 1); cout <<"    _    _ _____  _____       _______ ______    _____  _____ ____  _____  ______ ____   ____          _____  _____  ";
    gotoXY(24, 2); cout <<"   | |  | |  __ \\|  __ \\   /\\|__   __|  ____|  / ____|/ ____/ __ \\|  __ \\|  ____|  _ \\ / __ \\   /\\   |  __ \\|  __ \\ ";
    gotoXY(24, 3); cout <<"   | |  | | |__) | |  | | /  \\  | |  | |__    | (___ | |   | |  | | |__) | |__  | |_) | |  | | /  \\  | |__) | |  | |";
    gotoXY(24, 4); cout <<"   | |  | |  ___/| |  | |/ /\\ \\ | |  |  __|    \\___ \\| |   | |  | |  _  /|  __| |  _ <| |  | |/ /\\ \\ |  _  /| |  | |";
    gotoXY(24, 5); cout <<"   | |__| | |    | |__| / ____ \\| |  | |____   ____) | |___| |__| | | \\ \\| |____| |_) | |__| / ____ \\| | \\ \\| |__| |";
    gotoXY(24, 6); cout <<"    \\____/|_|    |_____/_/    \\_\\_|  |______| |_____/ \\_____\\____/|_|  \\_\\______|____/ \\____/_/    \\_\\_|  \\_\\_____/ ";
    gotoXY(30, 9); cout << "------------------------------"<< course_head->course_name <<"--------------------------\n";
    int option = 0;
    do
    {
        string id;
        gotoXY(30, 11); cout << "INPUT STUDENT ID: ";
        getline(cin, id);
        ifstream ifs;
        ifs.open(filename);
        if (!ifs.is_open())
        {
            cerr << "ERROR: UNABLE TO OPEN FILE FOR READING\n";
            return;
        }
        ofstream ofs;
        ofs.open("../Txt_Csv/temp.csv");
        if (!ofs.is_open())
        {
            cerr << "ERROR: UNABLE TO OPEN FILE FOR WRITING\n";
            return;
        }
        int counter = 1;
        string student_id, fullname;
        float total, final1, midterm, other;
        string temp;
        string dummy;
        getline(ifs, dummy);
        ofs << dummy << "\n";
        while (!ifs.eof())
        {
            if (ifs.eof())
                break;
        
            getline(ifs, student_id, ',');
            getline(ifs, fullname, ',');
            getline(ifs, temp, ',');
            midterm = stof(temp);
            getline(ifs, temp, ',');
            final1 = stof(temp);
            getline(ifs, temp, ',');
            other = stof(temp);
            getline(ifs, temp, '\n');
            total = stof(temp);
            
            if (id == student_id)
            {
                cout << setw(3) << right << "No." << counter << " ";
                cout << setw(10) << left << student_id << " ";
                cout << setw(25) << left << fullname << " ";
                cout << setw(5) << right << fixed << setprecision(1) << midterm << " ";
                cout << setw(5) << right << fixed << setprecision(1) << final1 << " ";
                cout << setw(5) << right << fixed << setprecision(1) << other << " ";
                cout << setw(5) << right << fixed << setprecision(1) << total << endl;
                ofs << student_id << "," << fullname << ",";
                cout << "Enter new scores for the student:" << "\n";
                cout << "Midterm: ";
                cin >> midterm;
                cout << "Final: ";
                cin >> final1;
                cout << "Other: ";
                cin >> other;
                total = (midterm + final1 + other)/3.0;
                ofs << fixed << setprecision(1) << midterm << ","
                    << fixed << setprecision(1) << final1 << ","
                    << fixed << setprecision(1) << other << ","
                    << fixed << setprecision(1) << total;
            }
            else
            {
                ofs << student_id << "," << fullname << ",";
                ofs << fixed << setprecision(1) << midterm << ","
                    << fixed << setprecision(1) << final1 << ","
                    <<fixed << setprecision(1) << other << ","
                    << fixed << setprecision(1) << total;
            }
            if (!ifs.eof())
            {
                ofs << "\n";
            }
            counter++;
        }
        ifs.close();
        ofs.close();
        const char* newfilename = filename.c_str();
        remove(newfilename);
        rename("../Txt_Csv/temp.csv", newfilename);
        cout << "Update Successful!\n";
        cout << "0. Return back\n";
        cout << "1. Continue updating\n";
        cout << "Please input your option: ";
        cin >> option;
        while (option != 0 && option != 1)
        {
            cout << "Please input again: ";
            cin >> option;
        }
        
    } while (option == 1);
    system("cls");
    accessCourse(username, year_head, semester_head, course_head);
}