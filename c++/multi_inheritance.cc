#include <iostream>

using namespace std;

class Base1{
public:
    Base1(){cout<<"Construct base1\n";}
    virtual void f1(){cout<<"base1\n";};
    ~Base1(){cout<<"Destruct base1\n";}
};
class Base2{
public:
    Base2(){cout<<"Construct base2\n";}
    virtual void f2(){cout<<"base2\n";};
    ~Base2(){cout<<"Destruct base2\n";}
};
class Derived: public Base1, public Base2{
public:
    Derived(){cout<<"Construct derived\n";}
    void f1(){cout<<"derivedf1\n";};
    void f2(){cout<<"derivedf2\n";};
    ~Derived(){cout<<"Destruct derived\n";}
};

int main(){
    Base1 *pB1 = new Derived();
    // Construct base1
    // Construct base2
    // Construct derived

    Derived *pD = dynamic_cast<Derived*>(pB1); // 成功
    Base2 *pB2 = dynamic_cast<Base2*>(pB1); // 成功

    pB1->f1();    // derivedf1
    pB2->f2();    // derivedf2
    pD->f1();    // derivedf1
    pD->f2();    // derivedf2

    delete pD;
    // Construct derived
    // Construct base2
    // Construct base1
    return 0;
}