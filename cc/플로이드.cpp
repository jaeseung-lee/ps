#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define INF 987654321

int n, m;
int adj[101][101];

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
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        adj[i][j] = 0;
      } else {
        adj[i][j] = INF;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    if (weight < adj[from][to]) {
      adj[from][to] = weight;
    }
  }
}

void solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (adj[j][k] > adj[j][i] + adj[i][k]) {
          adj[j][k] = adj[j][i] + adj[i][k];
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (adj[i][j] == INF) {
        cout << "0 ";
      } else {
        cout << adj[i][j] << " ";
      }
    }
    cout << endl;
  }
}
