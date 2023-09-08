#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct Employee {
        string employee_number;
        string first_name;
        char middle_initial;
        string last_name;
        string date_hired;
        float rate;
        int hours_worked;
        float gross_pay;
        float net_pay;
    };

    Employee employee1;
    
    cout << "Please enter your employee number (ex: 123-4567A): ";
    cin >> employee1.employee_number;

    cout << "Please enter your name (First MI Last): ";
    cin >> employee1.first_name >> employee1.middle_initial >> employee1.last_name;

    cout << "Please enter your date of hire (MM/DD/YYYY): ";
    cin >> employee1.date_hired;

    cout << "Please enter your hourly rate ($): ";
    cin >> employee1.rate;

    cout << "Please enter your number of hours worked (ex: 40): ";
    cin >> employee1.hours_worked;

    employee1.gross_pay = employee1.hours_worked * employee1.rate;
    employee1.net_pay = employee1.gross_pay - (employee1.gross_pay * 0.1);

    cout << "\n----------------------------------------------------------------" << endl;
    cout << "You have entered the following information: " << endl;
    cout << "Employee number: " << employee1.employee_number << endl;
    cout << "Name: " << employee1.first_name << employee1.middle_initial << employee1.last_name << endl;
    cout << "Date of hire: " << employee1.date_hired << endl;
    cout << "Hourly rate: " << employee1.rate << endl;
    cout << "Number of hours worked: " << employee1.hours_worked << endl;
    cout << "----------------------------------------------------------------\n" << endl;

    cout << "Your calculated Gross pay is: $" << employee1.gross_pay << endl;
    cout << "Your calculated Net pay is: $" << employee1.net_pay << endl;
    
    return 0;
}