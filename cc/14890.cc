#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

#define endl '\n'

int N, L;
int Board[100][100];
int ans = 0;
bool is_slide[100][100];

void input();
void solve();
bool is_valid_index(int y, int x) { return y < N && y >= 0 && x < N && x >= 0; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N >> L;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> Board[i][j];
    }
  }
}

void solve() {
  memset(is_slide, false, sizeof(is_slide));
  for (int i = 0; i < N; i++) {
    bool is_route = true;
    // 위-아래
    for (int j = 0; j < N - 1 && is_route; j++) {
      // 경사로 높이가 같을 경우
      if (Board[i][j] == Board[i][j + 1]) {
        continue;
      }
      //경사로가 차이가 1이 아닐 경우
      if (abs(Board[i][j] - Board[i][j + 1]) != 1) {
        is_route = false;
        continue;
      }
      // 2
      // 2 1 1
      else if (Board[i][j] - Board[i][j + 1] == 1) {
        for (int k = 1; k <= L; k++) {
          if (is_valid_index(i, j + k) &&
              (Board[i][j] - Board[i][j + k] == 1) && !is_slide[i][j + k]) {
            continue;
          } else {
            is_route = false;
            break;
          }
        }
        if (is_route) {
          for (int k = 1; k <= L; k++) {
            is_slide[i][j + k] = true;
          }
        }
      }

      //     2
      // 1 1 2
      else {
        for (int k = 1; k <= L; k++) {
          if (is_valid_index(i, j + 1 - k) &&
              Board[i][j + 1] - Board[i][j + 1 - k] == 1 &&
              !is_slide[i][j + 1 - k]) {
            continue;
          } else {
            is_route = false;
            break;
          }
        }
        if (is_route) {
          for (int k = 1; k <= L; k++) {
            is_slide[i][j + 1 - k] = true;
          }
        }
      }
    }

    if (is_route) {
      ans++;
    }
  }

  memset(is_slide, false, sizeof(is_slide));
  for (int j = 0; j < N; j++) {
    // 위 -> 아래
    bool is_route = true;
    for (int i = 0; i < N - 1 && is_route; i++) {
      // 경사로 높이가 같을 경우
      if (Board[i][j] == Board[i + 1][j]) {
        continue;
      }
      //경사로가 차이가 1이 아닐 경우
      if (abs(Board[i][j] - Board[i + 1][j]) != 1) {
        is_route = false;
        continue;
      }
      // 2 2
      // 1
      // 1
      else if (Board[i][j] - Board[i + 1][j] == 1) {
        for (int k = 1; k <= L; k++) {
          if (is_valid_index(i + k, j) &&
              (Board[i][j] - Board[i + k][j] == 1) && !is_slide[i + k][j]) {
            continue;
          } else {
            is_route = false;
            break;
          }
        }

        if (is_route) {
          for (int k = 1; k <= L; k++) {
            is_slide[i + k][j] = true;
          }
        }
      }

      // 1
      // 1
      // 2 2
      else {
        for (int k = 1; k <= L; k++) {
          if (is_valid_index(i + 1 - k, j) &&
              Board[i + 1][j] - Board[i + 1 - k][j] == 1 &&
              !is_slide[i + 1 - k][j]) {
            continue;
          } else {
            is_route = false;
            break;
          }
        }
        if (is_route) {
          for (int k = 1; k <= L; k++) {
            is_slide[i + 1 - k][j] = true;
          }
        }
      }
    }

    if (is_route) {
      ans++;
    }
  }

  cout << ans << endl;
}
