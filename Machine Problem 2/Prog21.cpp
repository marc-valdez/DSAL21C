// Create a complete C++ program that will compute for the minimum number of moves 
// based on the inputted number of disks. 
// Provide its equivalent IPO and flowchart. (Refer to "Towers of Hanoi" problem).

#include <iostream>
#include <cmath>
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

int main()
{
    do {
        int disks = 0, moves = 0;
        cout << "Please enter the number of disks: ";
        cin >> disks;
        moves = pow(2, disks) - 1;
        cout << "Minimum number of moves = " << moves << endl;
    } while(tryAgain("\nDo you want to try again? (y/n): "));
    return 0;
}