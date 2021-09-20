#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'

using namespace std;

vector<int> edges[3001];
bool visited[3001];
int N;
bool is_in_cycle[3001];

void input();
void solve();
void dfs(int now_index, int prev_index);
void check(int now_index);

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
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
}

void solve() {
  memset(is_in_cycle, false, sizeof(is_in_cycle));
  for (int i = 1; i <= N; i++) {
    memset(visited, false, sizeof(visited));
    visited[i] = true;
    dfs(i, 0);
  }
  memset(visited, false, sizeof(visited));
  for (int i = 1; i <= N; i++) {
    if (is_in_cycle[i]) {
      cout << "0 ";
    } else {
      check(i);
    }
  }
}

void dfs(int now_index, int prev_index) {
  for (int i = 0; i < edges[now_index].size(); i++) {
    int next = edges[now_index][i];
    // cout << "next : " << next << endl;
    if (!visited[next] && next != prev_index) {
      visited[next] = true;
      dfs(next, now_index);
    } else if (visited[next] && next != prev_index) {
      is_in_cycle[next] = true;
      return;
    }
  }
}

void check(int now_index) {
  memset(visited, false, sizeof(visited));
  queue<pair<int, int>> q;
  q.push(make_pair(now_index, 0));
  visited[now_index] = true;
  // cout << "now : " << now_index << endl;
  while (!q.empty()) {
    int now = q.front().first;
    int value = q.front().second;
    q.pop();
    for (int i = 0; i < edges[now].size(); i++) {
      int next = edges[now][i];
      if (!visited[next] && !is_in_cycle[next]) {
        visited[next] = true;
        q.push(make_pair(next, value + 1));
      } else if (!visited[next] && is_in_cycle[next]) {
        cout << value + 1 << " ";
        return;
      }
    }
  }
}
