#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'
// union-find
int parent[100001];
int find_parent(int target_index) {
  if (parent[target_index] == target_index) {
    return target_index;
  } else {
    return parent[target_index] = find_parent(parent[target_index]);
  }
}

void merge(int left_index, int right_index) {
  int left_parent = find_parent(left_index);
  int right_parent = find_parent(right_index);
  if (left_parent != right_parent) {
    if (left_parent > right_parent) {
      parent[right_parent] = left_parent;
    } else {
      parent[left_parent] = right_parent;
    }
  }
}

int N;
bool is_visited[100001];
int ans = 0;

struct position {
  int x, y, z;
};

position makePosition(int x, int y, int z) {
  position result;
  result.x = x;
  result.y = y;
  result.z = z;
  return result;
}

vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;

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
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    X.push_back(make_pair(a, i));
    Y.push_back(make_pair(b, i));
    Z.push_back(make_pair(c, i));
    parent[i] = i;
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  sort(Z.begin(), Z.end());
}

void solve() {
  priority_queue<pair<int, pair<int, int>>> pq;
  // fill pq
  for (int i = 0; i < N - 1; i++) {
    pq.push(make_pair(-abs(X[i].first - X[i + 1].first),
                      make_pair(X[i].second, X[i + 1].second)));
  }
  for (int i = 0; i < N - 1; i++) {
    pq.push(make_pair(-abs(Y[i].first - Y[i + 1].first),
                      make_pair(Y[i].second, Y[i + 1].second)));
  }
  for (int i = 0; i < N - 1; i++) {
    pq.push(make_pair(-abs(Z[i].first - Z[i + 1].first),
                      make_pair(Z[i].second, Z[i + 1].second)));
  }

  while (!pq.empty()) {
    int weight = -pq.top().first;
    int from = pq.top().second.first;
    int to = pq.top().second.second;
    pq.pop();
    if (find_parent(from) == find_parent(to)) {
      continue;
    } else {
      merge(from, to);
      ans += weight;
    }
  }
  cout << ans << endl;
}
