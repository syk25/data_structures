#include <cassert>
#include <fstream>
#include <iostream>

using namespace std;

struct Element {
    int key;
    char value;
};

bool CheckSorted(int *arr, int size) {
    // REVIEW: 정렬 확인 함수 구현
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void Print(int *arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Print(Element *arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i].key << " ";
    cout << endl;

    for (int i = 0; i < size; i++)
        cout << arr[i].value << " ";
    cout << endl;
}

/* @brief 선택정렬 */
void sort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[min_idx] > arr[j]) { // NOTE: 값비교
                min_idx = j;             // 최소값 인덱스 갱신
            }
        }
        swap(arr[min_idx], arr[i]); // 최소위치로 최소값을 옮김
    }
}

void sort(Element *arr, int size) {
    for (int i = 0; i < size; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[min_idx].key > arr[j].key) { // NOTE: 값비교
                min_idx = j;                     // 최소값 인덱스 갱신
            }
        }
        swap(arr[min_idx], arr[i]); // 최소위치로 최소값을 옮김
    }
}

/* @brief 선택정렬 헬퍼 함수: 값 교체 */
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    // 3개 정렬
    {
        for (int k = 0; k < 3; k++)
            for (int j = 0; j < 3; j++)
                for (int i = 0; i < 3; i++) {

                    int arr[3] = {i, j, k};
                    int size = sizeof(arr) / sizeof(arr[0]);

                    for (int e = 0; e < size; e++) {
                        cout << arr[e] << " " << flush;
                    }

                    cout << " -> " << flush;

                    // REVIEW: 정렬 해보기
                    sort(arr, size);

                    for (int e = 0; e < size; e++) {
                        cout << arr[e] << " " << flush;
                    }

                    cout << boolalpha;
                    cout << CheckSorted(arr, size); // 정렬 되었나 확인
                    cout << endl;
                }
    }

    // 5개라면? 더 많다면?
    {
        // 8 4 2 8 3
        // TODO: ???
        int arr[] = {8, 4, 2, 8, 3};
        int size = sizeof(arr) / sizeof(int);

        sort(arr, size);
        Print(arr, size);

        // 8 3 2 5 1 1 2 5 8 9
        // TODO: ???

        // 100개라면?
    }

    // 가장 작은 수 찾기
    {
        int arr[] = {8, 3, 2, 5, 1, 1, 2, 5, 8, 9}; // 임의의 숫자들, 변경 가능
        int size = sizeof(arr) / sizeof(arr[0]);

        assert(size > 0); // size가 1이상이라고 가정

        // REVIEW:
        sort(arr, size);
        int min_number = arr[0];

        Print(arr, size);

        cout << "Minimum number is " << min_number << endl;
    }

    // 가장 작은 수의 인덱스 찾기
    {
        int arr[] = {8, 3, 2, 5, 1, 1, 2, 5, 8, 9};
        int size = sizeof(arr) / sizeof(arr[0]);

        assert(size > 0); // size가 1이상이라고 가정

        // REVIEW:
        int min_index = 0;
        for (int i = 1; i < size; i++) {
            if (arr[min_index] > arr[i]) {
                min_index = i;
            }
        }

        Print(arr, size);

        cout << "The index of min is " << min_index << endl;
        cout << "Minimum number is " << arr[min_index] << endl;
    }

    // Selection Sort
    // 힌트: swap()
    {
        int arr[] = {8, 3, 2, 5, 1, 1, 2, 5, 8, 9};
        int size = sizeof(arr) / sizeof(arr[0]);

        int min_index;
        for (int i = 0; i < size - 1; i++) {
            // REVIEW:
            min_index = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[min_index] > arr[j]) {
                    min_index = j;
                }
            }
            swap(arr[min_index], arr[i]);

            Print(arr, size);

            cout << boolalpha;
            cout << CheckSorted(arr, size);
            cout << endl;
        }
    }

    // 비교 횟수 세보기, 더 효율적인 방법은 없을까?
    // https://en.wikipedia.org/wiki/Sorting_algorithm
    {
        ofstream ofile("log.txt");
        for (int size = 1; size < 1000; size++) {
            int count = 0;
            int *arr = new int[size];
            for (int s = 0; s < size; s++) {
                arr[s] = size - s;
            }

            // REVIEW: count ++;
            for (int i = 0; i < size - 1; i++) {
                int min_idx = i;
                for (int j = i + 1; j < size; j++) {
                    count++;
                    if (arr[min_idx] > arr[j]) {
                        min_idx = j;
                    }
                }
                swap(arr[min_idx], arr[i]);
            }

            // cout << size << ", " << count << endl;
            ofile << size << ", " << count << endl;
            // Print(arr, size);

            delete[] arr;
        }

        ofile.close();
    }
    // [2, 2, 1]
    // [1, 2, 2] // 첫 2가 마지막으로 이동

    // 안정성 확인(unstable)
    {
        Element arr[] = {{2, 'a'}, {2, 'b'}, {1, 'c'}};
        int size = sizeof(arr) / sizeof(arr[0]);

        Print(arr, size); // arr이 Element의 배열

        // REVIEW:
        sort(arr, size);

        Print(arr, size); // arr이 Element의 배열
    }
    return 0; // <- 실습용 임÷시
}
