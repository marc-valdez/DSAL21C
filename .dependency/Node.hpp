#include <iostream>

class Node {
private:
    double value;
public:
    struct Node *next;

    Node(double newValue) {
        this->value = newValue;
        this->next = nullptr;
    }
    double getValue() {
        return value;
    }
    void setValue(double newValue) {
        this->value = newValue;
    }
    
    void traverse() {
        Node* temp = this;
        while(temp != nullptr) {
            std::cout << temp->value << " -> ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};