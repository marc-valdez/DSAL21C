// Write a C++ program that will declare variables iVal initialized to 25, 
// y to 3256 and a pointer named pInt initialized to the address of iVal. 
// Display the values of iVal, y, pInt and the address of iVal and y

#include <iostream>
using namespace std;

int main()
{
    int iVal = 25, y = 3256, *pInt = &iVal;

    cout << "The value of iVal is: \t\t\t" << iVal << endl;
    cout << "The value of y is: \t\t\t" << y << endl;
    cout << "The value of pInt is: \t\t\t" << "\033[36m" << pInt << "\033[0m" << endl;
    cout << "The memory address of iVal is: \t\t" << "\033[36m" << &iVal << "\033[0m" << endl;
    cout << "The memory address of y is: \t\t" << &y << endl;

    return 0;
}