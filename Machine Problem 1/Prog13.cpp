// Create a complete C++ program will compute for the bonus of an employee. 
// Consider the following conditions: If the employee’s monthly salary is less than 15,000 pesos, the bonus is 25% of the salary; 
// for employees with salaries greater than or equal to 15,000 pesos, the bonus is 5,500 pesos. 
// Print the name and the corresponding bonus for each employee.

#include <iostream>
using namespace std;

int main()
{
    float salary = 0.0, bonus = 0.0;
    string name = "";
    cout << "Good day employee!\nPlease enter your name: ";
    cin >> name;

    cout << "Please enter your monthly salary: ";
    cin >> salary;

    salary < 15000 ? bonus = salary * 0.25 : bonus = 5500.0;

    cout << "Your name is: " << name << endl;
    cout << "Your bonus is: PHP " << bonus << endl;

    return 0;
}