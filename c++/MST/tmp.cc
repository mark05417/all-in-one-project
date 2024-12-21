#include <iostream>

using namespace std;

int main(void){
    int n = 10000;
    cout << n << endl;
    for(int i=0;i<n;i++) {
        cout << rand() % 1000 << " " << rand() % 1000 << endl;
    }
    return 0;
}