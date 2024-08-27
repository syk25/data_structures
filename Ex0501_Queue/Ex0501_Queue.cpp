#include "../shared/Queue.h"

#include <iostream>

int main() {
    // FIFO(First In First Out)

    Queue<char> q(2); // capacity_ = 2에서 시작 (메모리 증가 확인)

    q.SetDebugFlag(true);

    q.Print();

    q.Enqueue('A'); // A
    q.Print();

    q.Enqueue('B'); // A B
    q.Print();

    q.Enqueue('C'); // A B C
    // q.Print();

    q.Enqueue('D'); // A B C D
    // q.Print();

    q.Dequeue(); // B C D
    // q.Print();

    q.Dequeue(); // C D
    // q.Print();

    q.Dequeue(); // D
    q.Print();

    for (char c = 'E'; c <= 'K'; c++) {
        q.Enqueue(c);
        q.Print();
    }

    return 0;
}