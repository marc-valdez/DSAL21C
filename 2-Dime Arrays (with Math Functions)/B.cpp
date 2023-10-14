// WAC++P that will prompt the user to 5 numbers (Base) and another 5 numbers (Exponent) in an Array named MyNums. 
// The program should be able to compute and display the computed value of each number i.e. Base raised to Exponent, in a table format.

#include <iostream>
#include <cmath>
using namespace std;

double getNumber(const char* prompt, int index)
{
    double input = 0.0;
    cout << "[" << index << "] " << prompt;
    cin >> input;
    return input;
}

int main()
{
    double MyNums[5][3];
    for(int i = 0; i < 5; i++)
    {
        MyNums[i][0] = getNumber("Please enter a base number: ",i);
        MyNums[i][1] = getNumber("Please enter an exponent value: ", i);
        MyNums[i][2] = pow(MyNums[i][0], MyNums[i][1]);
    }

    cout << "\n\tBase\t| Exponent\t| Computed Value\n";
    cout << "=================================================\n";
    for(int i = 0; i < 5; i++)
    {
        cout << "[" << i << "]\t";
        printf("%.0f\t|\t", MyNums[i][0]);
        printf("%.0f\t|\t", MyNums[i][1]);
        printf("%.0f\t|\t", MyNums[i][2]);
        cout << endl;
    }
    return 0;
}