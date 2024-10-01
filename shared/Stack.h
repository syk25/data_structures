﻿#pragma once

#include <cassert>
#include <iostream>

template <typename T> // 템플릿 사용
class Stack {
  public:
    Stack(int capacity = 1) {
        assert(capacity > 0);
        Resize(capacity);
    }

    ~Stack() {
        if (stack_)
            delete[] stack_;
    }

    void Resize(int new_capacity) {
        T *new_stack = new T[new_capacity];
        memcpy(new_stack, stack_, sizeof(T) * Size());
        if (stack_)
            delete[] stack_;
        stack_ = new_stack;
        capacity_ = new_capacity;
    }

    // REVIEW
    bool IsEmpty() const {
        if (top_ == -1) {
            return true;
        }
        return false;
    }

    // REVIEW
    int Size() const { return top_ + 1; }

    void Print() {
        using namespace std;

        for (int i = 0; i < Size(); i++) // Size() 사용
            cout << stack_[i] << " ";
        cout << endl;
    }

    // Returns TOP element of stack.
    T &Top() const {
        assert(!IsEmpty());

        return stack_[top_];
    }

    // Insert item into the TOP of the stack
    void Push(const T &item) {
        // REVIEW 필요하면 리사이즈
        if (top_ == capacity_ - 1) {
            Resize(capacity_ * 2);
        }
        // REVIEW
        stack_[++top_] = item;
    }

    // Delete the TOP element of the stack
    void Pop() {
        assert(!IsEmpty());

        // REVIEW
        top_--;

    }

  protected: // 뒤에서 상속해서 사용
    T *stack_ = nullptr;
    int top_ = -1; // 0 아님
    int capacity_ = 0;
};
