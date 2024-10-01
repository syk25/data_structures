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

/* void RecurMaze(Pos p) {
    const char mark = maze[p.row][p.col];

    if (mark == 'G') {
        cout << "Found!" << endl;
        return;
    }

    // 방문한 장소가 아닌 경우이고 1이 아닌 경우 x 표시 후에 다음 장소로 이동 ||
    if (mark != 'X' && mark != '1') {
        maze[p.row][p.col] = 'X';

        RecurMaze({p.row + 1, p.col + 0});
        RecurMaze({p.row - 1, p.col + 0});
        RecurMaze({p.row + 0, p.col + 1});
        RecurMaze({p.row + 0, p.col - 1});
    }
} */

// 조기 종료가 가능한 버전
int RecurMaze(Pos p) {
    // TODO:
    cout << p << " ";

    const char mark = maze[p.row][p.col];

    if (mark == 'G') {
        cout << " Found! " << endl;
        return 1;
    }

    if (mark != 'X' && mark != '1') {
        maze[p.row][p.col] = 'X';

        // 함수 실행 결과, 1을 반환받았으면 재귀호출을 중단하기 위해 반환을 함
        if (RecurMaze({p.row + 1, p.col + 0}))
            return 1;
        if (RecurMaze({p.row - 1, p.col + 0}))
            return 1;
        if (RecurMaze({p.row + 0, p.col + 1}))
            return 1;
        if (RecurMaze({p.row + 0, p.col - 1}))
            return 1;
    }
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
        // cout << endl;

        const char mark = maze[p.row][p.col];

        if (mark == 'G') {
            cout << "Found!" << endl;
            break;
        }

        // REVIEW

        // 방문한 위치임을 표시
        maze[p.row][p.col] = 'X';

        // 모든 방향을 일단 스택에 넣기
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            Pos temp = {p.row, p.col};
            temp.row += dx[i];
            temp.col += dy[i];
            if (temp.row < kNumRows && temp.col < kNumCols && maze[temp.row][temp.col] == '0' ||
                maze[temp.row][temp.col] == 'G') {
                s.Push(temp);
            }
        }
    }
}

int main() {
    PrintMaze();

    RecurMaze({1, 1});

    // StackMaze();

    cout << endl;

    PrintMaze();

    return 0;
}
