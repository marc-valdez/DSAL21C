// Create a complete C# Program that will simulate the PUSH, POP, and PEEK Operations.
// Also, add a menu for displaying the state of your stack.

#include <iostream>
#include <iomanip>
#include "dependency.hpp"
using namespace std;

#define MAX 5

int main()
{
    Double choice(0);
    Stack myStack(MAX);

    do {
        system("cls");
        cout << "[1] PUSH" << endl;
        cout << "[2] POP" << endl;
        cout << "[3] PEEK" << endl;
        cout << "[4] SHOW" << endl;
        choice.setNumber("Please pick a menu item >> ", 1, 4);

        switch((int)choice.getNumber())
        {
            case 1:
            {
                system("cls");
                Double newValue(0);
                newValue.setNumber("What value would you like to push? >> ");
                myStack.push(newValue.getNumber());
                break;
            }
            case 2:
                system("cls");
                myStack.pop();
                break;
            case 3:
                system("cls");
                cout << "Top of Stack: " << myStack.peek() << endl;
                break;
            case 4:
                system("cls");
                myStack.showStack();
                break;
        }
    } while(tryAgain("\nDo you want to try again? (y/n): "));
    return 0;
}