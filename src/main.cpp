#include "slots.h"
#include <iostream>
#include <ctime>
#include <unistd.h>
//#include <windows.h> for windows users

using namespace std;

int main() {
    srand(time(NULL));
    int choice;

    Slots game;

    do {
        cout << "--- MENU ---\n";
        cout << "1. Play\n";

        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";

        cout << "4. Check Balance\n";
        cout << "0. Exit\n";

        cout << "Your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: 
                game.play();
                break;

            case 2:
                game.deposit();
                break;

            case 3:
                game.withdraw();
                break;

            case 4:
                game.checkBalance();
                break;

            case 0:
                cout << "Saving your balance...\n";
                sleep(1);
                cout << "Exitting\n";
                break;

            default:
                cout << "Unknown choice\n";
                break;
        }
    } while(choice != 0);

    return 0;
}