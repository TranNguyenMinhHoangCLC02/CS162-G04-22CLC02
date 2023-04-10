#include "../Header/Staff.h"
#include "../Header/Student.h"

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
        ifs.open("../Txt_Csv/acc_student.csv");
    else
        ifs.open("../Txt_Csv/acc_staff.csv");
    if (!ifs)
    {
        cerr << "Error: Unable to open file for reading\n";
        return;
    }
    //create temporary file to write
    ofs.open("../Txt_Csv/temp.csv");
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
        remove("../Txt_Csv/temp.csv");
        return;
    }
    //delete old file and rename temporary file to old file
    if (isStudent == true)
    {
        remove("../Txt_Csv/acc_student.csv");
        rename("../Txt_Csv/temp.csv", "../Txt_Csv/acc_student.csv");
    }
    else
    {
        remove("../Txt_Csv/acc_staff.csv");
        rename("../Txt_Csv/temp.csv", "../Txt_Csv/acc_staff.csv");
    }
    cout << "Change successful!\n";
}