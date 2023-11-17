// Write a C++ program that will declare a QUEUE named MyQueue. Enable the user to select either to APPEND or SERVE an integer to or from the queue.

#include <iostream>
#include "dependency.hpp"
using namespace std;

#define MAX 10

struct Node {
    double value;
    struct Node *next;
};
typedef struct Node *QueuePointer;

class Queue {
public:
    QueuePointer head;
    QueuePointer tail;
    Queue()
    {
        head = NULL;
        tail = NULL;
    }
};

void printQueue(QueuePointer head)
{
    if(head == NULL)
    {
        cout << "Queue is empty." << endl;
        return;
    }
    while(head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

void append(QueuePointer &head, QueuePointer &tail, int newValue)
{
    QueuePointer newNode;
    newNode = (QueuePointer)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        cout << "! Out of memory." << endl;
        exit(0);
    }

    newNode->value = newValue;
    newNode->next = NULL;
    if(tail == NULL)
        head = newNode;
    else
        tail->next = newNode;
    tail = newNode;
}

int serve(QueuePointer &head, QueuePointer &tail, int &item)
{
    QueuePointer temp;
    if(head == NULL)
    {
        cout << "Queue is empty. Cannot delete further." << endl;
        return 1;
    }
    else
    {
        item = head->value;
        temp = head;
        head = head->next;
        if(head == NULL)
            tail = NULL;
        free(temp);
    }
    return 0;
}

int main()
{
    Queue MyQueue;

    // Store 1 to 10 inside MyQueue
    for(int i = 1; i <= 10; i++)
        append(MyQueue.head, MyQueue.tail, i);

    do
    {
        // Show the available items
        cout << "Available items: ";
        printQueue(MyQueue.head);

        int choice = 0;
        cout << "[1] Append" << endl;
        cout << "[2] Serve" << endl;
        cout << "What would you like to do? >> ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int newValue = 0;
                cout << "What value would you like to append? >> ";
                cin >> newValue;

                append(MyQueue.head, MyQueue.tail, newValue);
                break;
            }
            case 2:
            {
                int numItems = 0;
                cout << "How many items would you like served? >> ";
                cin >> numItems;

                int items[10] = {0};
                for(int i = 0, errorCheck = 0; (i < numItems && errorCheck == 0); i++)
                {
                    errorCheck = serve(MyQueue.head, MyQueue.tail, items[i]);
                }

                cout << "Served items: ";
                for(int i = 0; i < numItems; i++)
                    cout << items[i] << " ";
                cout << endl;
                break;
            }
            default:
                cout << "Invalid choice." << endl;
                break;
        }

        cout << "Queue: ";
        printQueue(MyQueue.head);
    } while(tryAgain("Would you like to continue? (y/n) >> "));

    return 0;
}