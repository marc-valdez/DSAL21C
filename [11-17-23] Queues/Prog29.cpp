// Write a C++ program that will declare a QUEUE named MyQueue. Enable the user to select either to APPEND or SERVE an integer to or from the queue.

#include <iostream>
#include "dependency.hpp"
using namespace std;

struct Node {
    double value;
    struct Node *next;
};
typedef struct Node *QueuePointer;

class Queue {
public:
    QueuePointer head;
    QueuePointer tail;
    int size;
    int maxSize;

    Queue(int newMax)
    {
        head = NULL;
        tail = NULL;
        size = 0;
        maxSize = newMax;
    }

    void printQueue()
    {
        if(head == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        QueuePointer temp = head; // Introduce a temporary pointer variable
        while(temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next; // Move the temporary pointer to the next node
        }
        cout << endl;
    }

    void append(int newValue)
    {
        if(size >= maxSize)
        {
            cout << "! Queue overflow. Cannot append further." << endl;
            return;
        }

        QueuePointer newNode = (QueuePointer)malloc(sizeof(struct Node));
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

        size++;
    }

    bool serve(int &item)
    {
        QueuePointer temp;
        if(head == NULL)
        {
            cout << "Queue is empty. Cannot delete further." << endl;
            return false;
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
        return true;
    }
};

int main()
{
    Queue MyQueue(10);

    // Store 1 to 9 inside MyQueue
    for(int i = 1; i <= 9; i++)
        MyQueue.append(i);

    do
    {
        // Show the available items
        cout << "Available items: ";
        MyQueue.printQueue();

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

                MyQueue.append(newValue);
                break;
            }
            case 2:
            {
                int numItems = 0;
                cout << "How many items would you like served? >> ";
                cin >> numItems;

                int items[10] = {0};
                for(int i = 0; i < numItems; i++)
                {
                    if (MyQueue.serve(items[i]))
                      cout << "Served item: " << items[i] << endl;
                    else
                      break;
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
        MyQueue.printQueue();
    } while(tryAgain("Would you like to continue? (y/n) >> "));

    return 0;
}