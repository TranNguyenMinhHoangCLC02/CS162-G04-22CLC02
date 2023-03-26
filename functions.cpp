#pragma once
#include "Structures.h"

/*
Password Change Function: The user should be able to change their password after logging in. 
This function should allow the user to enter their current password and a new password, 
and then update the password in the database.
*/
void changePass(string username, bool isStudent)
{
    ifstream ifs;
    ofstream ofs;
    //choose which file to read
    if (isStudent == true)
        ifs.open("acc_student.csv");
    else
        ifs.open("acc_staff.csv");
    if (!ifs)
    {
        cerr << "Error: Unable to open file for reading\n";
        return;
    }
    //create temporary file to write
    ofs.open("temp.csv");
    if (!ofs)
    {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }
    string line;
    bool found = false;
    //read input form file and change password in the temporary file
    while (getline(ifs, line))
    {
        string user = line.substr(0, line.find(','));
        if (user == username)
        {
            string new_pass;
            cout << "New password: ";
            cin >> new_pass;
            ofs << user << "," << new_pass << "\n";
            found = true;
        }
        else
        {
            ofs << line << "\n";
        }
    }
    ifs.close();
    ofs.close();
    //check available username
    if (found == false)
    {
        cerr << "Error: Username not found\n";
        remove("temp.csv");
        return;
    }
    //delete old file and rename temporary file to old file
    if (isStudent == true)
    {
        remove("acc_student.csv");
        rename("temp.csv", "acc_student.csv");
    }
    else
    {
        remove("acc_staff.csv");
        rename("temp.csv", "acc_staff.csv");
    }
    cout << "Change successful!\n";
}