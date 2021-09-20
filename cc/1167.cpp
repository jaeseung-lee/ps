#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int V;
vector<pair<int, int>> edges[100000 + 1];
vector<int> degree;
int answer = 0;

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
  cin >> V;
  for (int i = 0; i <= V; i++) {
    degree.push_back(0);
  }
  for (int i = 1; i <= V; i++) {
    int target_v;
    int cnt = 0;
    cin >> target_v;
    while (true) {
      int v, d;
      cin >> v;
      if (v == -1) {
        break;
      } else {
        cin >> d;
      }
      edges[target_v].push_back(make_pair(v, d));
      cnt++;
    }
    degree[target_v] = cnt;
  }
}

void solve() { sort(degree.begin(), degree.end()); }
