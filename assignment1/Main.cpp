//Jose Huerta
//CS 260
//Assignment 1
#include <iostream>

using std::cout;
using std::cin;



int main() {
    bool running = true;
    int black = 0;
    int white = 0;
    int yellow = 0;
    int quantity = 0;
    int rand_num = rand() % 3 + 1;

    cout << "\nWelcome to your bag of marbles.";

    while (running) {
        cout << "\n---------------------------";
        cout << "\nWhat do you want to do?\n";
        cout << "\n1.   Add a marble\n";
        cout << "2.   Remove a marble\n";
        cout << "3.   View contents of bag\n";
        cout << "4.   Exit\n";

        cout << "Enter a number: ";
        int user_choice;
        cin >> user_choice;

        switch (user_choice) {
        case 1:
            cout << "\nWhat color do you wish to add?\n";
            cout << "1. Black\n";
            cout << "2. White\n";
            cout << "3. Yellow\n";

            int marble_choice;
            cin >> marble_choice;

            switch (marble_choice) {
            case 1:
                cout << "\nHow many black marbles do you want?\n";;
                cin >> black;
                quantity = black + white + yellow;
                break;
            case 2:
                cout << "\nHow many white marbles do you want?\n";;
                cin >> white;
                quantity = black + white + yellow;
                break;
            case 3:
                cout << "\nHow many yellow marbles do you want?\n";;
                cin >> yellow;
                quantity = black + white + yellow;
                break;
            
            default:
                cout << "Out of range.\n";
                break;
            }
            break;

        case 2:
            cout << "\nSelect what color you'd like to remove:\n";
            cout << "1. Black\n";
            cout << "2. White\n";
            cout << "3. Yellow\n";

            int remove_choice;
            cin >> remove_choice;

            switch (remove_choice) {
            case 1:
                if (black > 0) {
                    black = black - 1;
                } else {
                    cout << "Add a black marble before removing one.\n";
                }
                break;
            case 2:
                if (white > 0) {
                    white = white - 1;
                } else {
                    cout << "Add a white marble before removing one.\n";
                }
                break;
            case 3:
                if (yellow > 0) {
                    yellow = yellow - 1;
                } else {
                    cout << "Add a yellow marble before removing one.\n";
                }
                break;

            default:
            cout << "Out of range.\n";
                break;
            }
            break;

        case 3:
           
            cout << "\nCurrent bag contents:\n";
            cout << "Black: "<< black;
            cout << "\nWhite: "<< white;
            cout << "\nYellow: "<< yellow;

            quantity = black + white + yellow;
            cout << "\nTotal marbles: "<< quantity;
            break;

        case 4:
            cout << "\nExiting.";
            running = false;
            break;

        default:
            cout << "\nOut of range.\n";
            break;
        }
    }

    return 0;

    
    
}//end main

