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
      }
      for (int j = 0; j < edges[i].size(); j++) {
        degree[edges[i][j]]--;
        if (degree[edges[i][j]] == 0) {
          cout << edges[i][j] << " ";
          visited[edges[i][j]] = true;
        }
      }
    }
  }
}
