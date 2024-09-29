#include <iostream>

using namespace std;

/* int MySwapValue(int i, int j) {
    // NOTE: call by value - 값을 복사해옴 + 완전 새로운 변수를 만듬 + 반환을 하기가 난감함
    int temp = i;
    i = j;
    j = temp;
    return -1;
} */

void MySwapPtr(int *i, int *j) {
    // NOTE: 포인터로 매개변수를 받는 경우
    int temp = *i;
    *i = *j;
    *j = temp;
}

void MySwapRef(int &i, int &j) {
    // NOTE: Reference로 매개변수를 받는 경우 - 변수 자체에 이름을 하나 더 붙인 경우 - 객체를 복사하지 않음
    int temp = i;
    i = j;
    j = temp;
}

bool CheckSorted(int a, int b) { return !(a > b); }

int main() {
    // Swap
    {
        int a = 3;
        int b = 2;

        cout << "Before: " << a << " " << b << endl;

        // COMPLETE:
        // MySwapPtr(&a, &b);
        MySwapRef(a, b);

        cout << "After : " << a << " " << b << endl;
    }

    // 정렬(sorting)
    {
        int arr[] = {9, 3};

        cout << arr[0] << " " << arr[1] << endl;

        // COMPLETE:
        if (arr[0] > arr[1])
            MySwapRef(arr[0], arr[1]);

        cout << arr[0] << " " << arr[1] << endl;
    }

    // 값과 상관 없이 항상 작은 값이 먼저 출력되게 하려면?
    // 두 값이 같을 때는 순서가 상관 없음 -> 큰 값이 먼저 출력되지 않게 하려면?
    {
        int arr[2];

        // COMPLETE:
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                arr[0] = i;
                arr[1] = j;
                cout << boolalpha;
                cout << i << " " << j;
                cout << " " << (arr[0] <= arr[1]) << endl;
            }
        }
    }

    return 0;
}
