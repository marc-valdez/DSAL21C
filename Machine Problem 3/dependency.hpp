#include <iostream>
#include <string>
#include <iomanip>

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

// class Float {
//     private:
//         float number;
//     public:
//         Float(float number) {
//             this->number = number;
//         }
//         float getNumber() {
//             return number;
//         }
//         void setNumber(const char *prompt, float min, float max) {
//             float newValue;
//             std::string buffer;
//             while(true) {
//                 std::cout << prompt;
//                 try
//                 {
//                     std::cin >> buffer;
//                     newValue = std::stof(buffer);

//                     if(newValue < min || newValue > max) {
//                         std::cout << "! Invalid input. Please enter a number between " << min << " and " << max << "." << std::endl;
//                         continue;
//                     }
//                     break;
//                 }
//                 catch(const std::exception& e)
//                 {
//                     std::cout << "! Invalid input. Please enter a number." << std::endl;
//                 }
//             }
//             this->number = newValue;
//         }
// };

class GWA {
    private:
        float value;
    public:
        GWA(float value) {
            this->value = value;
        }
        float getGWA() {
            return value;
        }
        void setGWA(const char *prompt, float min, float max) {
            float newValue;
            std::string buffer;
            while(true) {
                std::cout << prompt;
                try
                {
                    std::cin >> buffer;
                    newValue = std::stof(buffer);

                    if(newValue < min || newValue > max) {
                        std::cout << "! Invalid input. Please enter a GWA between " << std::fixed << std::setprecision(2) << min << " and " << max << "." << std::endl;
                        continue;
                    }
                    if(newValue > 3.0 && newValue < 5.0) {
                        std::cout << "! Invalid input. You entered a value between 3.00 and 5.00" << std::endl;
                        continue;
                    }
                    break;
                }
                catch(const std::exception &e)
                {
                    std::cout << "! Invalid input. Please enter a valid value." << std::endl;
                }
            }
            this->value = newValue;
        }
};