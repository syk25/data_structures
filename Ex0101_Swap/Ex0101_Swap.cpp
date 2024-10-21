#include <iostream>

using namespace std;

// 매개변수가 값인 경우 - 값을 복사해서 전달
int MySwapValue(int i, int j) {
    // TODO:

    return 0;
}

// 매개변수가 포인터인 경우 - 주소를 복사해서 전달 -> 값을 바꿀 수 있음
void MySwapPtr(int *i, int *j) {
    // TODO:
    int temp = *i;
    *i = *j;
    *j = temp;
}

// 매개변수가 참조인 경우 - 변수 자체에 이름을 하나 더 붙인 경우임
void MySwapRef(int &i, int &j) {
    // TODO:
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

        cout << a << " " << b << endl;

        // REVIEW
        int temp = a;
        a = b;
        b = temp;

        cout << a << " " << b << endl;
    }

    // 정렬(sorting)
    {
        int arr[] = {9, 3};

        cout << arr[0] << " " << arr[1] << endl;

        // TODO:

        cout << arr[0] << " " << arr[1] << endl;
    }

    // 값과 상관 없이 항상 작은 값이 먼저 출력되게 하려면?
    // 두 값이 같을 때는 순서가 상관 없음 -> 큰 값이 먼저 출력되지 않게 하려면?
    {
        int arr[2];

        // TODO:
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                arr[0] = i;
                arr[1] = j;

                if (arr[0] > arr[1]) {
                    std::swap(arr[0], arr[1]);
                }

                cout << arr[0] << " " << arr[1] << " " << boolalpha << CheckSorted(arr[0], arr[1]) << endl;
            }
        }
    }

    return 0;
}
