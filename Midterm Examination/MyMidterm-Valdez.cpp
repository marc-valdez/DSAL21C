#include <iostream>

using namespace std;

void peek(double MyStack[12], int top)
{
    if(top == -1)
        cout << "The Stack is empty." << endl;
    else
    {
        // ...and perform and display the result (Value and Address) of the Stack Operation chosen. (15 points)
        printf("Value: %.2f\n", MyStack[top]);
        printf("Address: %p\n", &MyStack[top]);
    }
}

void push(double MyStack[12], int *top)
{
    if(*top >= 11)
        cout << "! Stack Overflow." << endl;
    else
    {
        double newValue = 0;
        cout << "What value would you like to push? >> ";
        cin >> newValue;

        *top = *top + 1;
        MyStack[*top] = newValue;
        
        // ...and perform and display the result (Value and Address) of the Stack Operation chosen. (15 points)
        printf("You pushed %.2f to the stack.\n", newValue);
        printf("The address of the new value is %p.\n", &MyStack[*top]);
    }
}
void pop(double MyStack[12], int *top)
{
    if(*top == -1)
        cout << "! Stack Underflow." << endl;
    else
    {
        // ...and perform and display the result (Value and Address) of the Stack Operation chosen. (15 points)
        printf("You have popped %.2f @ %p.\n", MyStack[*top], &MyStack[*top]);

        MyStack[*top] = 0;
        *top = *top - 1;

        printf("\nThe address of the new Top-of-Stack is %p.\n", &MyStack[*top]);
    }
}
void exitMessage()
{
    // Display your Full Name, Course and Section when the Exit option is chosen. (3 Points)
    cout << "Marc Joshua Arandia Valdez" << endl;
    cout << "BSCS" << endl;
    cout << "C231" << endl;
}

// Allow the user to enter another choice so long as he/she answers Yes to a prompt. (2 Points)
bool tryAgain(const char *prompt)
{
    string choice;
    cout << prompt;
    cin >> choice;
    
    if(choice == "Yes")
        return true;
    else if(choice == "No")
        return false;
    else
    {
        cout << "! Invalid input. Please try again." << endl;
        return tryAgain(prompt);
    }
}

int main()
{
    // Declare a Stack named MyStack which is of type Double and has a size of 12. (3 Points)
    double MyStack[12] = {0};
    int top = -1;

    int choice = 0;
    do {
        // Display a Menu for Stack Operations (Peek, Push, Pop, Exit). (2 Points) 
        system("cls");
        cout << "[1] Peek" << endl;
        cout << "[2] Push" << endl;
        cout << "[3] Pop" << endl;
        cout << "[4] Exit" << endl;

        // Enable the user to enter his/her choice from the Menu Options 
        // and perform and display the result (Value and Address) of the Stack Operation chosen. (15 points)
        cout << "Please choose an option >> ";
        cin >> choice;

        switch(choice)
        {
            case 1: system("cls"); peek(MyStack, top); break;
            case 2: system("cls"); push(MyStack, &top); break;
            case 3: system("cls"); pop(MyStack, &top); break;
            case 4: system("cls"); exitMessage(); break;
            default: system("cls"); cout << "! Invalid choice. Please try again." << endl; break;
        }
    } while(tryAgain("\nWould you like to choose another option? (Yes/No) >> "));

    return 0;
}