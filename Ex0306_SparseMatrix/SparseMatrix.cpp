#include "SparseMatrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix(int num_rows, int num_cols, int capacity) {
    // REVIEW
    num_rows_ = num_rows;
    num_cols_ = num_cols;
    capacity_ = capacity;
    num_terms_ = 0;
    terms_ = new MatrixTerm[capacity_];
}

// 복사 생성자 (b를 복사)
SparseMatrix::SparseMatrix(const SparseMatrix &b) {
    // REVIEW
    num_rows_ = b.num_rows_;
    num_cols_ = b.num_cols_;
    capacity_ = b.capacity_;

    memcpy(terms_, b.terms_, b.num_terms_);
}

SparseMatrix::~SparseMatrix() {
    // REVIEW
    delete[] terms_;
    num_rows_ = 0;
    num_cols_ = 0;
    capacity_ = 0;
    num_terms_ = 0;
}

void SparseMatrix::SetValue(int row, int col, float value) {
    if (value == 0.0f)
        return; // value가 0이 아닌 term만 저장
    MatrixTerm temp = {row, col, value};

    terms_[num_terms_++] = temp;

    // REVIEW

    // 열 기준 정렬
    for (int i = 0; i < num_terms_ - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < num_terms_; j++) {
            if (terms_[min_idx].col > terms_[j].col) {
                min_idx = j;
            }
        }
        std::swap(terms_[i], terms_[min_idx]);
    }

    // 행 기준 우선 정렬 - 선택정렬로 구현해보기
    for (int i = 0; i < num_terms_ - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < num_terms_; j++) {
            if (terms_[min_idx].row > terms_[j].row) {
                min_idx = j;
            }
        }
        std::swap(terms_[i], terms_[min_idx]);
    }
}

float SparseMatrix::GetValue(int row,
                             int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
    // REVIEW key = col + num_cols * row;
    int key = col + num_cols_ * row;
    if (key >= num_cols_ * num_rows_) {
        return 0.0f;
    }

    for (int i = 0; i < capacity_; i++) {
        int key_candidate = terms_[i].col + terms_[i].row * num_cols_;
        if (key == key_candidate) {
            return terms_[i].value;
        } else if (key_candidate > key) {
            return 0.0f;
        }
    }
    return 0.0f;
}

SparseMatrix SparseMatrix::Transpose() {
    SparseMatrix temp(num_cols_, num_rows_, capacity_); // num_cols_, num_rows_ 순서 주의

    // REVIEW
    for (int i = 0; i < capacity_; i++) {
        temp.SetValue(terms_[i].col, terms_[i].row, terms_[i].value);
    }

    return temp;
}

void SparseMatrix::PrintTerms() {
    for (int i = 0; i < num_terms_; i++)
        cout << "(" << terms_[i].row << ", " << terms_[i].col << ", " << terms_[i].value << ")" << endl;
}

void SparseMatrix::Print() {
    for (int r = 0; r < num_rows_; r++) {
        for (int c = 0; c < num_cols_; c++)
            cout << GetValue(r, c) << " ";
        cout << endl;
    }
}
