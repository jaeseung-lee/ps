#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

int n, m;
vector<int> edges[100000];
priority_queue<pair<int, int>> edge_sizes;
int dp[100000];

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
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    edge_sizes.push(make_pair(edges[i].size(), i));
  }
}

void solve() {
  while (!edge_sizes.empty()) {
    int now_vertex = edge_sizes.top().second;
    edge_sizes.pop();
    dp[now_vertex] = 1;
    for (int i = 0; i < edges[now_vertex].size(); i++) {
      int target_vertex = edges[now_vertex][i];
      if (edges[target_vertex].size() > edges[now_vertex].size()) {
        if (dp[now_vertex] < dp[target_vertex] + 1) {
          dp[now_vertex] = dp[target_vertex] + 1;
        }
      }
    }
  }

  int answer = 0;
  for (int i = 0; i < n; i++) {
    if (dp[i] > answer) {
      answer = dp[i];
    }
  }
  cout << answer;
}
