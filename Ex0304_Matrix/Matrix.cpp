#include "Matrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Matrix::Matrix(int num_rows, int num_cols) {
    // REVIEW:
    num_rows_ = num_rows;
    num_cols_ = num_cols;
    values_ = new float[num_rows_ * num_cols_];
}

// 복사 생성자 (b를 복사)
Matrix::Matrix(const Matrix &b) {
    // REVIEW:
    num_rows_ = b.num_rows_;
    num_cols_ = b.num_cols_;

    this->values_ = new float[num_rows_ * num_cols_];

    for (int r = 0; r < num_rows_; r++) {
        for (int c = 0; c < num_cols_; c++) {
            int idx = c + num_cols_ * r - 1;
            this->values_[idx] = b.values_[idx];
        }
    }
}

Matrix::~Matrix() {
    // REVIEW:
    delete[] this->values_; // NOTE: 문법의 의미 정리하기 -> 제대로 안하면 segmentation fault 발생
}

void Matrix::SetValue(int row, int col, float value) {
    // values_[TODO] = value;
    int idx = col + row * this->num_cols_ - 1;
    this->values_[idx] = value;
}

float Matrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
    int idx = col + row * this->num_cols_ - 1;
    return this->values_[idx];
}

Matrix Matrix::Transpose() {
    Matrix temp(num_cols_, num_rows_); // num_cols_, num_rows_ 순서 주의

    // TODO:
    for (int r = 0; r < num_rows_; r++) {
        for (int c = 0; c < num_cols_; c++) {
            int temp_idx = r + c * num_rows_ - 1;
            int this_idx = c + r * num_cols_ - 1;
            temp.values_[temp_idx] = this->values_[this_idx];
        }
    }
    return temp;
}

Matrix Matrix::Add(const Matrix &b) {
    assert(b.num_cols_ == num_cols_);
    assert(b.num_rows_ == num_rows_);

    Matrix temp(num_rows_, num_cols_);

    // REVIEW:
    for (int r = 0; r < num_rows_; r++) {
        for (int c = 0; c < num_cols_; c++) {
            int idx = c + num_cols_ * r - 1;
            temp.values_[idx] = this->values_[idx] + b.values_[idx];
        }
    }
    return temp;
}

void Matrix::Print() {
    for (int r = 0; r < num_rows_; r++) {
        for (int c = 0; c < num_cols_; c++)
            cout << GetValue(r, c) << " ";

        cout << endl;
    }
}
