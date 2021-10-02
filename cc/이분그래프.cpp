#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

int T;
vector<pair<int, int>> VE;
vector<int> edges[5][20001];
int color[20001];

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
  cin >> T;
  for (int i = 0; i < T; i++) {
    int V, E;
    cin >> V >> E;
    VE.push_back(make_pair(V, E));
    for (int j = 0; j < E; j++) {
      int a, b;
      cin >> a >> b;
      edges[i][a].push_back(b);
      edges[i][b].push_back(a);
    }
  }
}

// color : 0 / -1,1
void solve() {
  for (int t = 0; t < T; t++) {
    int V = VE[t].first;
    int E = VE[t].second;
    for (int i = 1; i <= V; i++) {
      color[i] = 0;
    }
    bool is_yes = true;
    for (int i = 1; i <= V && is_yes; i++) {
      if (color[i] == 0) {
        queue<pair<int, int>> q;
        for (int j = 0; j < edges[t][i].size() && is_yes; j++) {
          q.push(make_pair(i, edges[t][i][j]));
          color[i] = 1;
          while (!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            if (color[b] == 0) {
              color[b] = -color[a];
              for (int k = 0; k < edges[t][b].size(); k++) {
                q.push(make_pair(b, edges[t][b][k]));
              }
            } else if (color[b] == color[a]) {
              is_yes = false;
              break;
            } else {
              continue;
            }
          }
        }
      }
    }
    if (is_yes) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
