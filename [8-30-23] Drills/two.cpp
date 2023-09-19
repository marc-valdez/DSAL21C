/******************************************************************************
Program 2
*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    char legend[5][50] = {
        "Student Name",
        "Student ID",
        "Course",
        "Year Level",
        "Section"
    };

    char student_information[5][50] = {
        "Marc Joshua Valdez",
        "2022-1-01130",
        "BS Computer Science",
        "2nd Year",
        "C231"
    };

    for(int i = 0; i < 5; i++) {
        cout << legend[i] << "\t|";
    }

    cout << endl;

    for(int i = 0; i < 5; i++) {
        cout << student_information[i] << "\t|";
    }

    return 0;
}