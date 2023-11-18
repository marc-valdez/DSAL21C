// Write a C++ program that will declare a QUEUE named MyQueue. Enable the user to APPEND an integer unto the queue.

#include <iostream>
using namespace std;

#define MAX 5

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
};

void append(QueuePointer &head, QueuePointer &tail, int newValue, int &size)
{
    if(size >= MAX)
    {
        cout << "! Queue overflow. Cannot append further." << endl;
        exit(1);
    }

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

    size++;
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
    Queue MyQueue(10);

    while(true)
    {
        int newValue = 0;
        cout << "What value would you like to append? (-1 to exit) >> ";
        cin >> newValue;
        if(newValue == -1)
            break;

        append(MyQueue.head, MyQueue.tail, newValue, MyQueue.size);
        cout << "Queue: ";
        printQueue(MyQueue.head);
        cout << endl;
    }

    cout << "Queue: ";
    printQueue(MyQueue.head);
    cout << endl;

    return 0;
}