// Write a C++ program that will declare a QUEUE named MyQueue. Enable the user to APPEND an integer unto the queue.

#include <iostream>
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
    Queue()
    {
        head = NULL;
        tail = NULL;
    }
};

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

void printQueue(QueuePointer head)
{
    while(head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Queue MyQueue;

    while(true)
    {
        int newValue = 0;
        cout << "What value would you like to append? (-1 to exit) >> ";
        cin >> newValue;
        if(newValue == -1)
            break;

        append(MyQueue.head, MyQueue.tail, newValue);
    }

    cout << "Queue: ";
    printQueue(MyQueue.head);

    return 0;
}