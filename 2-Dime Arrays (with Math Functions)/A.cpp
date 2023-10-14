// WAC++P that will prompt the user to enter 10 numbers in an Array named MyNums.
// The program should be able to compute and display the Squared, Cubed and Square Root (rounded off) 
// value of each number which are to be stored also in the same array, in a table format.

#include <iostream>
#include <cmath>
using namespace std;

double getNumber(int index)
{
    double input = 0.0;
    cout << "[" << index << "] Please enter a number: ";
    cin >> input;
    return input;
}

int main()
{
    double MyNums[10][4];
    for(int i = 0; i < 10; i++)
    {
        MyNums[i][0] = getNumber(i);
        MyNums[i][1] = pow(MyNums[i][0], 2);
        MyNums[i][2] = pow(MyNums[i][0], 3);
        MyNums[i][3] = sqrt(MyNums[i][0]);
    }

    cout << "\n\tNumber\t|\tSquared\t|\tCubed\t|\tSquare Root\n";
    cout << "=========================================================================\n";
    for(int i = 0; i < 10; i++)
    {
        cout << "[" << i << "]\t";
        printf("%.0f\t|\t", MyNums[i][0]);
        printf("%.0f\t|\t", MyNums[i][1]);
        printf("%.0f\t|\t", MyNums[i][2]);
        printf("%.11f\t|\t", MyNums[i][3]);
        cout << endl;
    }
    return 0;
}