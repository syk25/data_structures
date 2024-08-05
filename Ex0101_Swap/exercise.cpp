#include <iostream>

/* 1. 0 ~ 4까지 두자리 수를 오름차순으로 정렬되었으면 true, 그렇지 않다면 false가 되도록 출력하기 */

using namespace std;

bool checkSort(int i, int j){
    return i >= j ? true : false;
}

int main(){
    for(int i = 0; i <=4; i++){
        for (int j = 0; j <=4 ;j++){
            cout << i << " " << j << " " << boolalpha << checkSort(i, j) << endl;
        }
    }
}