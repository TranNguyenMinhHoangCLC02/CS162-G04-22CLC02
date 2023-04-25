#include "../Header/Staff.h"
#include "../Header/Student.h"

Year *year_head = nullptr;
int main()
{
    bool check;
    // PlaySoundA("BackgroundMusic.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NOSTOP);
    int option = firstScreen(check);
    if (check == false) //Out the program
    {
        PlaySound(NULL, NULL, 0);
        return 0;
    }

    Myinterface(option, year_head); //Continue with 1 of 2 rest options

    return 0;
}