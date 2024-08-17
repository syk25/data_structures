#include "Polynomial.h" // Polynomial 에 있는 코드들을 사용할 수 있음

#include <iostream>

int main() {
    using namespace std;

    Polynomial p1; // max_degree는 기본값으로 설정

    /* 항 추가 */
    p1.NewTerm(1, 0);    // 1 * x^0 = 1
    p1.NewTerm(1.5f, 1); // 1.5 * x^1
    p1.NewTerm(2, 2);    // 2 * x^2

    /* 출력 */
    p1.Print(); // 1 + 1.5*x^1 + 2*x^2

    /* 다항식의 변수에 값을 대입할 경우 그 결과 */
    cout << p1.Eval(0.0f) << endl; // 1 + 1.5*0 + 2*0^2 = 1
    cout << p1.Eval(1.0f) << endl; // 1 + 1.5*1 + 2*1^2 = 4.5
    cout << p1.Eval(2.0f) << endl; // 1 + 1.5*2 + 2*2^2 = 1 + 3 + 8 = 12

    cout << endl;

    Polynomial p2;

    p2.NewTerm(1, 1);
    p2.NewTerm(3, 2);

    p2.Print(); // 1*x^1 + 3*x^2

    cout << endl;

    cout << "Add()" << endl;

    Polynomial psum = p1.Add(p2);
    psum.Print(); // 1 + 2.5*x^1 + 5*x^2

    cout << endl;

    cout << "Mult()" << endl;

    p1.Print(); // 1 + 1.5*x^1 + 2*x^2
    p2.Print(); // 1*x^1 + 3*x^2

    Polynomial pmul = p1.Mult(p2);
    pmul.Print(); // 1*x^1 + 4.5*x^2 + 6.5*x^3 + 6*x^4

    return 0;
}
