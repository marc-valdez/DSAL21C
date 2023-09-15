// Create a complete C++ program that will allow the user to input a symbol and display a 10x10 square using this symbol. Use while loop.

#include <iostream>
using namespace std;

int main()
{
    char symbol = ' ';
    cout << "Please enter a symbol (ex. #): ";
    cin >> symbol;

    int i = 0, j = 0;

    while(i < 10)
    {
        j = 0;
        while(j < 10)
        {
            cout << symbol;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}