#include <iostream>
#include <string>

class Handler {
public:
    virtual void handleRequest(int request) {};
    virtual Handler* setNext(Handler* handler) {
        nextHandler = handler;
        return handler;
    }
protected:
    Handler* nextHandler = nullptr;
};

class ConcreteHandler1 : public Handler {
public:
    void handleRequest(int request) override {
        if (request < 10) {
            std::cout << "ConcreteHandler1 handled request: " << request << std::endl;
        } else if (nextHandler) {
            nextHandler->handleRequest(request);
        } else {
            std::cout << "Error" << std::endl;
        }
    }
};

class ConcreteHandler2 : public Handler {
public:
    void handleRequest(int request) override {
        if (request >= 10 && request < 20) {
            std::cout << "ConcreteHandler2 handled request: " << request << std::endl;
        } else if (nextHandler) {
            nextHandler->handleRequest(request);
        } else {
            std::cout << "Error" << std::endl;
        }
    }
};


int main() {
    Handler* handler1 = new ConcreteHandler1();
    Handler* handler2 = new ConcreteHandler2();
    handler1->setNext(handler2);
    handler1->handleRequest(5);
    handler1->handleRequest(15);
    handler1->handleRequest(25);
    return 0;
}