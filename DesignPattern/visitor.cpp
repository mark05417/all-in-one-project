#include <iostream>
#include <vector>

using namespace std;

class Circle;
class Rectangle;
class Triangle;

class AreaCalculator {
public:
    void visit(Circle* c);
    void visit(Rectangle* r);
    void visit(Triangle* t);
    int totalArea = 0;
};

class Shape {
public:
    virtual void accept(AreaCalculator* visitor) = 0;
    virtual ~Shape() {}
};
class Circle : public Shape {
public:
    int R;
    Circle(int r) : R(r) {};
    void accept(AreaCalculator* visitor) {
        visitor->visit(this);
    }
};

class Rectangle : public Shape {
public:
    int W, H;
    Rectangle(int w, int h) : W(w), H(h) {};
    void accept(AreaCalculator* visitor) {
        visitor->visit(this);
    }
};

class Triangle : public Shape {
public:
    int B, H;
    Triangle(int b, int h) : B(b), H(h) {};
    void accept(AreaCalculator* visitor) {
        visitor->visit(this);
    }
};

void AreaCalculator::visit(Circle* c) {
    totalArea += 3.14 * c->R * c->R;
}
void AreaCalculator::visit(Rectangle* r) {
    totalArea += r->W * r->H;
}
void AreaCalculator::visit(Triangle* t) {
    totalArea += 0.5 * t->B * t->H;
}

// client
int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(5));
    shapes.push_back(new Rectangle(3, 4));
    shapes.push_back(new Triangle(4, 5));

    AreaCalculator areaCalculator;
    for (auto shape : shapes) {
        shape->accept(&areaCalculator);
    }
    std::cout << areaCalculator.totalArea << std::endl;
    return 0;
}