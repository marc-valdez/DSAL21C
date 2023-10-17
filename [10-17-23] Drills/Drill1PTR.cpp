// Write a C++ program which does the following: 
// a. Declares an integer variable and a pointer variable which points to an integer. 
// b. Point the pointer variable to the address of the integer variable. 
// c. Display the value of the integer variable, its address, 
// the value of the pointer variable and its address.

#include <iostream>
using namespace std;

int main()
{
    int number = 100000;
    int *pointer_to_number = &number;

    cout << "The value of number is:\t\t\t\t" << number << endl;
    cout << "The memory address of number is:\t\t" << "\033[36m" << &number << "\033[0m" << endl;

    cout << "\nThe value of pointer_to_number is:\t\t" << "\033[36m" << pointer_to_number << "\033[0m" << endl;
    cout << "The memory address of pointer_to_number is:\t" << &pointer_to_number << endl;
    
    return 0;
}