#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Expression {
public:
    virtual int interpret() = 0;
    virtual ~Expression() = default;
};

class Number : public Expression {
    int number;
public:
    Number(int num) : number(num) {}
    int interpret() override {
        return number;
    }
};

class Add : public Expression {
    Expression *left, *right;
public:
    Add(Expression* l, Expression* r) : left(l), right(r) {}
    int interpret() override {
        return left->interpret() + right->interpret();
    }
};


int main(void) {
    // std::string input = "4 + 3";

    Expression* left = new Number(4);
    Expression* right = new Number(3);
    Expression* add = new Add(left, right);
    std::cout << add->interpret() << std::endl;
    delete left;
    delete right;
    delete add;
    return 0;
}