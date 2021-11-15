#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

int N, M;
char board[50][50];
int ans = 1;

void input();
void solve();
bool isSquare(int y1, int x1, int y2, int x2, int y3, int x3, int y4, int x4) {
  return board[y1][x1] == board[y2][x2] && board[y2][x2] == board[y3][x3] &&
         board[y3][x3] == board[y4][x4];
}

int main() {
  input();
  solve();

  return 0;
}

void input() {
  cin >> N >> M;
  getchar();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      board[i][j] = getchar();
    }
    getchar();
  }
}

void solve() {
  for (int length = 1; length < min(N, M); length++) {
    for (int i = 0; i < N - length; i++) {
      for (int j = 0; j < M - length; j++) {
        if (isSquare(i, j, i + length, j, i, j + length, i + length,
                     j + length)) {
          ans = length + 1;
        }
      }
    }
  }
  cout << ans * ans << endl;
}
