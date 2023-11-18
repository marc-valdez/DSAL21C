#include <iostream>
#include <string>

class Double {
private:
    double number;
public:
    Double(double number) {
        this->number = number;
    }
    double getNumber() {
        return number;
    }
    void setNumber(const char *prompt) {
        double newValue;
        std::string buffer;
        while(true) {
            std::cout << prompt;
            try
            {
                std::cin >> buffer;
                newValue = std::stof(buffer);
                break;
            }
            catch(const std::exception &e)
            {
                std::cout << "! Invalid input. Please enter a valid number." << std::endl;
            }
        }
        this->number = newValue;
    }
    void setNumber(const char *prompt, double min, double max) {
        double newValue;
        std::string buffer;
        while(true) {
            std::cout << prompt;
            try
            {
                std::cin >> buffer;
                newValue = std::stof(buffer);

                if(newValue < min || newValue > max) {
                    std::cout << "! Invalid input. Please enter a number between " << min << " and " << max << "." << std::endl;
                    continue;
                }
                break;
            }
            catch(const std::exception &e)
            {
                std::cout << "! Invalid input. Please enter a number." << std::endl;
            }
        }
        this->number = newValue;
    }
};