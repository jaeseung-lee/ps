#include <iostream>

using namespace std;

#define endl '\n'
int board[500][500];
int N;

void input();
void solve();
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool isValidIndex(int y, int x) { return y >= 0 && y < N && x >= 0 && x < N; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
}

void solve() {}