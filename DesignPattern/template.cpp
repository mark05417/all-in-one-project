#include <iostream>

class AbstractClass {
public:
    void TemplateMethod() const {
        Step1();
        Step2();
        Hook(); // Optional
    }

    void Step1() const {
        std::cout << "Step 1: Common implementation\n";
    }

    virtual void Step2() const = 0; // pure virtual
    virtual void Hook() const {}    // optional
    virtual ~AbstractClass() = default;
};

class C1 : public AbstractClass {
public:
    void Step2() const override {
        std::cout << "Step 2: C1\n";
    }

    void Hook() const override {
        std::cout << "Hook: C1\n";
    }
};

class C2 : public AbstractClass {
public:
    void Step2() const override {
        std::cout << "Step 2: C2\n";
    }
};

int main() {
    C1 obj1;
    obj1.TemplateMethod();
    
    std::cout << "\n";

    C2 obj2;
    obj2.TemplateMethod();
}
