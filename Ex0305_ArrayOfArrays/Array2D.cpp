#include "Array2D.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Array2D::Array2D(int num_rows, int num_cols) {
    // REVIEW

    num_cols_ = num_cols;
    num_rows_ = num_rows;

    arrays_ = new float *[num_rows_];
    for (int r = 0; r < num_rows_; r++) {
        arrays_[r] = new float[num_cols_];
    }

    for (int r = 0; r < num_rows_; r++) {
        for (int c = 0; c < num_cols_; c++) {
            arrays_[r][c] = 0.0f;
        }
    }
}

// 복사 생성자 (b를 복사)
Array2D::Array2D(const Array2D &b) {
    // REVIEW
    Array2D temp(b.num_rows_, b.num_cols_);

    for (int r = 0; r < b.num_rows_; r++) {
        for (int c = 0; c < b.num_cols_; c++) {
            temp.arrays_[r][c] = b.arrays_[r][c];
        }
    }

    arrays_ = temp.arrays_;
    num_cols_ = temp.num_cols_;
    num_rows_ = temp.num_rows_;
}

Array2D::~Array2D() {
    // REVIEW

    for (int i = 0; i < num_rows_; i++) {
        delete[] arrays_[i];
    }

    delete[] arrays_;
    num_cols_ = 0;
    num_rows_ = 0;
}

void Array2D::SetValue(int row, int col, float value) {
    // REVIEW
    arrays_[row][col] = value;
}

float Array2D::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
    // REVIEW

    return arrays_[row][col];
}

Array2D Array2D::Transpose() {
    Array2D temp(num_cols_, num_rows_); // num_cols_, num_rows_ 순서 주의

    for (int r = 0; r < num_rows_; r++)
        for (int c = 0; c < num_cols_; c++)
            temp.SetValue(c, r, GetValue(r, c));

    return temp;
}

Array2D Array2D::Add(const Array2D &b) {
    assert(b.num_cols_ == num_cols_);
    assert(b.num_rows_ == num_rows_);

    Array2D temp(num_rows_, num_cols_);

    for (int r = 0; r < num_rows_; r++)
        for (int c = 0; c < num_cols_; c++)
            temp.SetValue(r, c, GetValue(r, c) + b.GetValue(r, c));

    return temp;
}

void Array2D::Print() {
    for (int r = 0; r < num_rows_; r++) {
        for (int c = 0; c < num_cols_; c++)
            cout << GetValue(r, c) << " ";

        cout << endl;
    }
}
