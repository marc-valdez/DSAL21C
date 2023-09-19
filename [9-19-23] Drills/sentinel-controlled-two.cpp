// Make a C++ program that would ask the users to enter scores until they enter '-1'.

#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    cout << "Please enter a score (-1 to end): " << endl;

    while (num != -1)
    {
        cin >> num;
    }
    cout << "Process completed." << endl;
    return 0;
}