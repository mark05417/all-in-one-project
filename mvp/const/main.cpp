#include <iostream>

class Example {
public:
    // const 版本的函式
    int getValue() const {
        std::cout << "Calling const version" << std::endl;
        // Step 1
        // Step 2
        // Step 3
        return value;
    }

    // non-const 版本的函式，利用 const_cast 呼叫 const 版本
    int getValue() {
        std::cout << "Calling non-const version" << std::endl;
        return const_cast<const Example*>(this)->getValue();
    }

private:
    int value = 42;
};

int main() {
    Example ex;
    const Example cex;

    std::cout << ex.getValue() << std::endl;   // 呼叫 non-const 版本

    return 0;
}
