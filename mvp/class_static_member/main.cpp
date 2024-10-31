#include <iostream>

#define CALL_WITH_MAX(a, b) f( (a) > (b) ? (a) : (b) )
void f(int a) {}

// class A {
// public:
//     enum { count = 10 };
//     int scores[count];
// };

int main(void) {
    int a = 5, b = 0;
    CALL_WITH_MAX(++a, b); // a : 5 -> 7
    CALL_WITH_MAX(++a, b+10); // a : 7 -> 8
    return 0;
}