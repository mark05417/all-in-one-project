#include <iostream>
#include <map>
class Circle {
public:
    Circle(std::string color) : color(color) {}

    void draw(int x, int y, int radius) {
        std::cout << "Drawing " << color << " circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }

private:
    std::string color;
};

class ShapeFactory {
public:
    Circle* getCircle(std::string color) {
        Circle* circle = circleMap[color];
        if (circle == nullptr) {
            circle = new Circle(color);
            circleMap[color] = circle;
            std::cout << "Creating circle of color: " << color << std::endl;
        }
        return circle;
    }

private:
    std::map<std::string, Circle*> circleMap;
};

int main() {
    ShapeFactory factory;
    Circle* redCircle = factory.getCircle("red");
    redCircle->draw(10, 20, 30);
    Circle* blueCircle = factory.getCircle("blue");
    blueCircle->draw(50, 60, 70);
    Circle* anotherRedCircle = factory.getCircle("red");
    anotherRedCircle->draw(30, 30, 30);
    return 0;
}