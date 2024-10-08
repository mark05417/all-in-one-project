#include <iostream>
#include <memory>
// Weapon
class Weapon {
public:
    virtual void use() = 0;
    virtual ~Weapon() {}
};

class Sword : public Weapon {
public:
    void use() override {
        std::cout << "使用劍" << std::endl;
    }
};

class Staff : public Weapon {
public:
    void use() override {
        std::cout << "使用法杖" << std::endl;
    }
};

// Character
class Character {
protected:
    Weapon* weapon;
public:
    Character(Weapon* w) : weapon(w) {}
    virtual void attack() = 0;
    virtual ~Character() {}
};

class Human : public Character {
public:
    Human(Weapon* w) : Character(w) {}
    void attack() override {
        std::cout << "人類";
        weapon->use();
    }
};

class Elf : public Character {
public:
    Elf(Weapon* w) : Character(w) {}
    void attack() override {
        std::cout << "精靈";
        weapon->use();
    }
};

int main() {
    std::unique_ptr<Weapon> sword = std::make_unique<Sword>();
    std::unique_ptr<Weapon> staff = std::make_unique<Staff>();
    std::unique_ptr<Character> human = std::make_unique<Human>(sword.get());
    std::unique_ptr<Character> elf = std::make_unique<Elf>(staff.get());
    human->attack();
    elf->attack();
    human = std::make_unique<Human>(staff.get());
    elf = std::make_unique<Elf>(sword.get());
    human->attack();
    elf->attack();
    return 0;
}