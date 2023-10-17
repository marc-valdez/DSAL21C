// Write a C++ program that will declare an array named myArray of size 10. 
// Prompt the user to input 10 integers to the array using a loop. 
// Display the values of myArray and their addresses using a pointer named myPtr

#include <iostream>
using namespace std;

int main()
{
    int myArray[10];
    int *myPtr;

    for(int i = 0; i < 10; i++)
    {
        cout << "[" << i << "] Please enter an integer : ";
        cin >> myArray[i];
    }

    cout << endl;

    cout << "    Values\t|\tMemory Address" << endl;
    for(int i = 0; i < 10; i++)
    {
        myPtr = &myArray[i];
        cout << "[" << i << "] " << myArray[i] << "\t\t|\t" << myPtr << endl;
    }

    return 0;
}