#include <iostream>
#include <string>
#include <vector>

using namespace std;

class History {
public:
    void push(const string& s) {
        datas.push_back(s);
    }

    string pop() {
        if (datas.empty()) return string("");
        
        string lastString = datas.back();
        datas.pop_back();
        return lastString;
    }
private:
    std::vector<string> datas;
};

int main() {
    string data;
    History history;

    data.append("123"); cout << data << endl;
    history.push(data);
    data.append("456"); cout << data << endl;
    history.push(data);
    data.append("789"); cout << data << endl;
    
    data = history.pop(); cout << data << endl;
    data = history.pop(); cout << data << endl;
    return 0;
}