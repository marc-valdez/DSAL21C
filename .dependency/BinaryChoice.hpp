#include <iostream>
#include <string>

bool binaryChoice(std::string prompt)
{
    std::string input;

    while(true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        for(int i = 0; i < input.size(); i++)
            input[i] = tolower(input[i]);

        if(input == "y" || input == "yes" || input == "1") {
            return true;
        }
        else if(input == "n" || input == "no" || input == "0") {
            return false;
        }
        else {
            std::cout << "! Invalid input. Please try again." << std::endl;
        }
    }
}