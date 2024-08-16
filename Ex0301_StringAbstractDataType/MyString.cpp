#include "MyString.h"

using namespace std;

/* MyString 생성자 정의 */
// 비어 있는 MyString() 생성
MyString::MyString() {
    str_ = nullptr;
    size_ = 0;
    // NOTE: 클래스의 private 멤버가 선언되었음에도 별도로 해야하는가?
}

// 맨 뒤에 널 캐릭터'\0'가 들어 있는 문자열로부터 초기화
MyString::MyString(const char *init) {
    // 크기(size_) 결정
    size_ = 0;
    while (init[size_] != '\0')
        size_++; // REVIEW: 프로그램에서 지정할 수 있게끔 로직을 짤 것

    // 메모리 할당
    str_ = new char[size_]; // REVIEW: private 멤버변수에 새로운 배열을 선언(할당)

    // 데이터 복사
    memcpy(str_, init, size_); // 블럭단위로 복사
}

// MyString의 다른 instance로부터 초기화
MyString::MyString(const MyString &str) { // NOTE: 복사생성자임
    // 기본 복사 생성자는 포인터 주소만 복사하기 때문에
    // 소멸시 오류 발생
    // 여기서는 새로 메모리를 할당 받아서 복사
    size_ = str.size_;
    char *copied[size_];
    memcpy(str_, str.str_, size_);
}

MyString::~MyString() {
    // 메모리 해제
    /* free(str_);
    size_ = 0; */

    if (str_ != nullptr) {
        delete[] str_; // NOTE: 여긴 어디?
        str_ = nullptr;
        size_ = 0;
    }
}

bool MyString::IsEmpty() { return Length() == 0; }

bool MyString::IsEqual(const MyString &str) // 편의상 참조& 사용
{
    // 힌트: str.str_, str.size_ 가능
    if (this->size_ != str.size_) { // NOTE: this의 역할
        return false;
    }
    for (int i = 0; i < this->size_; i++) {
        if (str_[i] != str.str_[i]) {
            return false;
        }
    }
    return true;
}

int MyString::Length() { return size_; }

void MyString::Resize(int new_size) {
    // 메모리 재할당과 원래 갖고 있던 내용 복사
    if (new_size != size_) {

        // 크기에 맞게 새로운 문자열 생성
        char *new_str = new char[new_size]; // NOTE: cpp에서 문자열을 선언하는 법

        for (int i = 0; i < (new_size < size_ ? new_size : size_); i++) {
            new_str[i] = str_[i];
        }
        delete[] str_;
        str_ = new_str;
        size_ = new_size;
    }
}

// 인덱스 start위치의 글자부터 num개의 글자로 새로운 문자열 만들기
MyString MyString::Substr(int start, int num) {
    // 복사할 인덱스: start, start + 1, ... , start + num - 1
    // assert(start + num - 1 < this->size_); // 문제를 단순하게 만들기 위해
    // 가정

    MyString temp;

    // TODO:
    // temp.size_ = num;
    temp.Resize(num); // 로직을 추가할 때 기존에 정의한 로직을 활용

    for (int i = 0; i < num; i++) {
        temp.str_[i] = this->str_[start + i];
    }

    return temp;
}

MyString MyString::Concat(MyString app_str) {
    MyString temp;

    // TODO:

    temp.Resize(this->size_ + app_str.size_);

    memcpy(temp.str_, this->str_, this->size_);
    memcpy(&temp.str_[this->size_], app_str.str_, app_str.size_);
    return temp;
}

MyString MyString::Insert(MyString t, int start) {
    assert(start >= 0);
    assert(start <= this->size_);

    MyString temp;

    // TODO:
    temp.Resize(this->size_ + t.size_);

    for (int i = 0; i < start; i++) {
        temp.str_[i] = this->str_[i];
    }
    for (int i = start; i < t.size_; i++) {
        temp.str_[i] = t.str_[i - start];
    }
    for (int i = t.size_; i < temp.size_; i++) {
        temp.str_[i] = this->str_[i - t.size_];
    }

    return temp;
}

int MyString::Find(MyString pat) {
    // TODO:

    for(int start = 0; start <= Length() - pat.Length(); start++){
        for(int j = 0; j < pat.Length(); j++){
            if((str_[start + j]) != pat.str_[j]){
                break;
            }

            if(j == pat.Length() - 1){
                return start;
            }
        }
    }
}

void MyString::Print() {
    for (int i = 0; i < size_; i++)
        cout << str_[i];
    cout << endl;
}
