#include <iostream>
#include <string>

bool tryAgain(std::string prompt)
{
    std::string input;
    std::cout << prompt;
    std::cin >> input;

    if(input == "y" || input == "Y") {
        return true;
    }
    else if(input == "n" || input == "N") {
        return false;
    }
    else {
        std::cout << "! Invalid input. Please try again." << std::endl;
        return tryAgain(prompt);
    }
}

// class Node {
// private:
//     double value;
//     struct Node *next;
// public:
//     Node(double newValue) {
//         this->value = newValue;
//         this->next = nullptr;
//     }
//     double getValue() {
//         return value;
//     }
//     void setValue(double newValue) {
//         this->value = newValue;
//     }
//     Node *getNext() {
//         return next;
//     }
//     void setNext(Node *newNext) {
//         this->next = newNext;
//     }
// };

// class Queue {
// private:
//     Node *head;
//     Node *tail;
//     int size;
// public:
//     Queue(int newSize) {
//         head = nullptr;
//         tail = nullptr;
//         size = newSize;
//     }
//     void append(double newValue) {
//         Node *newNode = new Node(newValue);

//         if(head == nullptr) {
//             head = newNode;
//             tail = newNode;
//         }
//         else {
//             tail->setNext(newNode);
//             tail = newNode;
//         }
//         size++;
//     }
//     int getSize() {
//         return size;
//     }
//     Node *getHead() {
//         return head;
//     }
//     Node *getTail() {
//         return tail;
//     }
//     void setHead(Node *newHead) {
//         head = newHead;
//     }
// };

class Double {
private:
    double number;
public:
    Double(double number) {
        this->number = number;
    }
    double getNumber() {
        return number;
    }
    void setNumber(const char *prompt) {
        double newValue;
        std::string buffer;
        while(true) {
            std::cout << prompt;
            try
            {
                std::cin >> buffer;
                newValue = std::stof(buffer);
                break;
            }
            catch(const std::exception &e)
            {
                std::cout << "! Invalid input. Please enter a valid number." << std::endl;
            }
        }
        this->number = newValue;
    }
    void setNumber(const char *prompt, double min, double max) {
        double newValue;
        std::string buffer;
        while(true) {
            std::cout << prompt;
            try
            {
                std::cin >> buffer;
                newValue = std::stof(buffer);

                if(newValue < min || newValue > max) {
                    std::cout << "! Invalid input. Please enter a number between " << min << " and " << max << "." << std::endl;
                    continue;
                }
                break;
            }
            catch(const std::exception &e)
            {
                std::cout << "! Invalid input. Please enter a number." << std::endl;
            }
        }
        this->number = newValue;
    }
};