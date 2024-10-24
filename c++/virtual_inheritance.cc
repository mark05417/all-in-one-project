#include <iostream>
#include <string>

using namespace std;

class A{
public:
    A(const string& id = "foo") : pid(id) {}
    string pid;
};

class B : public virtual A {};

class C : public B{
public:
    C(const string& id) : A(id){}
};

class D : public C{
public:
    D(const string& id) : C(id){}
};


int main() {
    cout << C("bar").pid << endl; // bar，先初始化虛擬部分 A，這時候 A(id) 有正確帶入 bar
    cout << D("bar").pid << endl; // foo，先初始化虛擬部分 A，這時候用 A 的 default constructor，後續不會初始化 A 第二次
    return 0;
}