#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define endl '\n'

int N, E;
vector<pair<int, int>> edges[801];
bool visited[801];
int A, B;
int cal_dis(int s, int d);

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
  cin >> N >> E;
  for (int i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back(make_pair(c, b));
    edges[b].push_back(make_pair(c, a));
  }
  cin >> A >> B;
}

void solve() {
  if (cal_dis(1, N) == -1) {
    cout << "-1" << endl;
    exit(0);
  }

  int dis_1toA = cal_dis(1, A);
  int dis_AtoB = cal_dis(A, B);
  int dis_BtoN = cal_dis(B, N);
  int AB = dis_1toA + dis_AtoB + dis_BtoN;

  int dis_1toB = cal_dis(1, B);
  int dis_BtoA = cal_dis(B, A);
  int dis_AtoN = cal_dis(A, N);
  int BA = dis_1toB + dis_BtoA + dis_AtoN;
  if (AB > BA) {
    cout << BA << endl;
  } else {
    cout << AB << endl;
  }
}

int cal_dis(int s, int d) {
  memset(visited, false, sizeof(visited));
  priority_queue<pair<int, int>> pq;
  visited[s] = true;
  pq.push(make_pair(0, s));
  int result = -1;
  while (!pq.empty()) {
    int w = -pq.top().first;
    int now = pq.top().second;
    // cout << "w : " << w << endl;
    visited[now] = true;
    if (now == d) {
      result = w;
      break;
    }
    pq.pop();
    for (int i = 0; i < edges[now].size(); i++) {
      int next = edges[now][i].second;
      int weight = edges[now][i].first + w;
      if (!visited[next]) {
        pq.push(make_pair(-weight, next));
      }
    }
  }
  return result;
}
