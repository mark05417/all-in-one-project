#include <iostream>

// 已存在舊的實作
class OldRectangle {
public:
    void draw(int x1, int y1, int x2, int y2) {
        std::cout << "OldRectangle: (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")\n";
    }
};

// 新的接口
class NewRectangleInterface {
public:
    virtual void drawRectangle(int x, int y, int width, int height) = 0;
    virtual ~NewRectangleInterface() = default;
};

// Adapter
class RectangleAdapter : public NewRectangleInterface {
private:
    OldRectangle* oldRectangle;
public:
    RectangleAdapter(OldRectangle* rectangle) : oldRectangle(rectangle) {}

    void drawRectangle(int x, int y, int width, int height) override {
        oldRectangle->draw(x, y, x + width, y + height);
    }
};

// client
int main() {
    OldRectangle* oldRectangle = new OldRectangle();
    NewRectangleInterface* adapter = new RectangleAdapter(oldRectangle);
    
    adapter->drawRectangle(10, 20, 30, 40);
    
    delete oldRectangle;
    delete adapter;
    return 0;
}
