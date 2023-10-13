// Prompt the user to enter Student's Record with data requirements as follow:
// Student's Name (LN, FN, MI.)
// Course (Ex. BSCS)
// Year (Ex. 2)
// Section (Ex. A)
// Final Grade (Ex. 75)
// Check the Final Grade and display the Grade Point Equivalent and General Description based on the table provided.

#include <iostream>
using namespace std;

int main()
{
    string last_name = "", first_name = "", course = "", section = "", general_description = "";
    char middle_initial = '\0';
    int year = 0;
    double final_grade = 0.0, grade_point_equivalent = 0.0;


    cout << "Please enter your Student Name: \n";
    cout << "Last Name: ";
    cin >> last_name;

    cout << "First Name: ";
    cin >> first_name;

    cout << "Middle Initial (ex. A): ";
    cin >> middle_initial;

    cout << "Please enter your Course (ex: BSCS): ";
    cin >> course;

    cout << "Please enter your Year Level (ex. 2): ";
    cin >> year;

    cout << "Please enter your Section (ex. A): ";
    cin >> section;

    cout << "Please enter your Final Grade (ex. 75): ";
    cin >> final_grade;

    if(final_grade >= 99)
    {
        grade_point_equivalent = 1.0;
        general_description = "Excellent";
    }
    else if(final_grade >= 96)
    {
        grade_point_equivalent = 1.25;
        general_description = "Outstanding";
    }
    else if(final_grade >= 93)
    {
        grade_point_equivalent = 1.50;
        general_description = "Superior";
    }
    else if(final_grade >= 90)
    {
        grade_point_equivalent = 1.75;
        general_description = "Very Good";
    }
    else if(final_grade >= 87)
    {
        grade_point_equivalent = 2.00;
        general_description = "Good";
    }
    else if(final_grade >= 84)
    {
        grade_point_equivalent = 2.25;
        general_description = "Satisfactory";
    }
    else if(final_grade >= 81)
    {
        grade_point_equivalent = 2.50;
        general_description = "Fairly Satisfactory";
    }
    else if(final_grade >= 78)
    {
        grade_point_equivalent = 2.75;
        general_description = "Fair";
    }
    else if(final_grade >= 75)
    {
        grade_point_equivalent = 3.0;
        general_description = "Passed";
    }
    else
    {
        grade_point_equivalent = 5.0;
        general_description = "Failed";
    }

    cout << "\nYour Grade Point Equivalent is: " << grade_point_equivalent << " = " << general_description << endl;

    return 0;
}