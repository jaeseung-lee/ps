#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int N, M;
vector<int> edges[32001];
void input();
void solve();

int degree[32001];
bool visited[32001];
void dfs(int now_index);

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
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    degree[b]++;
  }
}

void solve() {
  for (int i = 1; i <= N; i++) {
    if (degree[i] == 0) {
      if (!visited[i]) {
        cout << i << " ";
        visited[i] = true;
        for (int j = 0; j < edges[i].size(); j++) {
          int next = edges[i][j];
          degree[next]--;
          if (degree[next] == 0 && !visited[next]) {
            visited[next] = true;
            dfs(next);
          }
        }
      }
    }
  }
}
void dfs(int now_index) {
  cout << now_index << " ";
  for (int j = 0; j < edges[now_index].size(); j++) {
    int next = edges[now_index][j];
    degree[next]--;
    if (degree[next] == 0 && !visited[next]) {
      visited[next] = true;
      dfs(next);
    }
  }
}
