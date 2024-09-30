#include "MyString.h"

using namespace std;

// 비어 있는 MyString() 생성
MyString::MyString() {
    str_ = nullptr;
    size_ = 0;
}

// 맨 뒤에 널 캐릭터'\0'가 들어 있는 문자열로부터 초기화
// REVIEW
MyString::MyString(const char *init) {

    for (int i = 0; init[i] != '\0'; i++) {
        size_++;
    }

    str_ = new char[size_];

    memcpy(str_, init, size_);
}

// MyString의 다른 instance로부터 초기화
// NOTE: memcpy 대신에 반복문을 활용해서 복사를 함
MyString::MyString(const MyString &str) {
    // 기본 복사 생성자는 포인터 주소만 복사하기 때문에
    // 소멸시 오류 발생
    // 여기서는 새로 메모리를 할당 받아서 복사

    str_ = new char[str.size_];
    size_ = str.size_;

    for (int i = 0; i < str.size_; i++) {
        str_[i] = str.str_[i];
    }
}

MyString::~MyString() {
    // 메모리 해제
    if (str_ != nullptr) {
        delete[] str_;
        str_ = nullptr;
        size_ = 0;
    }
}

bool MyString::IsEmpty() { return Length() == 0; }

// REVIEW
bool MyString::IsEqual(const MyString &str) // 편의상 참조& 사용
{
    // 힌트: str.str_, str.size_ 가능
    if (size_ != str.size_) {
        return false;
    }

    for (int i = 0; i < size_; i++) {
        if (str_[i] != str.str_[i]) {
            return false;
        }
    }
    return true;
}

int MyString::Length() { return size_; }

// REVIEW
void MyString::Resize(int new_size) {
    // 메모리 재할당과 원래 갖고 있던 내용 복사

    if (new_size == size_) {
        return;
    }

    MyString temp;
    temp.str_ = new char[new_size];

    memcpy(temp.str_, str_, size_);
    delete[] str_;
    str_ = temp.str_;
    size_ = new_size;
}

// 인덱스 start위치의 글자부터 num개의 글자로 새로운 문자열 만들기
MyString MyString::Substr(int start, int num) {
    // 복사할 인덱스: start, start + 1, ... , start + num - 1
    // assert(start + num - 1 < this->size_); // 문제를 단순하게 만들기 위해 가정

    MyString temp;

    // REVIEW:
    temp.str_ = new char[num];
    for (int i = 0; i < num; i++) {
        temp.str_[i] = str_[start + i];
    }
    temp.size_ = num;

    return temp;
}

MyString MyString::Concat(MyString app_str) {
    MyString temp;

    // REVIEW:
    temp.size_ = size_ + app_str.size_;
    temp.str_ = new char[temp.size_];

    memcpy(temp.str_, str_, size_);
    memcpy((temp.str_ + size_), app_str.str_, app_str.size_);

    return temp;
}

MyString MyString::Insert(MyString t, int start) {
    assert(start >= 0);
    assert(start <= this->size_);

    MyString temp;

    // REVIEW:
    temp.size_ = size_ + t.size_;
    temp.str_ = new char[temp.size_];

    for (int i = 0; i < start; i++) {
        temp.str_[i] = str_[i];
    }

    for (int i = 0; i < t.size_; i++) {
        temp.str_[start + i] = t.str_[i];
    }

    for (int i = start; i < size_; i++) {
        temp.str_[t.size_ + i] = str_[i];
    }

    return temp;
}

int MyString::Find(MyString pat) {
    // REVIEW
    int count;
    for (int i = 0; i < size_; i++) {
        count = 0;
        for (int j = 0; j < pat.size_; j++) {
            if (str_[i + j] != pat.str_[j]) {
                break;
            }
            count++;
        }
        if (count == pat.size_) {
            return i;
        }
    }
    return -1;
}

void MyString::Print() {
    for (int i = 0; i < size_; i++)
        cout << str_[i];
    cout << endl;
}
