// proxy pattern: cache image
class ProxyImage : public Image {
private:
    std::string filename;
    std::unique_ptr<RealImage> realImage;

public:
    ProxyImage(const std::string& filename) : filename(filename), realImage(nullptr) {}

    void display() override {
        if (!realImage) {
            // lazy initialization
            realImage = std::make_unique<RealImage>(filename);
        }
        realImage->display();
    }
};