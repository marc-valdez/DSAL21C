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

class Stack {
private:
    int size;
    int top;
    double *stack;
public:
    Stack(int size) {
        this->size = size;
        top = -1;
        stack = new double[size];
    }
    void push(double value) {
        if(top == size - 1) {
            std::cout << "! Stack is full." << std::endl;
            return;
        }
        top++;
        stack[top] = value;
    }
    void pop() {
        if(top == -1) {
            std::cout << "! Stack is empty." << std::endl;
            return;
        }
        top--;
        std::cout << "An element from the stack has been deleted!" << std::endl;
    }
    double peek() {
        if(top == -1) {
            std::cout << "! Stack is empty." << std::endl;
            return -1;
        }
        return stack[top];
    }
    void showStack() {
        if(top == -1) {
            std::cout << "! Stack is empty." << std::endl;
            return;
        }
        for(int i = top; i >= 0; i--) {
            std::cout << "[" << i << "] " << stack[i] << std::endl;
        }
    }
};

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