#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

int N, K, Target;
int D[100000 + 1];
vector<int> path[100000 + 1];
int degree[100000 + 1];
bool visited[100000 + 1];
int dis[100000 + 1];

void input();
void solve();

int main() {
  ios::sync_with_stdio(false);

  solve();

  return 0;
}

void input() {
  memset(D, 0, sizeof(D));
  memset(degree, 0, sizeof(degree));
  memset(visited, false, sizeof(visited));
  memset(dis, 0, sizeof(dis));

  for (int i = 1; i <= N; i++) {
    path[i].clear();
  }

  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    cin >> D[i];
  }
  for (int i = 0; i < K; i++) {
    int x, y;
    cin >> x >> y;
    path[x].push_back(y);
    degree[y]++;
  }
  cin >> Target;
}

void solve() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    input();
    queue<int> q;
    for (int i = 1; i <= N; i++) {
      if (degree[i] == 0) {
        q.push(i);
        visited[i] = true;
        dis[i] = D[i];
      }
    }
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      if (now == Target) {
        cout << dis[Target] << endl;
        break;
      }
      for (int i = 0; i < path[now].size(); i++) {
        int next = path[now][i];
        if (!visited[next]) {
          if (degree[next] > 1) {
            degree[next]--;
            if (dis[next] < dis[now] + D[next]) {
              dis[next] = dis[now] + D[next];
            }
          } else {
            if (dis[next] < dis[now] + D[next]) {
              dis[next] = dis[now] + D[next];
            }
            q.push(next);
            visited[next] = true;
          }
        }
      }
    }
  }
  /*
  for (int i = 1; i <= N; i++) {
    cout << dis[i] << " ";
  }
  cout << endl;
  cout << N << " " << K << " " << Target << endl;
  */
}
