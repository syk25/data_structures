#include <algorithm> // swap
#include <cassert>
#include <iomanip> // setw
#include <iostream>

using namespace std;

int Fibonacci(int n) {

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int fn = 0;
        int temp = 1;
        int fibo;

        for (int i = 0; i < n -2; i++) {
            fibo = fn + temp;
            fn = temp;
            temp = fibo;
        }

        return fibo;
    }
}

int RecurFibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    return RecurFibonacci(n - 1) + RecurFibonacci(n - 2);
}

int main() {
    // Input      : 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14
    // Fibonnacci : 0   1   1   2   3   5   8  13  21  34  55  89 144 233 377
    // Fibonnacci : 0   1   1   2   3   5   8  13  21  34  55  89 144 233 377

    cout << "Input     : ";
    for (int i = 0; i < 15; i++)
        cout << setw(3) << i << " ";
    cout << endl;

    // Fibonnacci
    cout << "Fibonnacci: ";
    for (int i = 0; i < 15; i++)
        cout << setw(3) << Fibonacci(i) << " ";
    cout << endl;

    cout << "Fibonnacci: ";
    for (int i = 0; i < 15; i++)
        cout << setw(3) << RecurFibonacci(i) << " ";
    cout << endl;

    return 0;
}
