// ask the user to enter a SENTENCE in an Array named MyStmt
// it should be able to determine the No. of Words in the sentence and display it

#include <iostream>
#include <cctype>
#include <cstdio>

using namespace std;

int main()
{
    char MyStmt[100] = "";
    int i = 0, word_count = 0;

    cout << "Please Enter a Sentence: ";
    fgets(MyStmt, sizeof(MyStmt), stdin);

    while(MyStmt[i] != '\0')
    {
        if(isspace(MyStmt[i]))
            word_count++;
        i++;
    }

    cout << "No. of word(s) in the sentence: " << word_count << endl;

    return 0;
}