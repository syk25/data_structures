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
    // 오른쪽으로 하나씩 밀기 (삽입 정렬의 중간 단계)
    /* {
        int arr[] = {1, 2, 4, 5, 3, 6};
        int n = sizeof(arr) / sizeof(arr[0]);

        Print(arr, n);
        cout << "start" << endl;



        int i = 4; // 3의 위치가 맞도록 하나씩 밀어낼 것
                int key = arr[i];
                int j = i;
                for(; key < arr[j-1] && j > 0; j--){
                        arr[j] = arr[j-1]; // 오른쪽으로 값들을 shift

                        Print(arr, n);
                }
                // j의 위치에 값 넣기
                arr[j] = key;

        cout << "end" << endl;
        Print(arr, n);
        cout << endl;
    } */

    // int arr[] = { 8, 3, 2, 5, 1, 2 };
    int arr[] = {6, 5, 4, 3, 2, 1}; // Worst :
    // int arr[] = { 1, 2, 3, 4, 5, 6 }; // Best : 전체 원소개수 -1번 돌기
    int n = sizeof(arr) / sizeof(arr[0]);

    // Insertion Sort
    {
		cout << "start ";
		Print(arr, n);
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i;
			
            for (; key < arr[j - 1] && j > 0; j--) {
                arr[j] = arr[j - 1];
				cout << "Inner ";
				Print(arr, n);
            }
			arr[j] = key;
			cout << "Outer ";
			Print(arr, n);
        }
		cout << "end ";
		Print(arr, n);
    }

    // Stability
}
