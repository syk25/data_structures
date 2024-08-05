#include <iostream>

using namespace std;

bool CheckSorted(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1])
            return false;
    }

    return true;
}

void Print(int *arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // int arr[] = {5, 1, 4, 2, 8}; // 위키피디아 예시
    // int arr[] = { 5, 4, 3, 2, 1 }; // Worst Case
    int arr[] = { 1, 2, 3, 5, 4 }; // Best Case
    int n = sizeof(arr) / sizeof(arr[0]);

    Print(arr, n);
    cout << endl;

    // Bubble Sort
    {
        // 힌트: Print()로 진행상황 확인하면서 구현
        // 힌트: 2중 for 루프
        // 힌트: for 루프 범위 주의
        // 하나의 패스에서 끝자리까지 교환해서 올라가기
        for (int j = n - 1; j > 0; j--) {
            for (int i = 0; i < j; i++) {
                if (arr[i] > arr[i + 1])
                    swap(arr[i], arr[i + 1]);
                Print(arr, n);
            }
			cout << n - j << ": " << "pass ended" << endl;
			if(CheckSorted(arr, n)) break;
        }
    }

    // Best case
    // Stability
}
