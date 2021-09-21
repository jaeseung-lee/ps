#include <iostream>

using namespace std;

#define endl '\n'

int N;
char op[10][10];
int ans[10];
int sum[10][10];
void input();
void solve();
void dfs(int now_index);
void check();
bool fill_sum(int now_index);
bool check_valid(int i, int j, int value);

int main() {
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
    for (int j = i; j < N; j++) {
      op[i][j] = getchar();
    }
  }
}

void solve() {
  if (op[0][0] == '+') {
    for (int i = 1; i <= 10; i++) {
      ans[0] = i;
      sum[0][0] = i;
      dfs(1);
    }
  } else if (op[0][0] == '0') {
    ans[0] = 0;
    sum[0][0] = 0;
    dfs(1);
  } else {
    for (int i = -10; i <= -1; i++) {
      ans[0] = i;
      sum[0][0] = i;
      dfs(1);
    }
  }
}

void dfs(int now_index) {
  // cout << "now_index : " << now_index << endl;
  if (now_index == N) {
    check();
    return;
  }
  int min, max;
  if (op[now_index][now_index] == '0') {
    ans[now_index] = 0;
    if (fill_sum(now_index)) {
      dfs(now_index + 1);
    }
    return;
  }
  if (op[now_index - 1][now_index - 1] == '0') {
    if (op[now_index][now_index] == '+') {
      min = 1, max = 10;
      for (int i = min; i <= max; i++) {
        ans[now_index] = i;
        if (fill_sum(now_index)) {
          dfs(now_index + 1);
        }
      }
      return;
    } else {
      min = -10, max = -1;
      for (int i = min; i <= max; i++) {
        ans[now_index] = i;
        if (fill_sum(now_index)) {
          dfs(now_index + 1);
        }
      }
      return;
    }
  }
  if (op[now_index - 1][now_index] == '0') {
    ans[now_index] = -ans[now_index - 1];
    if (fill_sum(now_index)) {
      dfs(now_index + 1);
    }
    return;
  }
  if (op[now_index][now_index] == op[now_index - 1][now_index - 1]) {
    if (op[now_index][now_index] == '+') {
      min = 1, max = 10;
      for (int i = min; i <= max; i++) {
        ans[now_index] = i;
        if (fill_sum(now_index)) {
          dfs(now_index + 1);
        }
      }
      return;
    } else {
      min = -10, max = -1;
      for (int i = min; i <= max; i++) {
        ans[now_index] = i;
        if (fill_sum(now_index)) {
          dfs(now_index + 1);
        }
      }
      return;
    }
  }
  if (op[now_index - 1][now_index - 1] == '-') {
    if (op[now_index - 1][now_index] == '+') {
      min = -ans[now_index - 1] + 1, max = 10;
    } else {
      min = 1, max = -ans[now_index - 1] - 1;
    }
  } else {
    if (op[now_index - 1][now_index] == '+') {
      min = -ans[now_index - 1] + 1, max = -1;
    } else {
      min = -10, max = -ans[now_index - 1] - 1;
    }
  }
  for (int i = min; i <= max; i++) {
    ans[now_index] = i;
    if (fill_sum(now_index)) {
      dfs(now_index + 1);
    }
  }
  return;
}

void check() {
  /*
  cout << "ans : " << endl;
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  cout << endl << endl;
  for (int i = 0; i < N; i++) {
    for (int j = i + 2; j < N; j++) {
      int value = 0;
      for (int k = i; k <= j; k++) {
        value += ans[k];
      }
      if (op[i][j] == '+' && value > 0) {
        continue;
      } else if (op[i][j] == '0' && value == 0) {
        continue;
      } else if (op[i][j] == '-' && value < 0) {
        continue;
      } else {
        return;
      }
    }
  }
  */
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  exit(0);
}

bool fill_sum(int now_index) {
  int temp = 0;
  for (int i = 0; i <= now_index; i++) {
    temp += ans[i];
  }
  if (!check_valid(0, now_index, temp)) {
    return false;
  }
  for (int i = 0; i < now_index - 2; i++) {
    temp -= ans[i];
    if (!check_valid(i + 1, now_index, temp)) {
      return false;
    }
  }
  return true;
}

bool check_valid(int i, int j, int value) {
  if (op[i][j] == '0') {
    return value == 0;
  } else if (op[i][j] == '+') {
    return value > 0;
  } else {
    return value < 0;
  }
}
