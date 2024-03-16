#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <stdexcept>

class RPN {
public:
    std::stack<size_t> _table;

    void evaluateRPN(const std::string& expr) {
        std::istringstream iss(expr);
        std::string token;
        while (iss >> token) {
            if (is_operation(token[0]) && token.size() == 1) { // Single-char operation
                // Ensure there are at least two operands on the stack
                if (_table.size() < 2) throw std::runtime_error("Insufficient operands.");
                size_t operand2 = _table.top(); _table.pop();
                size_t operand1 = _table.top(); _table.pop();

                size_t result = performOperation(operand1, operand2, token[0]);
                _table.push(result);
            } else { // Number
                size_t val = std::stoi(token); // Directly convert token to integer
                if (val > 10) throw std::runtime_error("Value too high.");
                _table.push(val);
            }
        }

        // Final check for single result on the stack
        if (_table.size() != 1) throw std::runtime_error("Invalid RPN expression.");
        std::cout << "Result: " << _table.top() << std::endl;
    }

private:
    bool is_operation(char c) const {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    size_t performOperation(size_t operand1, size_t operand2, char op) {
        switch (op) {
            case '+': return operand1 + operand2;
            case '-': return operand1 - operand2;
            case '*': return operand1 * operand2;
            case '/': return operand1 / operand2;
            default: throw std::runtime_error("Unknown operation.");
        }
    }
};

int main() {
    RPN calculator;
    std::string expression = "1 1 -2 / 2 1 1 1 - - - 3 3 + -";
    try {
        calculator.evaluateRPN(expression);
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}