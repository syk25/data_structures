#pragma once

class Polynomial {
  public:
    /* 생성자 */
    Polynomial(int max_degree = 100);
    Polynomial(const Polynomial &poly);

    /* 소멸자 */
    ~Polynomial();

    int MaxDegree();

    /* 다항식에 새로운 항 추가 */
    void NewTerm(const float coef, const int exp);

    /* 덧셈 연산 */
    Polynomial Add(const Polynomial &poly);

    /* 곱셈 연산 */
    Polynomial Mult(const Polynomial &poly);

    /* 값 대입 */
    float Eval(float x);

    /* 출력 */
    void Print();

  private:
    int capacity_ = 0; // 항상 모든 항(term)들이 다 차 있는 것은 아니기 때문에
                       // size 대신 capacity 사용
    float *coeffs_ = nullptr; // 각항들을 계수로 구분하고 계수를 인덱스로 배열로 다루려고 함
};