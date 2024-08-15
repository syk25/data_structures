#include <algorithm> // swap
#include <cassert>
#include <iostream>

using namespace std;

void RecurPermutations(char *arr, int left, int right) {
    // arr[left], ..., arr[right]

    if (left == right) {
        for (int i = 0; i <= right; i++)
            cout << arr[i] << " ";
        cout << endl;
    } else {
        // 힌트
        // - for, swap(), 재귀호출
        // - 같은 변수끼리도 swap() 가능
        // - right는 고정

        /**
         * 반복문: 난 초반에 i =0 부터 i < right 까지 돌리려고 했다. 그런데 i를 left와 연관시키지 않아서 원하는 과정이 되지 않았다.
         * 
         */
        // REVIEW:
        for(int i = left; i <= right; i++){ // 반복범위를 정함: 자리를 바꾸는 값을 기준으로 할 때 left, right로 해야 함
            swap(arr[left], arr[i]); // 고정되는 값 정하기
            RecurPermutations(arr, left + 1, right); // 순열하는 데이터의 크기를 하나 줄여서 재귀호출
            swap(arr[left], arr[i]); // 본래상태로 복귀
        }
        
        
        
    }
}

int main() {
    /* a 한 글자의 순열 (Permutations)

            a
    */

    /* ab 두 글자의 순열 (Permutations)

            a b
            b a
    */

    /*  abc 3 글자의 순열 (Permutations)

            a b c
            a c b
            b a c
            b c a
            c b a
            c a b
    */

    // Permutations
    char arr[] = "abcd";

    RecurPermutations(arr, 0, 0);
    cout << endl;

    RecurPermutations(arr, 0, 1);
    cout << endl;

    RecurPermutations(arr, 0, 2);
    cout << endl;

    // RecurPermutations(arr, 0, 3);
    // cout << endl;

    return 0;
}
