#include <iostream>
#include <memory>
using namespace std;

class Pizza {
public:
    virtual std::string getDescription() const {
        return "pizza";
    }
    virtual int cost() const {
        return 100;
    }
    virtual ~Pizza() = default;
};

class CheeseDecorator : public Pizza {
private:
    std::unique_ptr<Pizza> pizza;
public:
    CheeseDecorator(std::unique_ptr<Pizza> p) : pizza(std::move(p)) {}

    std::string getDescription() const override {
        return pizza->getDescription() + " + cheese";
    }
    int cost() const override {
        return pizza->cost() + 10;
    }
};


class BaconDecorator : public Pizza {
private:
    std::unique_ptr<Pizza> pizza;
public:
    BaconDecorator(std::unique_ptr<Pizza> p) : pizza(std::move(p)) {}

    std::string getDescription() const override {
        return pizza->getDescription() + " + bacon";
    }
    int cost() const override {
        return pizza->cost() + 20;
    }
};

void showPizza(const Pizza& pizza) {
    std::cout << pizza.getDescription() << ": " << pizza.cost() << std::endl;
}
int main() {
    std::unique_ptr<Pizza> pizza = std::make_unique<Pizza>();
    showPizza(*pizza);
    pizza = std::make_unique<CheeseDecorator>(std::move(pizza));
    showPizza(*pizza);
    pizza = std::make_unique<BaconDecorator>(std::move(pizza));
    showPizza(*pizza);
    pizza = std::make_unique<CheeseDecorator>(std::move(pizza));
    showPizza(*pizza);
    pizza = std::make_unique<BaconDecorator>(std::move(pizza));
    showPizza(*pizza);
    return 0;
}