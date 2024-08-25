#include "../shared/Queue.h"

#include <iostream>

using namespace std;

int main() {
    // FIFO(First In First Out)

    Queue<char> q(2); // capacity_ = 2에서 시작 (메모리 증가 확인)

    q.SetDebugFlag(true);

    q.Print();

    /* Enqueue 구현 필요 */
    q.Enqueue('A');
    q.Print();

    /* 시작크기가 2이므로 Resizing 구현 필요 */
    q.Enqueue('B');
    q.Print();

    q.Enqueue('C');
    q.Print();

    q.Enqueue('D');
    q.Print();

    q.Dequeue();
    q.Print();
    exit(-1);

    q.Dequeue();
    q.Print();

    q.Dequeue();
    q.Print();

    for (char c = 'E'; c <= 'K'; c++) {
        q.Enqueue(c);
        q.Print();
    }

    return 0;
}
