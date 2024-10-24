#include <iostream>
#include <memory>

class B;

class A {
public:
    std::shared_ptr<B> ptrB;
    ~A() { std::cout << "A destroyed\n"; }
};

class B {
public:
    std::shared_ptr<A> ptrA;
    ~B() { std::cout << "B destroyed\n"; }
};

void func() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->ptrB = b;
    b->ptrA = a;
}

int main() {
    func();
    return 0;
}