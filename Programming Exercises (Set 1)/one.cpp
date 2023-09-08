#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct Grades {
        float prelim_grade;
        float midterm_grade;
        float final_grade;
    };

    struct Student {
        string name;
        string student_number;
        string course;
        string year_level;
        string section;
        Grades grade;
    };

    Student student1;

    cout << "Please enter your name: ";
    cin >> student1.name;

    cout << "Please enter your student number: ";
    cin >> student1.student_number;

    cout << "Please enter your course: ";
    cin >> student1.course;

    cout << "Please enter your year level: ";
    cin >> student1.year_level;

    cout << "Please enter your section: ";
    cin >> student1.section;

    cout << "Please enter your prelim grade: ";
    cin >> student1.grade.prelim_grade;

    cout << "Please enter your midterm grade: ";
    cin >> student1.grade.midterm_grade;

    cout << "Please enter your final grade: ";
    cin >> student1.grade.final_grade;

    cout << "\n----------------------------------------------------------------" << endl;
    cout << "You have entered the following information: " << endl;
    cout << "Student name: " << student1.name << endl;
    cout << "Student number: " << student1.student_number << endl;
    cout << "Course: " << student1.course << endl;
    cout << "Year level: " << student1.year_level << endl;
    cout << "Section: " << student1.section << endl;
    cout << "Prelim grade: " << student1.grade.prelim_grade << endl;
    cout << "Midterm grade: " << student1.grade.midterm_grade << endl;
    cout << "Final grade: " << student1.grade.final_grade << endl;
    cout << "----------------------------------------------------------------\n" << endl;

    float average = (student1.grade.prelim_grade + student1.grade.midterm_grade + student1.grade.final_grade) / 3;
    printf("Your average grade is %.2f\n", average);

    return 0;
}