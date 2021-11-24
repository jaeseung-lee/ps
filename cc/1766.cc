#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

int N, M;
vector<int> edges[32001];
int deg[32001];
bool is_visited[32001];
priority_queue<int, vector<int>, greater<int>> pq;

void input();
void solve();
void dfs(int now);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N >> M;
  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    edges[a].push_back(b);
    deg[b]++;
  }
  for (int i = 1; i <= N; i++) {
    sort(edges[i].begin(), edges[i].end());
  }
}

void solve() {
  for (int now = 1; now <= N; now++) {
    if (!is_visited[now] && deg[now] == 0) {
      pq.push(now);
      is_visited[now] = true;
    }
    while (!pq.empty()) {
      int next = pq.top();
      cout << next << " ";
      pq.pop();
      for (int i = 0; i < edges[next].size(); i++) {
        if (!is_visited[edges[next][i]] && --deg[edges[next][i]] == 0) {
          is_visited[edges[next][i]] = true;
          pq.push(edges[next][i]);
        }
      }
    }
  }
}
