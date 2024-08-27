#include <iostream>

#include "../shared/Stack.h" // 경로 "shared" 주의

int main() {
    using namespace std;

    // 일종의 가방(bag), 컨테이너(container)
    // LIFO(Last-In-First-Out)

    Stack<char> s; // 스택의 원소 자료형: char

    s.Push('A');
    s.Print(); // A

    s.Push('B');
    s.Print(); // A B

    s.Push('C');
    s.Print(); // A B C

    cout << "Top = " << s.Top() << endl; // C : 가장 위에 있는 원소 반환

    s.Pop();   // 가장 위 원소(C) 제거
    s.Print(); // A B

    cout << "Top = " << s.Top() << endl; // B

    s.Pop();   // B 제거
    s.Print(); // A

    s.Push('E');
    s.Print(); // A E

    s.Pop();
    s.Print(); // A

    cout << "Top = " << s.Top() << endl; // A

    s.Pop(); // 빈 스택

    // cout << "Top = " << s.Top() << endl; // 비었을 때 Top() 불가

    // 다른 자료형의 stack도 쉽게 만들 수 있어요.
    {
        Stack<int> int_stack;
        int_stack.Push(123);
        cout << int_stack.Top() << endl;
        int_stack.Top();
    }

    // 문자열 순서 뒤집어서 출력하기 (스택 사용하기 연습)
    {
        const char str[] = "Hello, World!";
        const int size = sizeof(str) - 1; // 마지막 '\0' 제외

        cout << "Input: " << str << endl;

        Stack<char> stack;
        for (int i = 0; i < size; i++) {
            stack.Push(str[i]);
        }

        // TODO:
        for (int i = stack.Size() - 1; i >= 0; i--) {
            cout << stack.Top();
            stack.Pop();
        }
        cout << endl;
    }

    return 0;
}
