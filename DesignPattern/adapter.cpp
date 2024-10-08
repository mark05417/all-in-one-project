#include <iostream>
#include <memory>
using namespace std;

class XMLData {
public:
    virtual std::string getXMLData() = 0;
    virtual ~XMLData() = default;
};

class JSONData {
public:
    std::string getJSONData() {
        return "{\"name\": \"John\", \"age\": 30}";
    }
};

class JSONToXMLAdapter : public XMLData {
private:
    JSONData* jsonData;
public:
    JSONToXMLAdapter(JSONData* data) : jsonData(data) {}

    std::string getXMLData() override {
        std::string jsonData = this->jsonData->getJSONData();
        std::string xmlData = "<root>" + jsonData + "</root>";
        return xmlData;
    }
};

int main() {
    JSONData jsonData;
    XMLData adapter = JSONToXMLAdapter(&jsonData);

    std::cout << "XML Data: " << adapter.getXMLData() << std::endl;


    return 0;
}