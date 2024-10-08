#include <iostream>
#include <memory>
using namespace std;

class Phone {
public:
    virtual ~Phone() = default;
};
class Samsung : public Phone {};
class Pixel : public Phone {};
class Iphone : public Phone {};

class phoneFactory {
public:
    static std::unique_ptr<Phone> createPhone(const std::string& phoneType) {
        if (phoneType == "Iphone") {
            return std::make_unique<Iphone>();
        } else if (phoneType == "Samsung") {
            return std::make_unique<Samsung>();
        } else if (phoneType == "Pixel") {
            return std::make_unique<Pixel>();
        } else {
            return nullptr;
        }
    }
};

int main() {
    std::unique_ptr<Phone> phone = phoneFactory::createPhone("Iphone");
    return 0;
}