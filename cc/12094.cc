#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'

using namespace std;

struct state {
  vector<vector<int>> game;  // 현재 게임판의 상태
  int max;  // 현재 게임판에서 만들어진 숫자들 중 가장 큰 수
  int moved;  // 움직인 횟수
};

int N;
queue<state> q;
int answer = 0;
bool is_valid_index(int y, int x) { return y < N && y >= 0 && x < N && x >= 0; }

void input();
void solve();
state make_state(vector<vector<int>> new_game, int new_max, int new_moved) {
  state new_state;
  new_state.game = new_game;
  new_state.max = new_max;
  new_state.moved = new_moved;
  return new_state;
}

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
  int Max = 0;

  vector<vector<int>> init_game;
  for (int i = 0; i < N; i++) {
    vector<int> temp;
    for (int j = 0; j < N; j++) {
      int t;
      cin >> t;
      temp.push_back(t);
      if (Max < t) {
        Max = t;
      }
    }
    init_game.push_back(temp);
  }
  q.push(make_state(init_game, Max, 0));
  answer = Max;
  // cout << "answer : " << answer << endl;
}

void solve() {
  while (!q.empty()) {
    if (q.front().max > answer) {
      // cout << "now max : " << q.front().max << endl;
      answer = q.front().max;
    }

    if (q.front().moved == 5) {
      q.pop();
      continue;
    }
    state now_U = q.front();
    state now_D = q.front();
    state now_R = q.front();
    state now_L = q.front();
    q.pop();

    if (now_U.max > answer) {
      answer = now_U.max;
    }
    if (now_U.moved == 5) {
      continue;
    }
    bool is_sum[20] = {
        false,
    };

    // UP
    for (int j = 0; j < N; j++) {
      memset(is_sum, false, sizeof(is_sum));
      for (int r_i = 0; r_i < N; r_i++) {
        int i = r_i;
        if (now_U.game[i][j] == 0) {
          continue;
        }
        while (is_valid_index(i - 1, j)) {
          if (now_U.game[i - 1][j] == now_U.game[i][j]) {
            if (is_sum[i - 1]) {
              break;
            }
            is_sum[i - 1] = true;
            now_U.game[i][j] = 0;
            now_U.game[i - 1][j] *= 2;
            if (now_U.max < now_U.game[i - 1][j]) {
              now_U.max = now_U.game[i - 1][j];
            }
            break;
          } else if (now_U.game[i - 1][j] != 0) {
            break;
          } else {
            now_U.game[i - 1][j] = now_U.game[i][j];
            now_U.game[i][j] = 0;
            i--;
          }
        }
      }
    }
    now_U.moved++;
    q.push(now_U);

    // DOWN
    for (int j = 0; j < N; j++) {
      memset(is_sum, false, sizeof(is_sum));
      for (int r_i = N - 1; r_i >= 0; r_i--) {
        int i = r_i;
        if (now_D.game[i][j] == 0) {
          continue;
        }

        while (is_valid_index(i + 1, j)) {
          if (now_D.game[i + 1][j] == now_D.game[i][j]) {
            if (is_sum[i + 1]) {
              break;
            }
            is_sum[i + 1] = true;
            now_D.game[i][j] = 0;
            now_D.game[i + 1][j] *= 2;
            if (now_D.max < now_D.game[i + 1][j]) {
              now_D.max = now_D.game[i + 1][j];
            }
            break;
          } else if (now_D.game[i + 1][j] != 0) {
            break;
          } else {
            now_D.game[i + 1][j] = now_D.game[i][j];
            now_D.game[i][j] = 0;
            i++;
          }
        }
      }
    }

    now_D.moved++;
    q.push(now_D);

    // LEFT
    for (int i = 0; i < N; i++) {
      memset(is_sum, false, sizeof(is_sum));
      for (int r_j = 0; r_j < N; r_j++) {
        int j = r_j;
        if (now_L.game[i][j] == 0) {
          continue;
        }
        while (is_valid_index(i, j - 1)) {
          if (now_L.game[i][j - 1] == now_L.game[i][j]) {
            if (is_sum[j - 1]) {
              break;
            }
            is_sum[j - 1] = true;
            now_L.game[i][j] = 0;
            now_L.game[i][j - 1] *= 2;
            if (now_L.max < now_L.game[i][j - 1]) {
              now_L.max = now_L.game[i][j - 1];
            }
            break;
          } else if (now_L.game[i][j - 1] != 0) {
            break;
          } else {
            now_L.game[i][j - 1] = now_L.game[i][j];
            now_L.game[i][j] = 0;
            j--;
          }
        }
      }
    }
    now_L.moved++;
    q.push(now_L);

    // RIGHT
    for (int i = 0; i < N; i++) {
      memset(is_sum, false, sizeof(is_sum));
      for (int r_j = N - 1; r_j >= 0; r_j--) {
        int j = r_j;
        if (now_R.game[i][j] == 0) {
          continue;
        }

        while (is_valid_index(i, j + 1)) {
          if (now_R.game[i][j + 1] == now_R.game[i][j]) {
            if (is_sum[j + 1]) {
              break;
            }
            is_sum[j + 1] = true;
            now_R.game[i][j] = 0;
            now_R.game[i][j + 1] *= 2;
            if (now_R.max < now_R.game[i][j + 1]) {
              now_R.max = now_R.game[i][j + 1];
            }
            break;
          } else if (now_R.game[i][j + 1] != 0) {
            break;
          } else {
            now_R.game[i][j + 1] = now_R.game[i][j];
            now_R.game[i][j] = 0;
            j++;
          }
        }
      }
    }
    now_R.moved++;
    q.push(now_R);
  }
  cout << answer << endl;
}
