#include <iostream>
#include <memory>

using namespace std;

int main(){    
    shared_ptr<int> pInv(new int);
    unique_ptr<int> pInv2(new int);

    int* p1 = pInv.get();
    int* p2 = pInv2.get();

    *p1 = 10;
    *p2 = 20;

    cout << *p1 << endl;
    cout << *p2 << endl;

    cout << *pInv.get() << endl;
    cout << *pInv2.get() << endl;
    return 0;
}