#include <iostream>
#include <string>

class CustomerServiceHandler {
protected:
    CustomerServiceHandler* nextHandler;
public:
    CustomerServiceHandler(CustomerServiceHandler* handler) : nextHandler(handler) {}
    virtual ~CustomerServiceHandler() = default;
    virtual void setNext(CustomerServiceHandler* handler) {
        nextHandler = handler;
    }
    virtual void handleRequest(const std::string& request) = 0;
};


class AutomatedSystem : public CustomerServiceHandler {
public:
    AutomatedSystem(CustomerServiceHandler* handler) : CustomerServiceHandler(handler) {}
    void handleRequest(const std::string& request) override {
        if (request == "簡單問題") {
            std::cout << "自動系統：我可以回答這個簡單問題。" << std::endl;
        } else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        } else {
            std::cout << "無法解決這個問題。" << std::endl;
        }
    }
};
class HumanAgent : public CustomerServiceHandler {
public:
    HumanAgent(CustomerServiceHandler* handler) : CustomerServiceHandler(handler) {}
    void handleRequest(const std::string& request) override {
        if (request == "複雜問題") {
            std::cout << "人工客服：我來處理這個複雜問題。" << std::endl;
        } else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        } else {
            std::cout << "無法解決這個問題。" << std::endl;
        }
    }
};
class TechnicalSupport : public CustomerServiceHandler {
public:
    TechnicalSupport(CustomerServiceHandler* handler) : CustomerServiceHandler(handler) {}
    void handleRequest(const std::string& request) override {
        if (request == "技術問題") {
            std::cout << "技術支援團隊：我們會深入研究並解決這個問題。" << std::endl;
        } else if (nextHandler != nullptr) {
            nextHandler->handleRequest(request);
        } else {
            std::cout << "無法解決這個問題。" << std::endl;
        }
    }
};

int main() {
    AutomatedSystem automatedSystem(new HumanAgent(new TechnicalSupport(nullptr)));
    automatedSystem.handleRequest("簡單問題");
    automatedSystem.handleRequest("複雜問題");
    automatedSystem.handleRequest("技術問題");
    return 0;
}