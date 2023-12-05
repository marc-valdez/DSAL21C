#include <iostream>
#include <string>

bool binaryChoice(std::string prompt) {
    std::string input;
    while(true) {
        std::cout << prompt;

        try {
            // Using cin directly to get input
            std::cin >> input;

            // Convert input to lowercase for case-insensitive comparison
            for(char &c : input) {
                c = std::tolower(c);
            }

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
        catch(const std::exception &e) {
            std::cout << "! An error occurred while reading input. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}