/*
edge가 단방향 edge인지, 쌍방향 edge인지 필히 체크할 것
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

int V, E;
vector<vector<pair<int, int>>> edges;
priority_queue<pair<int, int>> PQ;
bool visited[10000 + 1];

void solve();
void input();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> V >> E;
  for (int i = 0; i <= V; i++) {
    vector<pair<int, int>> temp;
    edges.push_back(temp);
  }
  for (int i = 0; i < E; i++) {
    int weight;
    int first_node;
    int second_node;
    cin >> first_node >> second_node >> weight;
    edges[first_node].push_back(make_pair(-weight, second_node));
    edges[second_node].push_back(make_pair(-weight, first_node));
  }
}

void solve() {
  long long weight_sum = 0;
  for (int i = 1; i <= V; i++) {
    visited[i] = false;
  }
  PQ.push(make_pair(0, 1));
  while (!PQ.empty()) {
    int next_node = PQ.top().second;
    int weight = -PQ.top().first;
    PQ.pop();
    if (!visited[next_node]) {
      visited[next_node] = true;
      weight_sum += weight;
      for (int i = 0; i < edges[next_node].size(); i++) {
        if (!visited[edges[next_node][i].second]) {
          PQ.push(edges[next_node][i]);
        }
      }
    }
  }
  cout << weight_sum << endl;
}
