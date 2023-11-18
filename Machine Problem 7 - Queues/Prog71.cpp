// Create a complete C++ Program that will simulate the ENQUEUE, DEQUEUE, and PEEK Operations. Also, add a menu for displaying the state of your QUEUE.

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node *next;
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
    };

    bool isFull() {
        return size >= maxSize;
    }

    bool enqueue(int newValue) {
        if(isFull()) {
            cout << "! Queue overflow. Cannot append further." << endl;
            return false;
        }

        Node *newNode = new Node();
        newNode->data = newValue;
        newNode->next = nullptr;

        if(isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;

        return true;
    }

    bool dequeue(int &item) {
        if(isEmpty()) {
            cout << "! Queue underflow. Cannot delete further." << endl;
            return false;
        }

        Node *temp = head;
        head = head->next;

        item = temp->data;

        delete temp;
        size--;

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

        if(isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node *temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        delete temp;
    }
};

class Menu {
public:
    short choice;
    string titleText;

    Menu(string newTitleText = "") {
        choice = 0;
        titleText = newTitleText;
    }

    void displayMenu() {
        system("cls");

        cout << titleText << endl;
        cout << "[1] ENQUEUE" << endl;
        cout << "[2] DEQUEUE" << endl;
        cout << "[3] PEEK" << endl;
        cout << "[4] DISPLAY" << endl;
        cout << "[5] EXIT" << endl;
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

            if(choice >= 1 && choice <= 5)
                return choice;
            else {
                cout << "! Please enter a number between 1 and 5. ";
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

    Menu menu("This is a Queue Simulation Program!");

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