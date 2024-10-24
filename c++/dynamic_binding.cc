#include <iostream>
using namespace std;

class A {
public:
    virtual void f(int n = 7) {
        cout << "A" << " " << n << endl;
    };
};
class B : public A {
public:
    void f(int n = 9) {
        cout << "B" << " " << n << endl;
    };
};

int main() {
    A *pa = new A, *pb = new B;
    B *pc = new B;
    pa->f(); // A 7
    pb->f(); // B 7
    pc->f(); // B 9
}