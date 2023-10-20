#include <iostream>
using namespace std;
int main()
{
    char myLet = 'A';
    char *Let; //Let is a pointer variable
    Let = &myLet; //Let stores the address of myLet
    cout << "The content of myLet is " << myLet << endl;
    //the value of Let ... the address stored in it.
    cout << Let << " is the value of Let." << endl;
    //the value Let "points to"
    cout << *Let << " is stored at " << Let << endl;
    //the address of Let itself
    cout << &Let << " is the address of Let." << endl;
    return 0;
}