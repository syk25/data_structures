#pragma once

#include "Queue.h"

#include <cassert>
#include <iomanip>
#include <iostream>

// NOTE Double Ended Queue (덱, dequeue와 구분)
template <typename T>         // NOTE 덱은 템플릿 클래스
class Deque : public Queue<T> // NOTE 덱은 템플릿을 사용하는 큐 상속
{

    typedef Queue<T> Base; // NOTE 큐에 대해 별명 지음 -> 글자수 줄이기 위함

  public:
    Deque(int capacity) : Queue<T>(capacity) {}

    T &Front() { return Base::Front(); }

    T &Back() { return Base::Rear(); }

    void PushFront(const T &item) {
        if (Base::IsFull())
            Base::Resize();

        // REVIEW
        this->queue_[this->front_] = item;
        this->front_ = (this->front_ + this->capacity_ - 1) % this->capacity_;
    }

    void PushBack(const T &item) { Base::Enqueue(item); }

    void PopFront() { Base::Dequeue(); }

    void PopBack() {
        assert(!Base::IsEmpty());

        // REVIEW
        rear_ = (rear_ + capacity_ - 1) % capacity_;
    }

  private:
    // Queue와 동일
    // 상속받은 변수를 그대로 이름만 바꿔서 사용하고 싶은 경우
    int &rear_ = Base::rear_;
    int &capacity_ = Base::capacity_;
    int &front_ = Base::front_;
    char *&queue_ = Base::queue_;
};
