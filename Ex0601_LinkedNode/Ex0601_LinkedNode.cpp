﻿#include <iostream>

using namespace std;

struct Node {
    int item = 0; // <- 큰 데이터도 가능
    Node *next = nullptr;

    /* 함수 overloading */
    friend ostream &operator<<(ostream &os, const Node &n) {
        cout << n.item << " " << flush;
        return os;
    }
};

void RecurPrint(Node *node) {
    // REVIEW:
    if (node == nullptr)
        return;
    cout << *node << endl;
    RecurPrint(node->next);
}

void IterPrint(Node *node) {
    // REVIEW:
    for (; node != nullptr; node = node->next) {
        cout << *node << endl;
    }
}

int main() {
    // ListArray와 비교

    Node *first = nullptr;
    first = new Node;
    first->item = 1;
    first->next = nullptr;

    Node *second = nullptr;
    second = new Node;
    second->item = 2;
    second->next = nullptr;

    Node *third = nullptr;
    third = new Node;
    third->item = 3;
    third->next = nullptr;

    Node *fourth = nullptr;
    fourth = new Node;
    fourth->item = 4;
    fourth->next = nullptr;

    Node *fifth = nullptr;
    fifth = new Node;
    fifth->item = 5;
    fifth->next = nullptr;

    // 계속 추가 가능

    cout << *first << endl;
    cout << *second << endl;
    cout << *third << endl;
    cout << *fourth << endl;
    cout << *fifth << endl;
    cout << endl;

    // 연결 관계 만들어 주기
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr; // 넣을 값이 없어도 초기화하기
    // TODO:
    // 마지막

    cout << *(first) << endl;
    cout << *(first->next) << endl;
    cout << *(first->next->next) << endl;
    cout << *(first->next->next->next) << endl;
    cout << *(first->next->next->next->next) << endl;
    // cout << *(first->next->next->next->next->next) << endl; // 오류

    cout << endl;

    // 임시 변수 사용
    {
        Node *current = first;

        // TODO:
        while (current->next != nullptr) {
            cout << *current << endl;
            current = current->next;
        }
        cout << *current << endl;
        cout << endl;
    }

    // 재귀 호출 이용
    RecurPrint(first);
    cout << endl;

    // 반복문 이용
    IterPrint(first);
    cout << endl;

    // REVIEW: 데이터 삭제
    Node *current = first;
    Node *next = current->next;

    while (next != nullptr) {
        cout << *current << endl;
        delete current;
        current = next;
        next = next->next;
    }

    cout << *current << endl;
    delete current;
    current = nullptr;
    next = nullptr;

    return 0;
}
