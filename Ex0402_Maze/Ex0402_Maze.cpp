#include <iostream>

#include "../shared/Stack.h"

using namespace std;

constexpr int kNumRows = 10;
constexpr int kNumCols = 9;

char maze[kNumRows][kNumCols] = {
    {'1', '1', '1', '1', '1', '1', '1', '1', '1'}, {'1', 'S', '0', '0', '0', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '0', '1', '0', '1', '1'}, {'1', '0', '0', '0', '0', '0', '0', '0', '1'},
    {'1', '0', '1', '1', '1', '1', '1', '1', '1'}, {'1', '0', '0', '0', '0', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '0', '1', '1', '1'}, {'1', '1', '1', '0', '0', '0', '1', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '0', 'G', '1'}, // <- 'G'를 만나면 종료
    {'1', '1', '1', '1', '1', '1', '1', '1', '1'},
};

void PrintMaze() {
    for (int j = 0; j < kNumRows; j++) {
        for (int i = 0; i < kNumCols; i++)
            cout << maze[j][i] << " ";
        cout << endl;
    }
}

struct Pos {
    int row;
    int col;

    // 디버깅을 위한 편의 기능
    friend ostream &operator<<(ostream &os, const Pos &pos) {
        cout << "(" << pos.row << ", " << pos.col << ")" << flush;
        return os;
    }
};

/* 완전탐색 후 종료 */
// void RecurMaze(Pos p) {

//     const char mark = maze[p.row][p.col]; // 상수화 및 고정

//     // 해당지점의 표시를 먼저 확인한다
//     // 'G'인 경우 종료
//     if (mark == 'G') {
//         cout << "Found!" << endl;
//         return;
//     }
//     // 'G'가 아닌 경우
//     // '1'인 경우 : return
//     // 'x'인 경우 : return
//     // 'o'인 경우 : x 표시하고 다른 방향으로 이동

//     if (mark == '1' || mark == 'X')
//         return;

//     maze[p.row][p.col] = 'X';

//     RecurMaze({p.row + 1, p.col});
//     RecurMaze({p.row - 1, p.col});
//     RecurMaze({p.row, p.col + 1});
//     RecurMaze({p.row, p.col - 1});
// }

int RecurMaze(Pos p) {

    cout << p << " ";

    const char mark = maze[p.row][p.col]; // 상수화 및 고정
    // 해당지점의 표시를 먼저 확인한다
    // 'G'인 경우 종료
    if (mark == 'G') {
        cout << "Found!" << endl;
        return 1;
    }
    // 'G'가 아닌 경우
    // '1'인 경우 : return
    // 'x'인 경우 : return
    // 'o'인 경우 : x 표시하고 다른 방향으로 이동

    if (mark != '1' && mark != 'X') {
        maze[p.row][p.col] = 'X';

        if (RecurMaze({p.row + 1, p.col}))
            return 1;
        if (RecurMaze({p.row - 1, p.col}))
            return 1;
        if (RecurMaze({p.row, p.col + 1}))
            return 1;
        if (RecurMaze({p.row, p.col - 1}))
            return 1;
    }
    return 0;
}

void StackMaze() {
    Stack<Pos> s;

    Pos start = {1, 1}; // i = 1, j = 1  시작 지점
    // Pos start;
    // start.row = 1;
    // start.col = 1;

    s.Push(start); // s.Push({1, 1});

    // s.Print(); // 디버깅에 사용 가능

    while (!s.IsEmpty()) {
        Pos p = s.Top();
        s.Pop();

        cout << p << " "; // 디버깅 출력

        const char mark = maze[p.row][p.col];

        if (mark == 'G') {
            cout << "Found!" << endl;
            break;
        }

        // TODO:
        // 1, x 인 경우에는 넣지 않음
        // 0 인 경우에는 넣기

        if (mark != '1' && mark != 'X') {
            maze[p.row][p.col] = 'X';
            s.Push({p.row + 1, p.col});
            s.Push({p.row - 1, p.col});
            s.Push({p.row, p.col + 1});
            s.Push({p.row, p.col - 1});
        }
    }
}

int main() {
    PrintMaze();

    // RecurMaze({1, 1}); // 1,1 에서 미로찾기 시작

    StackMaze();

    cout << endl << "-----result-----" << endl << endl;

    PrintMaze();

    return 0;
}
