#include <string>
#include <iostream>
using namespace std;

class Base {
public:
    int x;
    static int shared;
    Base() : x(3) {}
    virtual ~Base() {}
// protected:
};
int Base::shared = 100;
class Derived : public Base {
public:
    Derived() : Base() {}
    virtual ~Derived() {}
};

void func() {
    // printf("hello\n");
    // Derived *dp = new Derived;
    // Base *bp = dp; // 可以

    // Base *bp = new Base;
    // Derived *dp = bp; // 不行

    // Base *bp = new Derived;
    // Derived *dp = bp; // 不行
    // Derived *dp = dynamic_cast<Derived*>(bp);  // 嘗試向下轉型

    // Derived *dp = new Base; // 不行
}

void func2() {
    Base *bp = new Derived;
    std::cout << bp->x << std::endl;
}

void func3() {
    Base a, b;
    Derived c, d;
    a.shared = 1; std::cout << a.shared << std::endl;
    b.shared = 2; std::cout << a.shared << std::endl;
    c.shared = 3; std::cout << a.shared << std::endl;
    d.shared = 4; std::cout << a.shared << std::endl;
}
int main() {
    func();
}