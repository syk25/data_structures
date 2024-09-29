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

void bubbleSort(int *arr, int size) {
    cout << "Bubble: " << endl;
    if (CheckSorted(arr, size)) {
        return;
    }

    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
            cout << "Sorting: ";
            Print(arr, size);
        }
        cout << "Loop: ";
        Print(arr, size);
    }
}

int main() {
    // int arr[] = {5, 1, 4, 2, 8}; // 위키피디아 예시
    // int arr[] = {5, 4, 3, 2, 1}; // Worst Case
    int arr[] = {1, 2, 3, 5, 4}; // Best Case
    int n = sizeof(arr) / sizeof(arr[0]);

    Print(arr, n);
    cout << endl;

    // Bubble Sort
    {
        bubbleSort(arr, n);
        Print(arr, n);
        // 힌트: Print()로 진행상황 확인하면서 구현
        // 힌트: 2중 for 루프
        // 힌트: for 루프 범위 주의
    }

    // Best case
    // Stability
    {
        int arr[] = {1, 2, 3, 4, 5};
        int n = sizeof(arr) / sizeof(int);
        bubbleSort(arr, n);
        Print(arr, n);
    }
}
