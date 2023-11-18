// Create a complete C++ Program that will simulate the ENQUEUE, DEQUEUE, and PEEK Operations. Also, add a menu for displaying the state of your QUEUE.

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int newData) {
        data = newData;
        next = nullptr;
    }
};

class Queue {
public:
    Node *head;
    Node *tail;
    int size;
    int maxSize;

    Queue(int newMax) {
        head = NULL;
        tail = NULL;
        size = 0;
        maxSize = newMax;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    bool isFull() {
        return size >= maxSize;
    }

    bool enqueue(int newValue) {
        // Check if the queue is full.
        if(isFull()) {
            cout << "! Queue overflow. Cannot append further." << endl;
            // Return false to stop further execution.
            return false;
        }

        // Create a new node, with the given value.
        Node *newNode = new Node(newValue);

        // Check if the new node was successfully created.
        if(newNode == nullptr) {
            cout << "! Out of memory." << endl;
            // Exit the program with an error code.
            exit(1);
        }

        // If the queue is empty, set head to the new node.
        if(isEmpty()) {
            head = newNode;
        }
        // Otherwise, set the next pointer of the current tail to the new node.
        else {
            tail->next = newNode;
        }

        // Update the tail to point to the new node.
        tail = newNode;

        // Increase the size of the queue.
        size++;

        // Return true to indicate success.
        return true;
    }

    bool dequeue(int &item) {
        // Check if the queue is empty.
        if(isEmpty()) {
            cout << "! Queue underflow. Cannot delete further." << endl;
            // Return false to stop further execution.
            return false;
        }

        // Create a temporary pointer to store the head pointer.
        Node *temp = head;

        // Optional: Grab the data from temp before deletion.
        item = temp->data;

        // Shift the head pointer to the next node.
        head = head->next;

        // If the head pointer is NULL, it means we've reached the end of the list.
        if(head == nullptr) {
            tail = nullptr;
        }

        // Free the temporary pointer.
        delete temp;

        // Reduce the size of the queue.
        size--;

        // Return true to indicate success.
        return true;
    }

    string peek() {
        if(isEmpty()) {
            return "Queue is empty.";
        }
        return to_string(head->data) + " is at the front of the queue.";
    }

    void printQueue(string flavorText = "Queue: ") {
        cout << flavorText;

        // Check if the queue is empty.
        if(isEmpty()) {
            cout << "Queue is empty." << endl;
            // Return early to avoid further execution.
            return;
        }

        // Create a temporary pointer to traverse the queue.
        Node *temp = head;

        // Traverse the queue and print each node's data.
        // Once nullptr is reached, we've reached the end of the queue.
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;

        // Free the temporary pointer.
        delete temp;
    }
};

class Menu {
public:
    short choice;
    short min, max;
    string titleText;
    string *choices;

    Menu(string newTitleText = "", string *newChoices = nullptr) {
        choice = 0;
        min = 1;

        for(int i = 0; newChoices[i] != "\0"; i++)
            max = i + 1;

        titleText = newTitleText;
        choices = newChoices;
    }

    void displayMenu() {
        system("cls");

        cout << titleText << endl;
        for(int i = 0; i < max; i++) {
            cout << "[" << i + 1 << "] " << choices[i] << endl;
        }

        cout << "Enter your choice: ";
    }

    short getChoice() {
        while(true)
        {
            displayMenu();
            string input;

            try {
                getline(cin, input);
                choice = stoi(input);
            }
            catch(const std::exception &) {
                cout << "! Invalid input. ";
                system("pause");
                continue;
            }

            if(choice >= min && choice <= max)
                return choice;
            else {
                printf("! Please enter a number between %d and %d. ", min, max);
                system("pause");
                continue;
            }
        }
    }
};

class Number {
public:
    double value;

    Number(double newValue) {
        value = newValue;
    }

    void setValue(string prompt) {
        while(true)
        {
            cout << prompt;
            string input;
            try {
                getline(cin, input);
                value = stod(input);
                break;
            }
            catch(const std::exception &) {
                cout << "! Invalid input. ";
                system("pause");
                continue;
            }
        }
    }
};

bool binaryChoice(std::string prompt)
{
    std::string input;
    std::cout << prompt;

    std::getline(std::cin, input);

    for(int i = 0; i < input.size(); i++)
        input[i] = tolower(input[i]);

    while(true) {
        if(input == "y" || input == "yes" || input == "1") {
            return true;
        }
        else if(input == "n" || input == "no" || input == "0") {
            return false;
        }
        else {
            std::cout << "! Invalid input. Please try again." << std::endl;
            std::cout << prompt;
            std::getline(std::cin, input);
        }
    }
}

int main() {
    Queue q(5);

    string choices[6] = {
        "ENQUEUE",
        "DEQUEUE",
        "PEEK",
        "DISPLAY",
        "EXIT",
        "\0"
    };
    Menu menu("This is a Queue Simulation Program!", choices);

    do
    {
        switch(menu.getChoice())
        {
            case 1:
            {
                system("cls");

                Number count(0);
                string prompt = "ENQUEUE\nHow many elements do you wish to add? (max: " + to_string(q.maxSize - q.size) + ") >> ";
                count.setValue(prompt);

                for(int i = 0; i < count.value; i++)
                {
                    Number num(0);
                    string prompt = "Enter element " + to_string(i + 1) + " >> ";
                    num.setValue(prompt);
                    if(!q.enqueue(num.value))
                        break;
                }
                break;
            }
            case 2:
            {
                system("cls");

                Number count(0);
                string prompt = "DEQUEUE\nHow many elements do you wish to remove? (max: " + to_string(q.size) + ") >> ";
                count.setValue(prompt);

                Queue served(count.value);
                for(int i = 0; i < count.value; i++)
                {
                    int temp;
                    if(!q.dequeue(temp))
                        break;
                    served.enqueue(temp);
                }
                served.printQueue("Served Items: ");
                q.printQueue("Remaining Items: ");
                break;
            }
            case 3:
            {
                system("cls");
                cout << "PEEK" << endl;
                cout << "Head: " << q.peek() << endl;
                break;
            }
            case 4:
            {
                system("cls");
                q.printQueue("DISPLAY\n");
                break;
            }
            case 5:
            {
                system("cls");
                cout << "EXIT" << endl;
                if(binaryChoice("Are you sure you want to exit? (y/n) >> "))
                    return 0;
                else
                    continue;
            }
        }
    } while(binaryChoice("Do you want to try again? (y/n) >> "));

    return 0;
}