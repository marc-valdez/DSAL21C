#include <iostream>
using namespace std;

int myStack[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int top = 9;
int limit = 9;

void push()
{
    cout << "Push: " << endl;

    if(top >= limit)
        cout << "Stack Overflow." << endl;
    else {
        cout << "What value would you like to push? >> ";
        int choice = 0;
        cin >> choice;
        top++;
        myStack[top] = choice;
    }

    system("pause");
    return;
}

void pop()
{
    cout << "Pop: " << endl;

    cout << "How many would you like to pop? >> ";
    int choice = 0;
    cin >> choice;

    if(choice == 0)
    {
        cout << "You have to pop at least 1." << endl;
        system("pause");
        return;
    }
    if(top - (choice - 1) < 0)
    {
        cout << "Stack Underflow." << endl;
        system("pause");
        return;
    }

    top = top - choice;
}

void peek()
{
    cout << "Peek: " << endl;

    if(top == -1)
        cout << "Stack is empty." << endl;
    else
        cout << "TOP: " << myStack[top] << endl;

    system("pause");
    return;

    // for(int i = top; i >= 0; i--)
    // {
    //     if(i == top)
    //         cout << "[TOS]: " << myStack[i] << endl;
    //     else
    //         cout << i << ". " << myStack[i] << endl;
    // }
}

void exitProg()
{
    cout << "Exiting..." << endl;
    system("pause");
    exit(0);
}

int main()
{
    while(true)
    {
        cout << "[1] Push" << endl;
        cout << "[2] Pop" << endl;
        cout << "[3] Peek" << endl;
        cout << "\nPlease choose an option (Any to Exit) >> ";

        int choice;
        cin >> choice;

        switch(choice)
        {
            case 1: system("cls"); push(); break;
            case 2: system("cls"); pop(); break;
            case 3: system("cls"); peek(); break;
            default: system("cls"); exitProg();
        }
        system("cls");
    }
}