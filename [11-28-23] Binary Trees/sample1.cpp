#include <iostream>

using namespace std;

class Node {
public:
    Node *left;
    Node *right;
    int data;

    Node(int newData) {
        data = newData;
        left = NULL;
        right = NULL;
    }

    void insert(int newData) {
        if(newData <= data) {
            if(left == NULL) {
                left = new Node(newData);
            }
            else {
                left->insert(newData);
            }
        }
        else {
            if(right == NULL) {
                right = new Node(newData);
            }
            else {
                right->insert(newData);
            }
        }
    }

    bool contains(int value) {
        if(value == data) {
            return true;
        }
        else if(value < data) {
            if(left == NULL) {
                return false;
            }
            else {
                return left->contains(value);
            }
        }
        else {
            if(right == NULL) {
                return false;
            }
            else {
                return right->contains(value);
            }
        }
    }

    void printInOrder() {
        if(left != NULL) {
            left->printInOrder();
        }
        cout << data << " ";
        if(right != NULL) {
            right->printInOrder();
        }
    }
};

int main()
{
    Node *root = new Node(5);
    root->insert(3);
    root->insert(8);
    root->insert(2);
    root->insert(4);
    root->insert(6);
    root->insert(9);

    root->printInOrder();
    return 0;
}