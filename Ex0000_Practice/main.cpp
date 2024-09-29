/*
swap 연습
1. 포인터를 이용한 swap 구현
2. 레퍼런스를 이용한 swap 구현
3. 표준함수를 이용한 swap 구현

 */

#include <iostream>

using namespace std;

void swapPtr(int *a, int *b) {
    cout << "Before| Swap by Pointer: " << "a: " << a << ", b: " << b << endl;
    int temp = *a;
    *a = *b;
    *b = temp;

    cout << "After | Swap by Pointer: " << "a: " << a << ", b: " << b << endl;
}

void swapRef(int &a, int &b) {
    cout << "Before| Swap by Reference: " << "a: " << a << ", b: " << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "After | Swap by Reference: " << "a: " << a << ", b: " << b << endl;
}

int main() {
    int a = 10;
    int b = 20;

    cout << "before swap: a: " << a << ", b: " << b << endl;

    // 1. 포인터를 이용한 swap 구현
    // swapPtr(&a, &b);

    // 2. 레퍼런스를 이용한 swap 구현
    swapRef(a, b);

    // 3. 표준함수를 이용한 swap 구현
    // swap(a, b);

    cout << "after swap: a: " << a << ", b: " << b << endl;

    return 0;
}