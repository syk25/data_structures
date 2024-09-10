#include "../shared/SinglyLinkedList.h"
#include <iostream>

using namespace std;

struct Term {
    float coef;
    int exp;
};

class LinkedPolynomial : public SinglyLinkedList<Term> {
  public:
    typedef SinglyLinkedList<Term>::Node Node;

    void NewTerm(float coef, int exp) {
        // REVIEW: 다항식에 새로운 항 추가하기
        // 첫항이 비어있다면? 그냥 추가하기

        // 항 생성하기
        Term *t = new Term;
        t->coef = coef;
        t->exp = exp;

        // 항을 노드에 대입하기

        if (!IsEmpty()) {
            Node *current = first_;
            Node *prev = current;
            while (true) {
                if (t->exp > current->item.exp) {
                    if (current->next) {
                        prev = current;
                        current = current->next;
                    } else {
                        PushBack(*t);
                        break;
                    }

                } else if (t->exp < current->item.exp) {
                    InsertBack(prev, *t);
                    break;
                } else {
                    current->item.coef += t->coef;
                    break;
                }
            }
        } else {
            PushFront(*t);
        }
    }

    float Eval(float x) {
        float temp = 0.0f;

        // TODO: 계산하기

        return temp;
    }

    LinkedPolynomial Add(const LinkedPolynomial &poly) {
        // this와 poly의 terms_가 exp의 오름차순으로 정렬되어 있다고 가정
        // 하나의 다항식 안에 exp가 중복되는 term이 없다라고 가정 (한 exp는 하나의 term만 존재)

        LinkedPolynomial temp;

        Node *i = this->first_;
        Node *j = poly.first_;

        // TODO: 항끼리 더하기

        return temp;
    }

    void Print() {
        using namespace std;
        bool is_first = true; // 더하기 출력시 확인용

        // REVIEW:

        Node *current = first_;

        if (IsEmpty())
            cout << "Empty" << endl;
        else {
            cout << "Size = " << Size() << ": ";

            while (current) {

                if (current->item.exp != 0) {
                    cout << current->item.coef << "*x^" << current->item.exp;
                } else {
                    cout << current->item.coef;
                }

                if (current->next)
                    cout << " + ";
                else
                    cout << endl;

                current = current->next;
            }
            cout << endl;
        }
    }

  private:
};

int main() {
    using namespace std;

    LinkedPolynomial p1;

    // exp가 작은 항부터 추가한다고 가정
    p1.NewTerm(1.0f, 0); // 1 * x^0 = 1
    p1.NewTerm(1.5f, 1); // 1.5 * x^1
    p1.NewTerm(2.0f, 2); // 2 * x^2

    p1.Print(); // 1 + 1.5*x^1 + 2*x^2
    exit(-1);

    cout << p1.Eval(0.0f) << endl; // 1 + 1.5*0 + 2*0^2 = 1
    cout << p1.Eval(1.0f) << endl; // 1 + 1.5*1 + 2*1^2 = 4.5
    cout << p1.Eval(2.0f) << endl; // 1 + 1.5*2 + 2*2^2 = 1 + 3 + 8 = 12

    cout << endl;

    // Add() Test1
    cout << "Add() Test" << endl;
    {
        LinkedPolynomial p1; // max_degree는 기본값으로 설정

        // exp가 작은 항부터 추가한다고 가정
        p1.NewTerm(1.0f, 0);
        p1.NewTerm(1.5f, 1);
        p1.NewTerm(2.0f, 2);

        p1.Print(); // 1 + 1.5*x^1 + 2*x^2

        LinkedPolynomial p2;

        // exp가 작은 항부터 추가한다고 가정
        p2.NewTerm(1.0f, 1);
        p2.NewTerm(3.0f, 2);
        p2.NewTerm(5.0f, 7);
        p2.NewTerm(2.0f, 11);

        p2.Print(); // 1*x^1 + 3*x^2 + 5*x^7 + 2*x^11

        cout << endl;

        LinkedPolynomial psum = p1.Add(p2);
        psum.Print(); // 1 + 2.5*x^1 + 5*x^2 + 5*x^7 + 2*x^11

        cout << endl;
    }

    // Add() Test2
    cout << "Add() Test2" << endl;
    {
        LinkedPolynomial p1; // max_degree는 기본값으로 설정

        // exp가 작은 항부터 추가한다고 가정
        p1.NewTerm(1.0f, 0);
        p1.NewTerm(1.5f, 1);
        p1.NewTerm(2.0f, 2);
        p1.NewTerm(5.0f, 7);
        p1.NewTerm(3.5f, 10);
        p1.NewTerm(5.5f, 20);
        p1.NewTerm(5.0f, 1000);

        p1.Print(); // 1 + 1.5*x^1 + 2*x^2 + 5*x^7 + 3.5*x^10 + 5.5*x^20 + 5*x^1000

        LinkedPolynomial p2;

        // exp가 작은 항부터 추가한다고 가정
        p2.NewTerm(3.2f, 0);
        p2.NewTerm(1.0f, 1);
        p2.NewTerm(3.0f, 2);
        p2.NewTerm(2.0f, 11);

        p2.Print(); // 3.2 + 1*x^1 + 3*x^2 + 2*x^11

        cout << endl;

        LinkedPolynomial psum = p1.Add(p2);
        psum.Print(); // 4.2 + 2.5*x^1 + 5*x^2 + 5*x^7 + 3.5*x^10 + 2*x^11 + 5.5*x^20 + 5*x^1000

        cout << endl;
    }

    return 0;
}
