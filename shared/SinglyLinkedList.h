#pragma once

#include <cassert>
#include <iostream>
#include <stdint.h>

using namespace std;
template <typename T> class SinglyLinkedList {
  public:
    struct Node {
        T item = T();
        Node *next = nullptr;
    };

    SinglyLinkedList() {}

    SinglyLinkedList(const SinglyLinkedList &list) {
        // REVIEW: 다시해보기 -> 이미 있는 함수들을 사용해서 만들어보자
        Node *current = list.first_;
        while (current) {
            this->PushBack(current->item);
            current = current->next;
        }
    }

    ~SinglyLinkedList() { Clear(); }

    void Clear() // 모두 지워야(delete) 합니다.
    {
        // TODO: 모두 삭제
    }

    bool IsEmpty() { return first_ == nullptr; }

    int Size() {
        int size = 0;

        // REVIEW: size를 하나하나 세어서 반환
        Node *temp = first_;
        while (temp) {
            size++;
            temp = temp->next;
        }

        return size;
    }

    T Front() {
        assert(first_);

        return first_->item; // REVIEW: 수정
    }

    T Back() {
        assert(first_);
        Node *current = first_;
        while (current->next) {
            current = current->next;
        }

        return current->item; // REVIEW: 수정
    }

    Node *Find(T item) {
        // REVIEW: item이 동일한 노드 포인터 반환
        // 노드주소, 노드아이템, 노드 다음 주소
        Node *current = first_;
        while (current) {
            if (current->item == item) {
                return current;
            }
            current = current->next;
        }

        return nullptr;
    }

    void InsertBack(Node *node, T item) {
        // REVIEW:
        // 노드를 삽입하는 작업: 노드구조체가 필요함
        // 새로운 노드: 아이템, 다음 노드의 주소
        // 기존 노드: 다음 노드의 주소
        Node *make = new Node;
        make->item = item;
        make->next = node->next;
        node->next = make;
    }

    void Remove(Node *n) {
        assert(first_);

        // 하나 앞의 노드를 찾아야 합니다.
        // REVIEW:
        // 지금 노드 삭제: 이전 노드를 이후의 노드로 연결시켜야함
        // 이전노드의 주소 찾은 후 다음 노드의 주소로 이전노드의 next를 갱신한다
        Node *prev = nullptr;
        Node *current = first_;

        while (current != n) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        delete current;
    }

    void PushFront(T item) {
        using namespace std;
        // first_가 nullptr인 경우와 아닌 경우 나눠서 생각해보기 (결국은 두 경우를 하나로 합칠 수 있음)

        // 새로운 노드 만들기
        // REVIEW:
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->item = item;
        temp->next = nullptr;
        // 연결 관계 정리
        // REVIEW:

        if (first_ == nullptr) {
            first_ = temp;
        } else {
            temp->next = first_;
            first_ = temp;
        }
    }

    void PushBack(T item) {
        Node *temp = new Node; // new 연산자는 메모리 동적할당 후 구조체를 생성한 다음 구조체의 주소를 반환
        temp->item = item;
        temp->next = nullptr;

        if (first_) {
            // REVIEW:
            Node *check = first_;
            while (check->next) {
                check = check->next;
            }
            check->next = temp;
        } else {
            // REVIEW:
            first_ = temp;
        }
    }

    void PopFront() {
        if (IsEmpty()) {
            using namespace std;
            cout << "Nothing to Pop in PopFront()" << endl;
            return;
        }

        assert(first_);

        // REVIEW: 메모리 삭제
        Node *current = first_;
        first_ = current->next;
        delete current;
    }

    void PopBack() {
        if (IsEmpty()) {
            using namespace std;
            cout << "Nothing to Pop in PopBack()" << endl;
            return;
        }

        // 맨 뒤에서 하나 앞의 노드를 찾아야 합니다.

        assert(first_);

        // REVIEW: 메모리 삭제 - edge case: 내 방법이 맞았구나....
        Node *current = first_;
        if (current->next) {
            while (current->next->next) {
                current = current->next;
            }
            Node *next = current->next;
            delete next;
            current->next = nullptr;
        } else {
            delete current;
            first_ = nullptr;
        }
    }

    // REVIEW: 포인터를 활용한 관계의 역순화: 대상 자체에 대한 정보와 조작을 위한 데이터 구분하기
    // 일단 기능의 목적을 생각한다. 기능의 목적에 따라 대상에서 필요한 데이터가 뭔지 분석한다. 기능을 수행할 때 어떤
    // 도구가 필요한지 분석한다.
    void Reverse() {
        // 노드 구조체: 노드 자체의 주소, 다음노드의 주소
        // 도구: 이전 노드 주소, 현재 노드 주소, 다음 노드 주소
        // 마지막 노드에 도달할 때까지 노드의 관계를 역전시킨다
        // 마지막 노드에 도달하면 반복을 멈추고 first_로 바꾼다
        Node *prev = nullptr;
        Node *current = this->first_;
        Node *next = current->next;

        while (next) {
            current->next = prev;
            prev = current;
            current = next;
            next = current->next;
        }
        this->first_ = current;
        current->next = prev;
    }

    void SetPrintDebug(bool flag) { print_debug_ = flag; }

    void Print() {

        Node *current = first_;

        if (IsEmpty())
            cout << "Empty" << endl;
        else {
            cout << "Size = " << Size() << " ";

            while (current) {
                if (print_debug_) {
                    // cout << "[" << current << ", " << current->item << ", " << current->next << "]";

                    // 주소를 짧은 정수로 출력 (앞 부분은 대부분 동일하기때문에 뒷부분만 출력)
                    cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", " << current->item << ", "
                         << reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
                } else {
                    cout << current->item;
                }

                if (current->next)
                    cout << " -> ";
                else
                    cout << " -> NULL";

                current = current->next;
            }
            cout << endl;
        }
    }

  protected:
    Node *first_ = nullptr;

    bool print_debug_ = false;
};