#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct Compute {
        double numbers[5];
        double sum;
        double product;
        double average;
    };

    Compute problem = {{0, 0, 0, 0, 0}, 0, 1, 0.0};

    cout << "Please enter 5 numbers (ex: 1 2 3 4 5): ";
    cin >> problem.numbers[0] >> problem.numbers[1] >> problem.numbers[2] >> problem.numbers[3] >> problem.numbers[4];

    for(int i = 0; i < 5; i++)
    {
        problem.sum += problem.numbers[i];
        problem.product *= problem.numbers[i];
    }
    problem.average = problem.sum / 5;

    cout << "------------------------------------------------------------" << endl;
    cout << "Sum: " << problem.sum << endl;
    cout << "Product: " << problem.product << endl;
    cout << "Average: " << problem.average << endl;

    return 0;
}