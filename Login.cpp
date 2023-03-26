#include "Structures.h"

bool isLoggedIn() {
    // Check whether the user is currently logged in by checking the isLoggedIn.txt file
    ifstream file("isLoggedIn.txt");
    string line;
    getline(file, line);
    file.close();
    return (line == "1");
}

void login(bool isStudent) 
{

    // Check whether the login information is correct by comparing it with the acc_student.csv file or acc_staf.csv
    if (!isStudent)
    {
        // Request user to input login information
        string username, password;
        cout << "User: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        fstream file("acc_student.csv");
        string line;
        getline(file, line);  // Skip the first line of the file as it is a header
        while (getline(file, line)) 
        {
            if (line.substr(0, line.find(',')) == username) {
                string passwordFromFile = line.substr(line.find(',') + 1);
                if (password == passwordFromFile) {
                    // If the login is successful, write the login status to the isLoggedIn.txt file and exit the function
                    ofstream file("isLoggedIn.txt");
                    file << "1";
                    file.close();
                    return;
                }
            }
        }
    }
    else
    {
        // Request user to input login information
        string username, password;
        cout << "User: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        fstream file("acc_staff.csv");
        string line;
        getline(file, line);  // Skip the first line of the file as it is a header
        while (getline(file, line)) 
        {
            if (line.substr(0, line.find(',')) == username) {
                string passwordFromFile = line.substr(line.find(',') + 1);
                if (password == passwordFromFile) {
                    // If the login is successful, write the login status to the isLoggedIn.txt file and exit the function
                    ofstream file("isLoggedIn.txt");
                    file << "1";
                    file.close();
                    return;
                }
            }
        } 
    }   

    // If the login is unsuccessful, display an error message and request the user to login again
    cout << "Incorrect login information! \n";
	login(isStudent);
}

void logout() {
    // Write the logout status to the isLoggedIn.txt file
    ofstream file("isLoggedIn.txt");
    file << "0";
    file.close();
}