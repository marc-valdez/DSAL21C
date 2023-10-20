#include<iostream>
using namespace std;

int main()
{
    int myNum = 5;
    int *p; //p is a pointer, stores an address
    p = &myNum; //p now stores the address of myNum
    cout << "The value of myNum is " << myNum << endl;
    cout << "The address stored in p is " << p << endl;
    cout << "The contents of * p is " << *p << endl;
    return 0;
}