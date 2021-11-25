#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'

using namespace std;

vector<int> ans;
bool edges[1001][1001];
int N, M;
int deg[1001];
bool isVisited[1001];

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
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int n;
    cin >> n;
    int prev = -1;
    int now = -1;
    for (int j = 0; j < n; j++) {
      cin >> now;
      if (prev != -1 && !edges[prev][now]) {
        edges[prev][now] = true;
        deg[now]++;
      }
      prev = now;
    }
  }
}

void solve() {
  for (int i = 1; i <= N; i++) {
    if (deg[i] == 0 && !isVisited[i]) {
      queue<int> q;
      q.push(i);
      isVisited[i] = true;
      while (!q.empty()) {
        int now = q.front();
        q.pop();
        ans.push_back(now);
        for (int next = 1; next <= N; next++) {
          if (edges[now][next]) {
            deg[next]--;
            if (deg[next] < 0) {
              cout << "0" << endl;
              return;
            } else if (deg[next] == 0) {
              q.push(next);
              isVisited[next] = true;
            }
          }
        }
      }
    }
  }
  if (ans.size() != N) {
    cout << "0" << endl;
    return;
  }
  for (auto element : ans) {
    cout << element << endl;
  }
}
