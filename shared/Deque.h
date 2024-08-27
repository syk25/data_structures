#pragma once

#include "Queue.h"

#include <cassert>
#include <iomanip>
#include <iostream>

// Double Ended Queue (덱, dequeue와 구분)
template <typename T> class Deque : public Queue<T> {

    typedef Queue<T> Base;

  public:
    Deque(int capacity) : Queue<T>(capacity) {}

    T &Front() { return Base::Front(); }

    T &Back() { return Base::Rear(); }

    void PushFront(const T &item) {
        if (Base::IsFull())
            Base::Resize();

        // REVIEW:
        Base::queue_[Base::front_] = item;
        if (Base::front_ == 0) {
            Base::front_ = Base::capacity_ - 1;
        } else {
            Base::front_--;
        }
    }

    void PushBack(const T &item) { Base::Enqueue(item); }

    void PopFront() { Base::Dequeue(); }

    void PopBack() {
        assert(!Base::IsEmpty());

        // REVIEW:
        if (Base::rear_ == 0) {
            Base::rear_ = Base::capacity_ - 1;
        } else {
            Base::rear_--;
        }
    }

  private:
    // Queue와 동일
};
