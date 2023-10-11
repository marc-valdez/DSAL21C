// Create a complete C++ program that will find the nth Fibonacci number. 
// Use the formulas in finding the odd and even Fibonacci number. Provide its equivalent IPO and flowchart.

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

int fibonacci_algorithm(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fibonacci_algorithm(n - 1) + fibonacci_algorithm(n - 2);
}

int main()
{
    mainloop: do {
        int n = 0, fibonacci_number = 0;
        cout << "Please input an integer [n]: ";
        cin >> n;

        if(n < 0)
        {
            cout << "! Input cannot be negative." << endl;
            goto mainloop;
        }
    
        fibonacci_number = fibonacci_algorithm(n);
        if(n == 1)
            cout << "The " << n << "st Fibonacci number is " << fibonacci_number << endl;
        else if(n == 2)
            cout << "The " << n << "nd Fibonacci number is " << fibonacci_number << endl;
        else if(n == 3)
            cout << "The " << n << "rd Fibonacci number is " << fibonacci_number << endl;
        else
            cout << "The " << n << "th Fibonacci number is " << fibonacci_number << endl;
    } while(tryAgain("\nDo you want to try again? (y/n): "));
    return 0;
}