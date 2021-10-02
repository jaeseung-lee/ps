#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n';

int N;
double e;
double w;
double s;
double n;
bool visited[29][29];
double answer = 0;
int num_e = 0;
int num_w = 0;
int num_s = 0;
int num_n = 0;

void input();
void solve();
void dfs(int now_index, int y, int x);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  int east, west, south, north;
  cin >> N >> east >> west >> south >> north;
  e = (double)east / (double)100;
  w = (double)west / (double)100;
  s = (double)south / (double)100;
  n = (double)north / (double)100;
}

void solve() {
  for (int i = 0; i < 29; i++) {
    for (int j = 0; j < 29; j++) {
      visited[i][j] = false;
    }
  }
  visited[14][14] = true;
  dfs(0, 14, 14);
  cout.precision(15);
  cout << answer << endl;
}

void dfs(int now_index, int y, int x) {
  if (now_index == N) {
    double value = 1.0;
    for (int i = 0; i < num_e; i++) {
      value *= e;
    }
    for (int i = 0; i < num_s; i++) {
      value *= s;
    }
    for (int i = 0; i < num_w; i++) {
      value *= w;
    }
    for (int i = 0; i < num_n; i++) {
      value *= n;
    }

    answer += value;
    return;
  }

  if (!visited[y + 1][x]) {
    num_s++;
    visited[y + 1][x] = true;
    dfs(now_index + 1, y + 1, x);
    num_s--;
    visited[y + 1][x] = false;
  }

  if (!visited[y][x + 1]) {
    num_e++;
    visited[y][x + 1] = true;
    dfs(now_index + 1, y, x + 1);
    num_e--;
    visited[y][x + 1] = false;
  }

  if (!visited[y - 1][x]) {
    num_n++;
    visited[y - 1][x] = true;
    dfs(now_index + 1, y - 1, x);
    num_n--;
    visited[y - 1][x] = false;
  }

  if (!visited[y][x - 1]) {
    num_w++;
    visited[y][x - 1] = true;
    dfs(now_index + 1, y, x - 1);
    num_w--;
    visited[y][x - 1] = false;
  }
}
