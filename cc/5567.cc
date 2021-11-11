#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

int n, m;
vector<int> edge[501];
int ans = 0;
queue<pair<int, int>> q;  // index, depth

bool is_invited[501];
void input();
void solve();
void dfs(int index, int depth);

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
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
}

void solve() {
  q.push(make_pair(1, 0));
  is_invited[1] = true;
  while (!q.empty()) {
    int now = q.front().first;
    int depth = q.front().second;
    q.pop();
    if (depth >= 3) {
      continue;
    }
    ans++;
    for (int next : edge[now]) {
      if (!is_invited[next]) {
        q.push(make_pair(next, depth + 1));
        is_invited[next] = true;
      }
    }
  }
  cout << ans - 1 << endl;
}
