#include <iostream>
#include <string>

using namespace std;

class Expression {
public:
    virtual int interpret() = 0;
    virtual ~Expression() = default;
};

class NumberExpression : public Expression {
    int number;
public:
    NumberExpression(int num) : number(num) {}
    int interpret() override {
        return number;
    }
};

class AddExpression : public Expression {
    Expression *left, *right;
public:
    AddExpression(Expression* l, Expression* r) : left(l), right(r) {}
    int interpret() override {
        return left->interpret() + right->interpret();
    }
};

class MultiplyExpression : public Expression {
    Expression *left, *right;
public:
    MultiplyExpression(Expression* l, Expression* r) : left(l), right(r) {}
    int interpret() override {
        return left->interpret() * right->interpret();
    }
};

int main(void) {
    cout << (new MultiplyExpression(new NumberExpression(2), new NumberExpression(3)))->interpret() << endl;
    cout << (new AddExpression(new NumberExpression(2), new NumberExpression(3)))->interpret() << endl;
    return 0;
}