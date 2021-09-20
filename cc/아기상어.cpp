#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'
#define INF 1000000

int N;

int shark_y;
int shark_x;
int answer = 0;
int shark_size = 2;
int Exp = 0;
int fish_status[20][20];
bool visited[20][20];
int fish_dist[20][20];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void input();
void solve();
void fill_dist();
bool is_valid_index(int y, int x);

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
      int temp;
      cin >> temp;
      if (temp == 9) {
        shark_y = i;
        shark_x = j;
        fish_status[i][j] = temp;
      } else {
        fish_status[i][j] = temp;
      }
    }
  }
}

void solve() {
  while (true) {
    int target_fish_index = -1;
    int dist = INF;
    fill_dist();
    int target_y = -1;
    int target_x = -1;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (fish_status[i][j] != 0 && dist > fish_dist[i][j]) {
          dist = fish_dist[i][j];
          target_y = i;
          target_x = j;
        }
      }
    }
    if (target_y == -1) {
      cout << answer << endl;
      break;
    }
    answer += dist;
    fish_status[shark_y][shark_x] = 0;
    shark_y = target_y;
    shark_x = target_x;
    fish_status[target_y][target_x] = 9;
    Exp++;
    if (Exp == shark_size) {
      shark_size++;
      Exp = 0;
      // cout << "now size : " << shark_size << endl;
    }
  }
}

void fill_dist() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      fish_dist[i][j] = INF;
      visited[i][j] = false;
    }
  }
  queue<pair<int, int>> q;
  q.push(make_pair(shark_y, shark_x));
  fish_dist[shark_y][shark_x] = 0;
  visited[shark_y][shark_x] = true;
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    int value = fish_dist[y][x];
    q.pop();
    cout << "now y, x : " << y << " " << x << endl;
    for (int d = 0; d < 4; d++) {
      // cout << "y+dy[d], x+dx[d] : " <<y+dy[d]<< "," << x+dx[d] << endl;
      if (is_valid_index(y + dy[d], x + dx[d]) &&
          !visited[y + dy[d]][x + dx[d]]) {
        visited[y + dy[d]][x + dx[d]] = true;
        if (fish_status[y + dy[d]][x + dx[d]] == 0) {
          q.push(make_pair(y + dy[d], x + dx[d]));
          fish_dist[y + dy[d]][x + dx[d]] = value + 1;
        } else if (fish_status[y + dy[d]][x + dx[d]] == shark_size) {
          q.push(make_pair(y + dy[d], x + dx[d]));
          fish_dist[y + dy[d]][x + dx[d]] = INF;
        } else if (fish_status[y + dy[d]][x + dx[d]] < shark_size) {
          fish_dist[y + dy[d]][x + dx[d]] = value + 1;
        } else {
          fish_dist[y + dy[d]][x + dx[d]] = INF;
        }
      }
    }
  }
}
bool is_valid_index(int y, int x) { return y < N && y >= 0 && x < N && x >= 0; }
