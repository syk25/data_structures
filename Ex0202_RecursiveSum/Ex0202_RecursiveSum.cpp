#include <algorithm> // swap
#include <cassert>
#include <iostream>

using namespace std;

int Sum(int *arr, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

// COMPLETE:
int RecurSum(int *arr, int n) {
    if (n == 0) { // 종료조건
        return 0;
    }
    return arr[n - 1] + RecurSum(arr, n - 1); // 점화식
}

int main() {
    // Sum vs RecurSum

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << Sum(arr, n) << endl;
    cout << RecurSum(arr, n) << endl;

    return 0;
}
