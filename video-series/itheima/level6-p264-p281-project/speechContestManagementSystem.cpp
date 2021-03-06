# include <iostream>
# include <ctime>

# include "speechManager.h"

using namespace std;

void main_func();

// build command:
// /usr/bin/clang++ -std=c++11 -g speechContestManagementSystem.cpp speechManager.cpp -o speechContestManagementSystem
/*
speechContestManagementSystem.cpp speechManager.cpp
*/

int main() {

    srand((unsigned int) time (NULL));

    SpeechManager sm;
    int choice = 0;

    // tester
    // for (map<int, Speaker>::iterator it = sm.speakers.begin(); it != sm.speakers.end(); it++)
    //     cout << it->first << " " << it->second.name << " " << it->second.score[0] << " " << it->second.score[1] << endl;

    while (true) {
        sm.showMenu();

        cout << "please type in your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:                 // begin
                sm.speechContesting();
                break;
            case 2:                 // previous
                sm.showRecord();
                break;
            case 3:                 // clear
                sm.clearRecord();
                break;
            case 0:                 // quit
                sm.quitSystem();
                break;
            default:
                system("clear");
                break;
        }
    }

    //system("pause");    // use it in windows, effect [press any key to continue], no such command in linux/mac

    return 0;
}
