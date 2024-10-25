#include <iostream>
#include <string>
#include <stdexcept>

class Parser {
public:
    explicit Parser(const std::string &input) : input_(input), pos_(0) {}

    int parse() {
        int result = expression();
        if (pos_ < input_.length()) {
            throw std::runtime_error("Unexpected character at the end of expression");
        }
        return result;
    }

private:
    std::string input_;
    size_t pos_;

    char peek() const {
        if (pos_ < input_.length()) {
            return input_[pos_];
        }
        return '\0';
    }

    char get() {
        return input_[pos_++];
    }

    int expression() {
        int result = term();
        while (peek() == '+' || peek() == '-') {
            char op = get();
            int rhs = term();
            if (op == '+') {
                result += rhs;
            } else {
                result -= rhs;
            }
        }
        return result;
    }

    int term() {
        int result = factor();
        while (peek() == '*' || peek() == '/') {
            char op = get();
            int rhs = factor();
            if (op == '*') {
                result *= rhs;
            } else {
                result /= rhs;
            }
        }
        return result;
    }

    int factor() {
        if (peek() >= '0' && peek() <= '9') {
            return number();
        } else if (peek() == '(') {
            get(); // consume '('
            int result = expression();
            if (get() != ')') {
                throw std::runtime_error("Mismatched parentheses");
            }
            return result;
        } else {
            throw std::runtime_error("Unexpected character");
        }
    }

    int number() {
        int result = 0;
        while (peek() >= '0' && peek() <= '9') {
            result = result * 10 + (get() - '0');
        }
        return result;
    }
};

int main() {
    std::string expression;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    try {
        Parser parser(expression);
        int result = parser.parse();
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
