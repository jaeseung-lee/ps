#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define endl '\n'

int N, M, X;
vector<pair<int, int>> edges[1000 + 1];
vector<pair<int, int>> rev_edges[1000 + 1];
int dis[1001];
int ret[1001];
bool visited[1001];

void input();
void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N >> M >> X;
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back(make_pair(b, c));
    rev_edges[b].push_back(make_pair(a, c));
  }
}

void solve() {
  memset(dis, -1, sizeof(dis));
  memset(visited, false, sizeof(visited));
  priority_queue<pair<int, int>> pq;
  pq.push(make_pair(0, X));
  // visited[X] = true;
  while (!pq.empty()) {
    int now = pq.top().second;
    int w = pq.top().first;
    visited[now] = true;
    if (dis[now] == -1 || dis[now] > -w) {
      dis[now] = -w;
    }
    pq.pop();
    for (int i = 0; i < edges[now].size(); i++) {
      int next = edges[now][i].first;
      int next_w = edges[now][i].second - w;
      if (!visited[next]) {
        pq.push(make_pair(-next_w, next));
      }
    }
  }
  memset(ret, -1, sizeof(ret));
  memset(visited, false, sizeof(visited));
  pq.push(make_pair(0, X));
  while (!pq.empty()) {
    int now = pq.top().second;
    int w = pq.top().first;
    visited[now] = true;
    if (ret[now] == -1 || ret[now] > -w) {
      ret[now] = -w;
    }
    pq.pop();
    for (int i = 0; i < rev_edges[now].size(); i++) {
      int next = rev_edges[now][i].first;
      int next_w = rev_edges[now][i].second - w;
      if (!visited[next]) {
        pq.push(make_pair(-next_w, next));
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (ans < ret[i] + dis[i]) {
      ans = ret[i] + dis[i];
    }
  }
  cout << ans;
}