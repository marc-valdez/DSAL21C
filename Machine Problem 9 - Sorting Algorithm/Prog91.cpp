// Create a complete C++ program that allows user to input a series of integers 
// and arrange these in ascending and descending order 
// applying the logical concepts involved in the following sorting algorithms :

// Bubble Sort Algorithm
// Insertion Sort Algorithm
// Selection Sort Algorithm

#include <iostream>
#include "Number.hpp"
#include "BinaryChoice.hpp"

using namespace std;

#define MAX 5

void printArray(Number integers[], int n) {
    for(int i = 0; i < n; i++) {
        cout << integers[i].getNumber() << " ";
    }
    cout << endl;
};

short bubbleSort(Number integers[], int n) {
    short iterations = 0;
    bool swapped;
    for(int i = 0; i < n; i++) {
        swapped = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(integers[j].getNumber() > integers[j + 1].getNumber()) {
                Number temp = integers[j];
                integers[j] = integers[j + 1];
                integers[j + 1] = temp;
                swapped = true;
            }
            iterations++;
        }
        if(!swapped) { break; }
    }
    printArray(integers, n);
    return iterations;
}

short insertionSort(Number integers[], int n) {
    short iterations = 0;
    for(int i = 1; i < n; i++) {
        Number temp = integers[i];
        int j = i - 1;
        while(j >= 0 && integers[j].getNumber() > temp.getNumber()) {
            integers[j + 1] = integers[j];
            j--;
        }
        integers[j + 1] = temp;
        iterations++;
    }
    printArray(integers, n);
    return iterations;
}

short selectionSort(Number integers[], int n) {
    short iterations = 0;
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(integers[j].getNumber() < integers[minIndex].getNumber()) {
                minIndex = j;
            }
            iterations++;
        }
        Number temp = integers[minIndex];
        integers[minIndex] = integers[i];
        integers[i] = temp;
    }
    printArray(integers, n);
    return iterations;
}

int main() {
    do {
        Number integers[MAX];

        cout << "Please enter five random integers out of order.\n";
        for(int i = 0; i < MAX; i++) {
            string prompt = "Integer " + to_string(i + 1) + ": ";
            integers[i].setNumber(prompt.c_str());
        }

        system("cls");
        cout << "Unsorted Array: ";
        printArray(integers, MAX);
        cout << endl;

        // Using Bubble Sort
        cout << "Bubble Sort took " << bubbleSort(integers, MAX) << " iterations." << endl << endl;

        // Using Insertion Sort
        cout << "Insertion Sort took " << insertionSort(integers, MAX) << " iterations." << endl << endl;

        // Using Selection Sort
        cout << "Selection Sort took " << selectionSort(integers, MAX) << " iterations." << endl;
    } while(binaryChoice("Would you like to continue? (y/n): "));
    return 0;
}