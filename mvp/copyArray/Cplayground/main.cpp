// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct box{
public:
    int x;
    int y[1];
};

void classVersion(){
    cout<<"class version"<<endl;
    box b1, b2;
    b1.x = 2;
    b1.y[0] = 3;
    cout<<b1.x<<" "<<b1.y[0]<<endl;

    b2 = b1;
    cout<<b2.x<<" "<<b2.y[0]<<endl;

    box b3 = b1;
    cout<<b3.x<<" "<<b3.y[0]<<endl;
    return;
}

void listVersion(){
    cout<<"list version"<<endl;
    int l[] = {2, 3};
    for(auto x:l)    cout<<x<<' '; cout<<endl;

    // int l2[] = l;
    // l2[0] = 12;
    // l2[1] = 13;
    return;
}

int main() {
    classVersion();
    cout<<endl;
    listVersion();
    return 0;
}
