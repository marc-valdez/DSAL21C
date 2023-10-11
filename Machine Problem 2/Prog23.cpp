// Create a complete C++ program that will simulate a slot machine with 1 as the starting value and 5 as the highest value.
// Use the rand() math function.

#include <iostream>
using namespace std;

bool tryAgain(string prompt)
{
    string input;
    cout << prompt;
    cin >> input;

    if(input == "y" || input == "Y") {
        return true;
    }
    else if(input == "n" || input == "N") {
        return false;
    }
    else {
        cout << "! Invalid input. Please try again." << endl;
        return tryAgain(prompt);
    }
}

void spin_reels(int reels[3])
{
    for(int i = 0; i < 3; i++)
        reels[i] = (rand() % 5) + 1;
}

void print_results(int reels[3])
{
    cout << "The reels are [" << reels[0] << "][" << reels[1] << "][" << reels[2] << "]\n";
    if(reels[0] == reels[1] && reels[1] == reels[2])
        cout << "You won!" << endl;
    else
        cout << "You lost." << endl;
}

int main()
{
    mainloop: do {
        int reels[3] = {1, 1, 1};
        string action;
        cout << "Please type \"SPIN\" to spin the reels. (Type \"QUIT\" to quit): ";
        cin >> action;
        if(action == "QUIT" || action == "quit")
            break;
        else if(action == "SPIN" || action == "spin")
        {
            spin_reels(reels);
            print_results(reels);
        }
        else
        {
            cout << "! Invalid input. Please try again." << endl;
            goto mainloop;
        }
    } while(tryAgain("\nDo you want to try again? (y/n): "));
    return 0;
}