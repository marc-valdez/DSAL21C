// 10 values in an array named Any.
// check if the value is a number, a letter, or a punctuation
// count and display how many are numbers, letters and punctuations
// and an appropriate message for each condition

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char Any[10];
    int numbers = 0, letters = 0, punctuations = 0;

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter a value: ";
        cin >> Any[i];
        if (isdigit(Any[i]))
            numbers++;
        else if (isalpha(Any[i]))
            letters++;
        else if (ispunct(Any[i]))
            punctuations++;
    }

    cout << "No. of Numbers: " << numbers << endl;
    cout << "No. of Letters: " << letters << endl;
    cout << "No. of Punctuations: " << punctuations << endl;

    return 0;
}