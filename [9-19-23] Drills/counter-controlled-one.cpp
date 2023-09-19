// Make a C++ program that would generate each of the following columns of numbers.
// Loop1: 1 3 5 7 9 11 13 15

#include <iostream>
using namespace std;

int main()
{
    cout << "|LOOP1 \t|" << endl;
    for (int i = 1; i <= 15; i += 2)
        cout << "|" << i << "\t|" << endl;
    cout << endl;
}