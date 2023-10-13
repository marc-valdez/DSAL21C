// Using Arrays, create a complete C++ program that will display three columns of COVID-19 data; Active, Recoveries, and Deaths.

#include <iostream>
#include "dependency.hpp"
using namespace std;

int main()
{
    do {
        int covid_cases[3] = {0, 0, 0};
        cout << "Please enter the number of active cases: ";
        cin >> covid_cases[0];
        cout << "Please enter the number of recoveries: ";
        cin >> covid_cases[1];
        cout << "Please enter the number of deaths: ";
        cin >> covid_cases[2];

        cout << "\nCases: " << endl;
        cout << "Active\t| Recoveries\t| Deaths" << endl;
        cout << covid_cases[0] << "\t| " << covid_cases[1] << "\t| " << covid_cases[2] << endl;

    } while(tryAgain("\nDo you want to try again? (y/n): "));
    return 0;
}