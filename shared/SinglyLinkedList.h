#pragma once

#include <cassert>
#include <stdint.h>

template <typename T> class SinglyLinkedList {
  public:
    struct Node {
        T item = T();
        Node *next = nullptr;
    };

    SinglyLinkedList() {}

    SinglyLinkedList(const SinglyLinkedList &list) {
        // REVIEW 연결 리스트 복사
        Node *current = list.first_;

        while (current) {
            this->PushBack(current->item);
            current = current->next;
        }
    }

    ~SinglyLinkedList() { Clear(); }

    void Clear() // 모두 지워야(delete) 합니다.
    {
        // REVIEW 모두 삭제
        Node *current = first_;

        while (current) {
            Node *temp = current->next;
            delete current;
            current = temp;
        }
    }

    bool IsEmpty() { return first_ == nullptr; }

    int Size() {
        int size = 0;

        // REVIEW size를 하나하나 세어서 반환
        Node *current = first_;

        while (current) {
            size += 1;
            current = current->next;
        }

        return size;
    }

    T Front() {
        assert(first_);
        // REVIEW 수정
        return first_->item;
    }

    T Back() {
        assert(first_);

        // REVIEW

        Node *current = first_;
        while (current->next) {
            current = current->next;
        }

        return current->item;
    }

    Node *Find(T item) {
        // REVIEW item이 동일한 노드 포인터 반환
        Node *current = first_;
        while (current) {
            if (current->item == item) {
                break;
            }
            current = current->next;
        }

        return current;
    }

    void InsertBack(Node *node, T item) {
        // REVIEW
        Node *temp = new Node;
        temp->item = item;
        temp->next = node->next;
        node->next = temp;
    }

    void Remove(Node *n) {
        assert(first_);

        // 하나 앞의 노드를 찾아야 합니다.
        // REVIEW
        Node *prev = nullptr;
        Node *current = first_;
        while (current) {
            if (current == n) {
                break;
            }
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        delete current;
    }

    void PushFront(T item) {
        // first_가 nullptr인 경우와 아닌 경우 나눠서 생각해보기 (결국은 두 경우를 하나로 합칠 수 있음)

        // 새로운 노드 만들기
        // REVIEW
        Node *temp = new Node;
        temp->item = item;
        temp->next = first_;

        // 연결 관계 정리
        // REVIEW
        first_ = temp;
    }

    void PushBack(T item) {
        Node *temp = new Node;
        temp->item = item;
        if (first_) {
            // REVIEW
            Node *current = first_;
            while (current->next) {
                current = current->next;
            }
            current->next = temp;
        } else {
            // REVIEW
            first_ = temp;
            first_->next = nullptr;
        }
    }

    void PopFront() {
        if (IsEmpty()) {
            using namespace std;
            cout << "Nothing to Pop in PopFront()" << endl;
            return;
        }

        assert(first_);

        // REVIEW 메모리 삭제
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

        // REVIEW 메모리 삭제

        Node *prev = nullptr;
        Node *current = first_;
        Node *next = current->next;

        while (next) {
            prev = current;
            current = next;
            next = current->next;
        }
        prev->next = nullptr;
        delete current;
    }

    void Reverse() {
        // REVIEW

        Node *prev = nullptr;
        Node *current = first_;
        Node *next = current->next;

        while (next) {
            current->next = prev;
            prev = current;
            current = next;
            next = current->next;
        }
        current->next = prev;
        first_ = current;
    }

    void SetPrintDebug(bool flag) { print_debug_ = flag; }

    void Print() {
        using namespace std;

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