#include <iostream>

#define endl '\n'

using namespace std;

int N, M, ans;
char board[51][51];
char target[51][51];
void input();
void solve();

void flip(int y, int x) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[y + i][x + j] == '0') {
        board[y + i][x + j] = '1';
      } else {
        board[y + i][x + j] = '0';
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);

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

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      target[i][j] = getchar();
    }
    getchar();
  }
}

void solve() {
  for (int i = 0; i < N - 2; i++) {
    for (int j = 0; j < M - 2; j++) {
      if (board[i][j] != target[i][j]) {
        flip(i, j);
        ans++;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] != target[i][j]) {
        cout << "-1" << endl;
        exit(0);
      }
    }
  }
  cout << ans << endl;
}
