#include <iostream>
#include <memory>

// 定義 Subject 介面，RealSubject 和 Proxy 都會實現此介面
class Subject {
public:
    virtual void request() const = 0;
    virtual ~Subject() = default;
};

// RealSubject 實現了真正的功能
class RealSubject : public Subject {
public:
    void request() const override {
        std::cout << "RealSubject: Handling request." << std::endl;
    }
};

// Proxy 會控制對 RealSubject 的訪問
class Proxy : public Subject {
private:
    mutable std::unique_ptr<RealSubject> real_subject_; // 延遲加載
    bool check_access() const {
        // 這裡可以執行一些訪問控制的邏輯
        std::cout << "Proxy: Checking access prior to firing a real request.\n";
        return true;
    }

    void log_access() const {
        // 記錄一些日誌
        std::cout << "Proxy: Logging the time of request.\n";
    }

public:
    void request() const override {
        if (check_access()) {
            if (!real_subject_) {
                // 延遲實例化 RealSubject
                real_subject_ = std::make_unique<RealSubject>();
            }
            real_subject_->request();
            log_access();
        }
    }
};

int main() {
    std::cout << "Client: Executing with a real subject:\n";
    RealSubject real_subject;
    real_subject.request();

    std::cout << "\nClient: Executing with a proxy:\n";
    Proxy proxy;
    proxy.request();
    return 0;
}
