#include "../shared/Queue.h"
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

int GetMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    Print(arr, n);

    Queue<int> queues[10];

    ;
    int m = GetMax(arr, n); // 가장 큰 자리수를 찾기 위해서

    for (int exp = 1; m / exp > 0; exp *= 10) {
        // REVIEW
        // 큐통에 자리수대로 큐에 넣기
        for (int i = 0; i < n; i++) {
            int temp = arr[i] / exp;
            int loc = temp % 10;
            queues[loc].Enqueue(arr[i]);
        }

        // 큐에서 하나씩 꺼내면서 정렬하기
        int idx = 0;
        for (int i = 0; i < 10; i++) {
            int queue_size = queues[i].Size();
            for (int j = 0; j < queue_size; j++) {
                arr[idx++] = queues[i].Front();
                queues[i].Dequeue();
            }
        }

        Print(arr, n);
    }

    return 0;
}
