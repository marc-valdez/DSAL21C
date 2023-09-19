// Make a C++ program that would generate each of the following columns of numbers.
// Loop2: 20 18 16 14 12 10 8 6 4 2

#include <iostream>
using namespace std;

int main()
{
    cout << "|LOOP2 \t|" << endl;
    for(int i = 20; i >= 2; i -= 2)
        cout << "|" << i << "\t|" << endl;
    cout << endl;
    return 0;
}