#include <iostream>
#include <memory>

// Implementor 抽象接口
class Color {
public:
    virtual void applyColor() = 0;  // 純虛函數，子類別需要具體實現
    virtual ~Color() = default;     // 虛擬析構函數
};

// ConcreteImplementor 具體實現
class RedColor : public Color {
public:
    void applyColor() override {
        std::cout << "Applying Red color." << std::endl;
    }
};

class BlueColor : public Color {
public:
    void applyColor() override {
        std::cout << "Applying Blue color." << std::endl;
    }
};

// Abstraction 抽象部分
class Shape {
protected:
    std::shared_ptr<Color> color;  // 持有 Implementor 的引用
public:
    Shape(std::shared_ptr<Color> c) : color(c) {}
    virtual void draw() = 0;        // 純虛函數，子類別需要具體實現
    virtual ~Shape() = default;     // 虛擬析構函數
};

// RefinedAbstraction 具體抽象部分
class Circle : public Shape {
public:
    Circle(std::shared_ptr<Color> c) : Shape(c) {}

    void draw() override {
        std::cout << "Drawing a Circle. ";
        color->applyColor();  // 使用實現部分
    }
};

class Square : public Shape {
public:
    Square(std::shared_ptr<Color> c) : Shape(c) {}

    void draw() override {
        std::cout << "Drawing a Square. ";
        color->applyColor();  // 使用實現部分
    }
};

int main() {
    // 具體實現類別
    std::shared_ptr<Color> red = std::make_shared<RedColor>();
    std::shared_ptr<Color> blue = std::make_shared<BlueColor>();

    // 使用不同的實現來創建形狀
    std::shared_ptr<Shape> circle = std::make_shared<Circle>(red);
    std::shared_ptr<Shape> square = std::make_shared<Square>(blue);

    circle->draw();  // 繪製紅色的圓
    square->draw();  // 繪製藍色的正方形

    return 0;
}