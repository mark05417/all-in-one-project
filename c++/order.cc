#include<iostream>
using namespace std;

class A {
public:
    A()  { cout << "A,"; }
    ~A() { cout << "~A,"; }
};

class B {
public:
    B()  { cout << "B,"; }
    ~B() { cout << "~B,"; }
};

class C: public B {
public:
    C()  { cout << "C,"; }
    ~C() { cout << "~C,"; }
};

class D {
public:
    D()  { cout << "D,"; }
    ~D() { cout << "~D,"; }
    C _c;
};

class E: public D {
public:
    E()  { cout << "E,"; 
            _pB = new C; }
    ~E() { cout << "~E,"; 
            delete _pB; }
    A  a;
    B* _pB;
};

// int main() {
//     E e;
// }

class base {
public:
    void func1() 
      { printf( "bf1," );
        func2(); }
    virtual void func2() 
      { printf( "bf2," ); }
};

class son1 : public base {
public:
    void func1() 
      { printf( "sf1," );
        func2(); }
    virtual void func2() 
      { printf( "sf2," ); }
};

int main()
{
    // E e;
    B* _pB = new C;
    // base* pb1 = new base;
    // base* pb2 = (base*) new son1;
    // son1* ps = (son1*)pb1;
    // pb1->func1();
    // pb2->func1();
    // ps->func1();
    // delete pb1;
    // delete pb2;
    // return 0;
}
