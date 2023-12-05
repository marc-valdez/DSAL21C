// Create a complete C++ program that allows user to input a series of integers locate a specific integer in the series. 
// Apply the logical concepts involved in the following searching algorithms: 
// Sequential Search
// Binary Search

#include <iostream>
#include "Number.hpp"
#include "BinaryChoice.hpp"

using namespace std;

#define MAX 5

short sequential_search(Number integers[], int target) {
    short iterations = 1;
    for(int i = 0; i <= MAX; i++) {
        if(i == MAX) {
            cout << "! Failure, Integer not found." << endl;
            break;
        }
        if(integers[i].getNumber() == target) {
            cout << "! Success, Integer found at index " << i << endl;
            break;
        }
        iterations++;
    }
    return iterations;
}

short binary_search(Number integers[], int target) {
    short iterations = 1, low = 0, high = MAX - 1, mid;
    while(true) {
        if(low > high) {
            cout << "! Failure, Integer not found." << endl;
            break;
        }

        mid = low + (high - low) / 2;

        if(integers[mid].getNumber() == target) {
            cout << "! Success, Integer found at index " << mid << endl;
            break;
        }
        else if(integers[mid].getNumber() < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
        iterations++;
    }
    return iterations;
}

int main() {
    do {
        Number integers[MAX];

        cout << "Please enter five integers.\n";
        for(int i = 0; i < MAX; i++) {
            string prompt = "Integer " + to_string(i + 1) + ": ";
            integers[i].setNumber(prompt.c_str());
        }

        system("cls");
        Number target;
        target.setNumber("Please enter an integer to find: ");

        // Using Sequential Search
        cout << "Sequential search took " << sequential_search(integers, target.getNumber()) << " iterations." << endl << endl;

        // Using Binary Search
        cout << "Binary search took " << binary_search(integers, target.getNumber()) << " iterations." << endl;
    } while(binaryChoice("Would you like to continue? (y/n): "));
    return 0;
}