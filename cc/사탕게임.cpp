#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int N;
char board[50][50];
int answer;

void input();
void solve();
void find_longest();

int main() {
  // ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N;
  getchar();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board[i][j] = getchar();
    }
    getchar();
  }
}

void solve() {
  answer = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - 1; j++) {
      if (board[i][j] != board[i][j + 1]) {
        // swap하고
        char temp = board[i][j];
        board[i][j] = board[i][j + 1];
        board[i][j + 1] = temp;
        //최대길이를 구해보고
        find_longest();
        //다시 원래대로 돌려놓음
        temp = board[i][j];
        board[i][j] = board[i][j + 1];
        board[i][j + 1] = temp;
      }
    }
  }

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N - 1; i++) {
      if (board[i + 1][j] != board[i][j]) {
        // cout << "i : " << i << " j : " << j << endl;
        // swap하고
        char temp = board[i][j];
        board[i][j] = board[i + 1][j];
        board[i + 1][j] = temp;
        //최대길이를 구해보고
        find_longest();
        //다시 원래대로 돌려놓음
        temp = board[i][j];
        board[i][j] = board[i + 1][j];
        board[i + 1][j] = temp;
      }
    }
  }

  cout << answer;
}

void find_longest() {
  int best = 1;
  // 진짜 찾는 부분
  char now_color;
  int temp_long = 0;
  //가로
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j == 0) {
        now_color = board[i][j];
        if (temp_long > best) {
          best = temp_long;
        }
        temp_long = 1;
      } else {
        if (now_color != board[i][j]) {
          if (best < temp_long) {
            best = temp_long;
          }
          temp_long = 1;
          now_color = board[i][j];
        } else {
          temp_long++;
        }
      }
      // cout << "temp_long : " << temp_long << endl;
    }
  }

  //세로
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) {
      if (i == 0) {
        now_color = board[i][j];
        if (temp_long > best) {
          best = temp_long;
        }
        temp_long = 1;
      } else {
        if (now_color != board[i][j]) {
          if (best < temp_long) {
            best = temp_long;
          }
          temp_long = 1;
          now_color = board[i][j];
        } else {
          temp_long++;
        }
      }
    }
  }

  if (best > answer) {
    answer = best;
  }
}
