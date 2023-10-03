// ask the user to enter WORD in an array named MyWord
// check if the word is a palindrome or not
// display an appropriate message for each condition

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    char MyWord[20] = "";
    char MyWordReversed[20] = "";
    bool isPalindrome = false;

    cout << "Please Enter a Word: ";
    cin >> MyWord;

    for(int i = 0; MyWord[i] != '\0'; i++)
        MyWord[i] = tolower(MyWord[i]);

    int j = 0;
    for(int i = strlen(MyWord) - 1; MyWord[i] != '\0'; i--, j++)
        MyWordReversed[j] = MyWord[i];
    MyWordReversed[j+1] = '\0';

    if(strcmp(MyWord, MyWordReversed) == 0)
        isPalindrome = true;

    if(isPalindrome)
        cout << "The word is a palindrome." << endl;
    else
        cout << "The word is not a palindrome." << endl;

    return 0;
}