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

    void Clear() // 모두 지워야(delete) 합니다.
    {
        // REVIEW:
        if (!first_) {
            return;
        }

        Node *will_be_deleted = first_;
        Node *next_will_be_deleted = will_be_deleted->right;

        while (next_will_be_deleted) {
            delete will_be_deleted;
            will_be_deleted = next_will_be_deleted;
            next_will_be_deleted = next_will_be_deleted->right;
        }
        delete will_be_deleted;
    }

    bool IsEmpty() {
        // REVIEW:
        if (first_ == nullptr) {

            return true;
        }
        return false;
    }

    int Size() {
        int size = 0;

        // REVIEW
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
        // REVIEW
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
            // REVIEW

            Node *new_node = new Node;
            new_node->item = item;

            new_node->left = node;
            new_node->right = node->right;

            node->right->left = new_node;
            node->right = new_node;
        }
    }

    void PushFront(T item) {
        // REVIEW:

        Node *new_node = new Node;
        new_node->item = item;

        if (IsEmpty()) {
            first_ = new_node;
            first_->left = nullptr;
            first_->right = nullptr;
        } else {
            new_node->right = first_;
            new_node->left = nullptr;

            first_->left = new_node;
            first_ = new_node;
        }
    }

    void PushBack(T item) {
        // REVIEW:

        Node *new_node = new Node;
        new_node->item = item;

        if (IsEmpty()) {
            first_ = new_node;
            first_->left = nullptr;
            first_->right = nullptr;
        } else {
            Node *current = first_;
            while (current->right) {
                current = current->right;
            }

            new_node->right = nullptr;
            new_node->left = current;

            current->right = new_node;
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
        Node *deleting_node = first_;
        first_ = deleting_node->right;
        first_->left = nullptr;

        delete deleting_node;
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
        while (current->right) {
            current = current->right;
        }
        current->left->right = nullptr;
        delete current;
    }

    void Reverse() {
        // REVIEW
        Node *current = first_;
        Node *temp;
        while (current) {

            temp = current->left;

            current->left = current->right;
            current->right = temp;

            current = current->left;
        }
        first_ = temp->left;
    }

    T Front() {
        // REVIEW
        assert(first_);

        return first_->item;
    }

    // REVIEW
    T Back() {
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