#include <iostream>
#include <vector>
using namespace std;

class Graphic {
public:
    virtual void draw() const = 0;
    virtual ~Graphic() = default;
};

class Circle : public Graphic {
public:
    void draw() const override {
        std::cout << "Drawing Circle\n";
    }
};

class Rectangle : public Graphic {
public:
    void draw() const override {
        std::cout << "Drawing Rectangle\n";
    }
};

class CompositeGraphic : public Graphic {
private:
    std::vector<Graphic*> graphics;

public:
    void add(Graphic* graphic) {
        graphics.push_back(graphic);
    }

    void draw() const override {
        for (const auto& graphic : graphics) {
            graphic->draw();
        }
    }
};

int main() {
    // 建立單一圖形
    Circle circle;
    Rectangle rectangle;

    // 建立組合圖形
    CompositeGraphic composite, complexComposite;
    composite.add(&circle);
    composite.add(&rectangle);
    complexComposite.add(&composite);
    complexComposite.add(&circle);

    // 繪製所有圖形
    std::cout << "Drawing composite graphic:\n";
    complexComposite.draw();
    return 0;
}