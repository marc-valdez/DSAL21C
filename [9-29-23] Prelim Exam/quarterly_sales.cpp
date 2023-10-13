#include <iostream>
using namespace std;

int main()
{
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    double quarter1[3] = {0.0, 0.0, 0.0};
    double quarter2[3] = {0.0, 0.0, 0.0};
    double quarter3[3] = {0.0, 0.0, 0.0};
    double quarter4[3] = {0.0, 0.0, 0.0};
    double q1_sales_total = 0.0, q2_sales_total = 0.0, q3_sales_total = 0.0, q4_sales_total = 0.0;

    cout << "Please enter Monthly Sales(for 1 year) : \n";
    cout << "January: ";
    cin >> quarter1[0];
    cout << "February: ";
    cin >> quarter1[1];
    cout << "March: ";
    cin >> quarter1[2];
    cout << "April: ";
    cin >> quarter2[0];
    cout << "May: ";
    cin >> quarter2[1];
    cout << "June: ";
    cin >> quarter2[2];
    cout << "July: ";
    cin >> quarter3[0];
    cout << "August: ";
    cin >> quarter3[1];
    cout << "September: ";
    cin >> quarter3[2];
    cout << "October: ";
    cin >> quarter4[0];
    cout << "November: ";
    cin >> quarter4[1];
    cout << "December: ";
    cin >> quarter4[2];

    q1_sales_total = quarter1[0] + quarter1[1] + quarter1[2];
    q2_sales_total = quarter2[0] + quarter2[1] + quarter2[2];
    q3_sales_total = quarter3[0] + quarter3[1] + quarter3[2];
    q4_sales_total = quarter4[0] + quarter4[1] + quarter4[2];

    cout << "Quarter 1 | " << q1_sales_total << endl;
    cout << "Quarter 2 | " << q2_sales_total << endl;
    cout << "Quarter 3 | " << q3_sales_total << endl;
    cout << "Quarter 4 | " << q4_sales_total << endl;

    return 0;
}