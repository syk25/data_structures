#pragma once

#include <algorithm>
#include <cassert>
#include <stdint.h>

template <typename T> class DoublyLinkedList {
  public:
    struct Node {
        T item = T();

        Node *left = nullptr;
        Node *right = nullptr;

        // 참고: prev/next가 아니라 left/right
    };

    DoublyLinkedList() {}

    ~DoublyLinkedList() { Clear(); }

    void Clear() {
        // REVIEW:
        // 모두 지워야(delete) 합니다.
        Node *current = first_;
        Node *next = current->right;
        while (next) {
            delete current;
            current = next;
            next = current->right;
        }
        delete current;
    }

    bool IsEmpty() {
        // REVIEW:
        if (Size()) {
            return false;
        }
        return true;
    }

    int Size() {
        int size = 0;

        // REVIEW:
        Node *current = first_;
        while (current) {
            size += 1;
            current = current->right;
        }
        return size;
    }

    void Print() {
        using namespace std;

        Node *current = first_;

        if (IsEmpty())
            cout << "Empty" << endl;
        else {
            cout << "Size = " << Size() << endl;

            cout << " Forward: ";
            // REVIEW:
            Node *current = first_;
            Node *prev;
            while (current) {
                cout << current->item << " ";
                prev = current;
                current = current->right;
            }
            cout << endl;

            cout << "Backward: ";
            // REVIEW:
            current = prev;
            while (current) {
                cout << current->item << " ";
                current = current->left;
            }
            cout << endl;
        }
    }

    Node *Find(T item) {
        // REVIEW:
        Node *current = first_;
        while (current) {
            if (current->item == item) {
                return current;
            }
            current = current->right;
        }
        return nullptr;
    }

    void InsertBack(Node *node, T item) {
        if (IsEmpty()) {
            PushBack(item);
        } else {
            // REVIEW:
            Node *temp = new Node;
            temp->item = item;

            temp->left = node;
            temp->right = node->right;

            node->right->left = temp;

            node->right = temp;
        }
    }

    void PushFront(T item) {
        // REVIEW:

        Node *temp = new Node;
        temp->item = item;

        if (IsEmpty()) {
            first_ = temp;
        } else {
            temp->right = first_;
            first_->left = temp;
            first_ = temp;
        }
    }

    void PushBack(T item) {
        // REVIEW:
        Node *temp = new Node;
        temp->item = item;

        if (IsEmpty()) {
            first_ = temp;
        } else {
            Node *current = first_;
            while (current->right) {
                current = current->right;
            }
            current->right = temp;
            temp->left = current;
        }
    }

    void PopFront() {
        if (IsEmpty()) {
            using namespace std;
            cout << "Nothing to Pop in PopFront()" << endl;
            return;
        }

        assert(first_);

        // REVIEW
        Node *current = first_;
        if (!current->right) {
            delete current;
        }
        first_ = current->right;
        first_->left = nullptr;
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

        // REVIEW
        Node *current = first_;
        Node *prev = nullptr;

        if (!current->right) {
            delete current;
            first_ = nullptr;
            return;
        }

        while (current) {
            prev = current;
            current = current->right;
        }
        prev->left->right = nullptr;

        prev->left = nullptr;
        delete prev;
    }

    void Reverse() {
        // REVIEW:
        Node *main = first_;
        Node *next = nullptr;
        Node *prev = nullptr;

        if (IsEmpty()) {
            return;
        }

        while (main) {
            next = main->right;

            Node *temp = main->left;
            main->left = main->right;
            main->right = temp;

            prev = main;
            main = next;
        }
        first_ = prev;
    }

    T Front() {

        // REVIEW:
        assert(first_);

        return first_->item;
    }

    T Back() {
        // REVIEW:
        assert(first_);
        Node *current = first_;
        while (current->right) {
            current = current->right;
        }
        return current->item;
    }

  protected:
    Node *first_ = nullptr;
};