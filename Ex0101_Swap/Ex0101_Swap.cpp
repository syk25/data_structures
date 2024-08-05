#include <iostream>

using namespace std;

/*
// 변수로 받는 경우, 매개변수로 받은 값을 복사
// 그런데 반환값은 1개임
int MySwapValue(int i, int j)
{
        // TODO:

        return ? ;
}
*/
/* 포인터 매개변수 */
void MySwapPtr(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

/* 레퍼런스 매개변수 */
void MySwapRef(int &i, int &j) {
    // TODO:
    int temp = i;
    i = j;
    j = temp;
}

bool CheckSorted(int a, int b) { return false; }

int main() {
    // Swap
    {
        int a = 3;
        int b = 2;

        cout << a << " " << b << endl;

        // TODO:
        /* int temp = a;
        a = b;
        b = temp; */

        MySwapPtr(&a, &b);

        cout << a << " " << b << endl;
    }

    // 정렬(sorting)
    {
        int arr[] = {9, 3};

        cout << arr[0] << " " << arr[1] << endl;

        // TODO:

        if (arr[0] > arr[1]) {
            MySwapRef(arr[0], arr[1]);
        }
        cout << arr[0] << " " << arr[1] << endl;
    }

    // 값과 상관 없이 항상 작은 값이 먼저 출력되게 하려면?
    // 두 값이 같을 때는 순서가 상관 없음 -> 큰 값이 먼저 출력되지 않게 하려면?
    {
        int arr[2];

        // TODO:
    }

    return 0;
}
