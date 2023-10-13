// Using Arrays, create a complete C++ program that will accept 10 of your classmates’ names and their last semester's GWA. 
// The program should sort the list based on the highest GWA

#include <iostream>
#include <iomanip>
#include "dependency.hpp"
using namespace std;

typedef struct {
    string name;
    GWA gwa = GWA(0.0);
} Student;

#define MAX 3

int main()
{
    Student students[MAX];
    do {
        for(int i = 0; i < MAX; i++) {
            cout << "Please enter your name: ";
            cin >> students[i].name;
            students[i].gwa.setGWA("Please enter your GWA: ", 1.0, 5.0);
        }

        // Ascending Sort
        for (int i = 0; i < MAX; i++) {
            for (int j = i + 1; j < MAX; j++) {
                if(students[i].gwa.getGWA() > students[j].gwa.getGWA()) {
                    Student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }

        cout << "\nThe sorted list is: \n\n";
        for(int i = 0; i < MAX; i++) {
            cout << students[i].name << "\t: " << fixed << setprecision(2) << students[i].gwa.getGWA() << endl;
        }
    } while(tryAgain("\nDo you want to try again? (y/n): "));
    return 0;
}