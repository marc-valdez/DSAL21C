// Make a C++ program that would ask the users for characters until the user enters 'X'.

#include <iostream>
using namespace std;

int main()
{
    cout << "Please enter any character ('X' to end): " << endl;
    for(char input; input != 'X'; cin >> input) {}
    return 0;
}