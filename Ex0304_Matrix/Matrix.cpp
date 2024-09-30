#include "Matrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Matrix::Matrix(int num_rows, int num_cols) {
    // REVIEW
    num_rows_ = num_rows;
    num_cols_ = num_cols;
    values_ = new float[num_cols_ * num_rows_];

    for (int i = 0; i < num_rows_ * num_cols_; i++) {
        values_[i] = 0.0f;
    }
}

// 복사 생성자 (b를 복사)
Matrix::Matrix(const Matrix &b) {
    // REVIEW
    Matrix temp(b.num_rows_, b.num_cols_);
    memcpy(temp.values_, b.values_, num_cols_ * num_rows_);
    delete[] values_;
    values_ = temp.values_;
    num_cols_ = temp.num_cols_;
    num_rows_ = temp.num_rows_;
}

Matrix::~Matrix() {
    // REVIEW
    delete[] values_;
    values_ = nullptr;
    num_cols_ = 0;
    num_rows_ = 0;
}

void Matrix::SetValue(int row, int col, float value) {
    // REVIEW
    int idx = col + row * num_cols_;
    values_[idx] = value;
}

float Matrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
    int idx = col + row * num_cols_;
    if (idx > num_cols_ * num_rows_) {
        return -1;
    }
    return values_[idx];
}

Matrix Matrix::Transpose() {
    // REVIEW
    Matrix temp(num_cols_, num_rows_); // num_cols_, num_rows_ 순서 주의
    for (int i = 0; i < num_rows_; i++) {
        for (int j = 0; j < num_cols_; j++) {
            temp.SetValue(j, i, this->GetValue(i, j));
        }
    }

    return temp;
}

Matrix Matrix::Add(const Matrix &b) {
    assert(b.num_cols_ == num_cols_);
    assert(b.num_rows_ == num_rows_);

    Matrix temp(num_rows_, num_cols_);

    // REVIEW
    for (int i = 0; i < num_rows_; i++) {
        for (int j = 0; j < num_cols_; j++) {
            temp.SetValue(i, j, this->GetValue(i, j) + b.GetValue(i, j));
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
