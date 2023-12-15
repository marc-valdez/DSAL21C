#include <iostream>

using namespace std;

class ArrayQueue {
    int front;
    int rear;
    int size;
    int *array;

public:
    ArrayQueue(int size) {
        this->size = size;
        this->array = new int[size];
        this->front = 0;
        this->rear = -1;
    }

    void append(int value) {
        if(rear == size - 1) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % size;
        array[rear] = value;
    }

    int serve() {
        if(front == rear) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int value = array[front];
        front = (front + 1) % size;
        return value;
    }

    void printQueue(const char *prompt = "Queued: ") {
        cout << prompt;
        for(int i = 0; i != size; i++) {
            cout << array[i] << " ";
        }
        cout << endl << endl;
    }

    void ascendingSort() {
        for(int i = 0; i != size; i++) {
            for(int j = i + 1; j != size; j++) {
                if(array[i] > array[j]) {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }

    int search(int key) {
        for(int i = 0; i != size; i++) {
            if(array[i] == key) {
                return i;
            }
        }
        return -1;
    }
};

void myCredentials(const char *name, const char *course, const char *year, const char *section) {
    cout << "===================================" << endl;
    cout << "Name: " << name << "" << endl;
    cout << "Course: " << course << endl;
    cout << "Year: " << year << endl;
    cout << "Section: " << section << endl;
    cout << "===================================" << endl;
}


int main()
{
    // Declare a QUEUE (implemented by an Array) named Allowances and prompt the user to enter 7 values (in random order) to it using a loop.
    ArrayQueue Allowances(7);

    cout << "Please enter 7 values (in random order). " << endl;
    for(int i = 0; i < 7; i++) {
        int value;
        cout << "[" << i + 1 << "]: ";
        cin >> value;
        Allowances.append(value);
    }
    system("cls");

    // Display the inputted values.
    Allowances.printQueue();

    // Using your preferred sorting algorithm, sort the values in ascending order and display them afterwards.
    Allowances.ascendingSort();
    Allowances.printQueue("Sorted: ");

    // Prompt the user to enter a search key...
    int key = 0;
    cout << "Please enter a value to search in the Queue: ";
    cin >> key;

    // and using your preferred searching algorithm, search for the value 
    int result = Allowances.search(key);

    // and display the result of the process (Successful or Failed).
    if(result == -1) {
        cout << "\nFailed to find " << key << endl << endl;
    }
    else {
        cout << "\nSuccessful! " << key << " found at index [" << result << "]" << endl << endl;
    }

    // Declare and call a function that will display your Name, Course/Year/Section.
    myCredentials("Marc Joshua Valdez", "BS Computer Science", "2nd Year", "C231");

    return 0;
}