#pragma once

#include <cassert>
#include <iostream>

template <typename T> class Stack {
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

    // NOTE: const의 역할
    bool IsEmpty() const {
        if (top_ == -1) {
            return true;
        }
        return false;
    }

    // NOTE: const의 역할
    int Size() const { return top_ + 1; }

    void Print() {
        using namespace std; // NOTE: 해당코드가 함수 내에서도 쓰이네?

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

        if (top_ + 1 == capacity_) {
            Resize(2 * capacity_);
        }

        stack_[top_ + 1] = item;
        top_ += 1;
    }

    // Delete the TOP element of the stack
    void Pop() {
        assert(!IsEmpty());

        top_ -= 1;
    }

  protected: // 뒤에서 상속해서 사용
    T *stack_ = nullptr;
    int top_ = -1; // 0 아님 - 가장 마지막에 추가 된 원소의 인덱스
    int capacity_ = 0;
};
