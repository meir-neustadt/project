#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "No expression provided" << std::endl;
        return 1;
    }

    std::string expression = argv[1];
    double result = 0.0;

    // Example: Handle basic arithmetic (simple and naive parsing)
    // You may want to implement a full expression parser
    std::istringstream iss(expression);
    char op;
    double num;

    iss >> result;
    while (iss >> op >> num) {
        switch (op) {
            case '+': result += num; break;
            case '-': result -= num; break;
            case '*': result *= num; break;
            case '/': result /= num; break;
            default:
                std::cerr << "Unsupported operation" << std::endl;
                return 1;
        }
    }

    std::cout << result << std::endl;
    return 0;
}
