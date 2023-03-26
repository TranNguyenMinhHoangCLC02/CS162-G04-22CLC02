
#include "Structures.h"
#include "Staff.h"
#include "Student.h"

void staff_info(string username){
    ifstream ifs;
    ifs.open("staff_info.csv");
    if(!ifs.is_open()){
        cout << "Cannot open file";
        return;
    }

    //Ignore the first line
    string ignore_line;
    getline(ifs, ignore_line);


    while(getline(ifs, ignore_line)){
        //find the username
        size_t pos = ignore_line.find(',');
        string first_column = ignore_line.substr(0, pos);


        if(username == first_column){
            stringstream ss(ignore_line);
            string field;
            int count = 1;
            while(getline(ss, field, ',')){
                if(count == 1){
                    cout << "Username: ";
                    cout << field;
                    count++;
                }
                else if(count == 2){
                    cout << "\nFull name: ";
                    cout << field;
                    count++;
                }
                else if(count == 3){
                    cout << "\nGmail: ";
                    cout << field;
                    count++;
                }
                else if(count == 4){
                    cout << "\nPhone Number: ";
                    cout << field;
                    count++;
                }
                else if(count == 5){
                    cout << "\nDOB: ";
                    cout << field;
                    count++;
                }
            }
        }
    }
}

void student_info(string username){
    ifstream ifs;
    ifs.open("student_info.csv");
    if(!ifs.is_open()){
        cout << "Cannot open file";
        return;
    }

    //Ignore the first line
    string ignore_line;
    getline(ifs, ignore_line);


    while(getline(ifs, ignore_line)){
        //find the username
        size_t pos = ignore_line.find(',');
        string first_column = ignore_line.substr(0, pos);


        if(username == first_column){
            stringstream ss(ignore_line);
            string field;
            int count = 1;
            while(getline(ss, field, ',')){
                if(count == 1){
                    cout << "Student ID: ";
                    cout << field;
                    count++;
                }
                else if(count == 2){
                    cout << "\nSocial ID: ";
                    cout << field;
                    count++;
                }
                else if(count == 3){
                    cout << "\nFull name: ";
                    cout << field << " ";
                    cout << field;
                    count++;
                }
                else if(count == 4){
                    cout << "\nGender: ";
                    if(field == "1"){
                        cout << "Male";
                    }
                    else{
                        cout << "Female";
                    }   
                    count++;
                }
                else if(count == 5){
                    cout << "\nClass: ";
                    cout << field;
                    count++;
                }
                else if(count == 6){
                    cout << "\nDOB: ";
                    cout << field;
                    count++;
                }
            }
        }
    }
}