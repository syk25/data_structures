#include <iostream>

using namespace std;

struct Node {             // 구조체: 데이터의 묶음
    int item = 0;         // <- 큰 데이터도 가능
    Node *next = nullptr; // 다음 노드의 위치

    // 연잔자 오버로딩: '<<'를 오버로딩함
    friend ostream &operator<<(ostream &os, const Node &n) {
        cout << "[ 현재주소: " << &n << ", 노드의 값: " << n.item << ", 다음 주소: " << n.next << " ] " << flush;
        return os;
    }
};

void RecurPrint(Node *node) {
    // REVIEW: 조건식을 더 직관적으로 쓰자.
    if (node) {
        cout << *node << endl;
        RecurPrint(node->next);
    }
    return;
}

void IterPrint(Node *node) {
    // REVIEW:
    Node *current = node;

    while (current) {
        cout << *current << endl;
        current = current->next;
    }

    cout << endl;
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
    // first->next = second;
    // REVIEW:
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr; // NOTE: 널포인터 꼭 지정하기
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
        cout << *current << endl;

    REVIEW:
        while (current->next != nullptr) {
            current = current->next;
            cout << *current << endl;
        }

        cout << endl;
    }

    // 재귀 호출 이용
    RecurPrint(first);
    cout << endl;

    // 반복문 이용
    IterPrint(first);
    cout << endl;

    // REVIEW: 데이터 삭제
    Node *temp = first;
    Node *current = temp;
    while (temp) {
        
        cout << "delete " << *temp << endl;
        delete temp;
        temp = current;
        current = temp->next;
    }

    return 0;
}