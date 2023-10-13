// Using Arrays, create a complete C++ program that will accept 10 of your classmates’ names and their last semester's GWA. 
// The program should sort the list based on the highest GWA

#include <iostream>
#include <iomanip>
#include "dependency.hpp"
using namespace std;

typedef struct {
    string name;
    float general_weighted_average;
} Student;

#define MAX 3

int main()
{
    Student students[MAX];
    do {
        for(int i = 0; i < MAX; i++) {
            cout << "Please enter your name: ";
            cin >> students[i].name;
            cout << "Please enter your GWA: ";
            cin >> students[i].general_weighted_average;
        }

        // Ascending
        for (int i = 0; i < MAX; i++) {
            for (int j = i + 1; j < MAX; j++) {
                if (students[i].general_weighted_average > students[j].general_weighted_average) {
                    Student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }

        cout << "The sorted list is: " << endl;
        for(int i = 0; i < MAX; i++) {
            cout << students[i].name << " " << fixed << setprecision(2) << students[i].general_weighted_average << endl;
        }
    } while(tryAgain("\nDo you want to try again? (y/n): "));
    return 0;
}