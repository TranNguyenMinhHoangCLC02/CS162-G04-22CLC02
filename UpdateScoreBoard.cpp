#include "Staff.h"
#include "Student.h"

void updateStudentsScore(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{
    system("cls");
    cout << "------------"<< course_head->course_name <<"--------------\n";
    int option=0;
    do
    {
        string id;
        cout << "Input student ID: ";
        getline(cin, id);
        ifstream ifs;
        ifs.open(filename);
        if (!ifs.is_open())
        {
            cerr << "Error: Unable to open file for reading\n";
            return;
        }
        ofstream ofs;
        ofs.open("temp.csv");
        if (!ofs)
        {
            cerr << "Error: Unable to open file for writing\n";
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
        rename("temp.csv", newfilename);
        cout << "Update Successful!\n";
        cout << "0. Return back\n";
        cout << "1. Continue updating\n";
        cout << "Please input your option: ";
        cin >> option;
        while (option!=0 && option!=1)
        {
            cout << "Please input again: ";
            cin >> option;
        }
        
    } while (option==1);
    system("cls");
    accessCourse(username, year_head, semester_head, course_head);
}