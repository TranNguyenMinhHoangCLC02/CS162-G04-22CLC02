#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

bool isLoggedIn() {
    // Check whether the user is currently logged in by checking the isLoggedIn.txt file
    ifstream file("../Txt_Csv/isLoggedIn.txt");
    string line;
    getline(file, line);
    file.close();
    return (line == "1");
}

void login(bool isStudent, string &username) 
{
    // Check whether the login information is correct by comparing it with the acc_student.csv file or acc_staf.csv
    if (isStudent)
    {   
        SetScreenBufferSize(1000,1000);
        system("color E0");

        gotoXY(43,2);
        std::cout << "   _____ _____ _   _______ _____ _   _ _____      _     _____ _____     _____ _   _";
        gotoXY(43,3);
        std::cout << "  /  ___|_   _| | | |  _  \\  ___| \\ | |_   _|    | |   |  _  |  __ \\   |_   _| \\ | |";
        gotoXY(43,4);
        std::cout << "  \\ `--.  | | | | | | | | | |__ |  \\| | | |______| |   | | | | |  \\/_____| | |  \\| |";
        gotoXY(43,5);
        std::cout << "   `--. \\ | | | | | | | | |  __|| . ` | | |______| |   | | | | | _|______| | | . ` |";
        gotoXY(43,6);
        std::cout << "  /\\__/ / | | | |_| | |/ /| |___| |\\  | | |      | |___\\ \\_/ / |_\\ \\    _| |_| |\\  |";
        gotoXY(43,7);
        std::cout << "  \\____/  \\_/  \\___/|___/ \\____/\\_| \\_/ \\_/      \\_____/\\___/ \\____/    \\___/\\_| \\_/";

        std::string username; std::string password; int count = 0;

        Create_A_Box_2(68,11,2,30,14,14,0,"USERNAME");
        Create_A_Box_2(68,16,2,30,14,14,0,"PASSWORD");
        ShowConsoleCursor(false);

        int x_temp = 68; int y_temp = 11;
        while (count < 2)
        {
            system("color E0");

            if (y_temp == 11)
            {
                gotoXY(x_temp + 2, y_temp + 1);
                ShowConsoleCursor(true);
                cin.ignore();
                cin >> username;

                if (username != "")
                    count++;

                y_temp = 16;
                continue;
            }
            else
            {
                gotoXY(x_temp + 2, y_temp + 1);
                ShowConsoleCursor(true);
                cin >> password;

                if (password != "")
                    count++;

                y_temp = 11;
                continue;
            }
        }

        fstream file("../Txt_Csv/acc_student.csv");
        string line;
        getline(file, line);  // Skip the first line of the file as it is a header
        while (getline(file, line)) 
        {
            if (line.substr(0, line.find(',')) == username) {
                string passwordFromFile = line.substr(line.find(',') + 1);
                if (password == passwordFromFile) {
                    // If the login is successful, write the login status to the isLoggedIn.txt file and exit the function
                    ofstream file("../Txt_Csv/isLoggedIn.txt");
                    file << "1";
                    file.close();
                    return;
                }
            }
        }
    }
    else
    {
        SetScreenBufferSize(1000,1000);
        system("color E0");

        gotoXY(48,2);
        std::cout << "   _____ _____ ___ ____________      _     _____ _____     _____ _   _";
        gotoXY(48,3);
        std::cout << "  /  ___|_   _/ _ \\|  ___|  ___|    | |   |  _  |  __ \\   |_   _| \\ | |";
        gotoXY(48,4);
        std::cout << "  \\ `--.  | |/ /_\\ \\ |_  | |_ ______| |   | | | | |  \\/_____| | |  \\| |";
        gotoXY(48,5);
        std::cout << "   `--. \\ | ||  _  |  _| |  _|______| |   | | | | | _|______| | | . ` |";
        gotoXY(48,6);
        std::cout << "  /\\__/ / | || | | | |   | |        | |___\\ \\_/ / |_\\ \\    _| |_| |\\  |";
        gotoXY(48,7);
        std::cout << "  \\____/  \\_/\\_| |_|_|   \\_|        \\_____/\\___/ \\____/    \\___/\\_| \\_/";

        std::string username; std::string password; int count = 0;

        Create_A_Box_2(68,11,2,30,14,14,0,"USERNAME");
        Create_A_Box_2(68,16,2,30,14,14,0,"PASSWORD");
        ShowConsoleCursor(false);

        int x_temp = 68; int y_temp = 11;
        while (count < 2)
        {
            system("color E0");

            if (y_temp == 11)
            {
                gotoXY(x_temp + 2, y_temp + 1);
                ShowConsoleCursor(true);
                cin >> username;

                if (username != "")
                    count++;

                y_temp = 16;
                continue;
            }
            else
            {
                gotoXY(x_temp + 2, y_temp + 1);
                ShowConsoleCursor(true);
                cin >> password;

                if (password != "")
                    count++;

                y_temp = 11;
                continue;
            }
        }

        fstream file("../Txt_Csv/acc_staff.csv");
        string line;
        getline(file, line);  // Skip the first line of the file as it is a header
        while (getline(file, line)) 
        {
            if (line.substr(0, line.find(',')) == username) 
            {
                string passwordFromFile = line.substr(line.find(',') + 1);
                if (password == passwordFromFile) {
                    // If the login is successful, write the login status to the isLoggedIn.txt file and exit the function
                    ofstream file("../Txt_Csv/isLoggedIn.txt");
                    file << "1";
                    file.close();
                    return;
                }
            }
        }
    }   

    // If the login is unsuccessful, display an error message and request the user to login again
    system("cls");
    Create_A_Box_1(64,20,2,38,14,14,4,"     Incorrect login information!");
    ShowConsoleCursor(false);
	login(isStudent, username);
}

void logout() 
{
    // Write the logout status to the isLoggedIn.txt file
    ofstream file("../Txt_Csv/isLoggedIn.txt");
    file << "0";
    file.close();
}