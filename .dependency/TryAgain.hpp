#include <iostream>

bool tryAgain(std::string prompt)
{
    std::string input;
    std::cout << prompt;
    std::cin >> input;

    if(input == "y" || input == "Y") {
        return true;
    }
    else if(input == "n" || input == "N") {
        return false;
    }
    else {
        std::cout << "! Invalid input. Please try again." << std::endl;
        return tryAgain(prompt);
    }
}