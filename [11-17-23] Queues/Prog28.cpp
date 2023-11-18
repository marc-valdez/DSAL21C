// Write a C++ program that will declare a QUEUE named MyQueue. Enable the user to SERVE an integer from the queue.

#include <iostream>
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
    int size;
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
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

void serve(QueuePointer &head, QueuePointer &tail, int &item, int &size)
{
    QueuePointer temp;
    if(head == NULL)
        cout << "! Queue underflow. Cannot delete further." << endl;
    else
    {
        item = head->value;
        temp = head;
        head = head->next;
        if(head == NULL)
            tail = NULL;
        free(temp);
        size--;
    }
}

int main()
{
    Queue MyQueue;

    // Store 1 to 10 inside MyQueue
    for(int i = 1; i <= 10; i++)
        append(MyQueue.head, MyQueue.tail, i, MyQueue.size);

    // Show the available items
    cout << "Available items: ";
    printQueue(MyQueue.head);

    int numItems = 0;
    cout << "How many items would you like served? (Max 10) >> ";
    cin >> numItems;

    int items[10] = {0};
    for(int i = 0; i < numItems; i++)
        serve(MyQueue.head, MyQueue.tail, items[i], MyQueue.size);

    cout << "Queue: ";
    printQueue(MyQueue.head);

    cout << "Served items: ";
    for(int i = 0; i < numItems; i++)
        cout << items[i] << " ";
    cout << endl;

    return 0;
}