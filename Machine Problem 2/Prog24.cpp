// Create a complete C++ program that will determine the Greatest Common Divisor (GCD) of two inputted integers.
// Provide its equivalent IPO and flowchart.

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

int euclidian_gcd(int x, int y)
{
    if(y == 0)
        return x;
    else
        return euclidian_gcd(y, x % y);
}

int main()
{
    do {
        int x = 0, y = 0, gcd = 0;
        cout << "Please input integer one [x]: ";
        cin >> x;
        cout << "Please input integer two [y]: ";
        cin >> y;

        gcd = euclidian_gcd(x, y);
        cout << "The GCD of " << x << " and " << y << " is " << gcd << endl;
    } while(tryAgain("\nDo you want to try again? (y/n): "));
    return 0;
}