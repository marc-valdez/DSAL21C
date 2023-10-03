// ask the user to enter a WORD in an array named MyWord
// the program should be able to count the number of

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char MyWord[20] = "";
    int i = 0;

    cout << "Enter a word: ";
    cin >> MyWord;

    while(MyWord[i] != '\0')
    {
        if(isupper(MyWord[i]))
            MyWord[i] = tolower(MyWord[i]);
        else if(islower(MyWord[i]))
            MyWord[i] = toupper(MyWord[i]);
        i++;
    }

    cout << MyWord << endl;

    return 0;
}