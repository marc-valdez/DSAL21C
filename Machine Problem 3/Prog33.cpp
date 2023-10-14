// Create a complete C++ program that will display all the elements in Array3D [Table No., Row No. and Column No.].
// Use for loop.

#include <iostream>
#include "dependency.hpp"
using namespace std;

int main()
{
    do {
        char threeDArray[3][3][3] = {
            {
                {'A', 'B', 'C'},
                {'D', 'E', 'F'},
                {'G', 'H', 'I'}
            },
            {
                {'J', 'K', 'L'},
                {'M', 'N', 'O'},
                {'P', 'Q', 'R'}
            },
            {
                {'S', 'T', 'U'},
                {'V', 'W', 'X'},
                {'Y', 'Z', '!'}
            }
        };

        for(int i = 0; i < 3; i++) {
            cout << "Tbl_" << i + 1 << "\t[0]\t[1]\t[2]\n\n";
            for(int j = 0; j < 3; j++) {
                cout << "[" << j << "]\t";
                for(int k = 0; k < 3; k++) {
                    cout << threeDArray[i][j][k] << "\t";
                }
                cout << endl;
            }
            cout << endl;
        }
    } while(tryAgain("\nDo you want to try again? (y/n): "));
    return 0;
}