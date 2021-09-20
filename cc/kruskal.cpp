#include <iostream>
#include <queue>
#include <tuple>

#define endl '\n'

using namespace std;

// union-find
int parent[10001];
int find(int target_index);
void merge(int first_index, int second_index);
priority_queue<tuple<int, int, int>> PQ;

int V, E;

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

int find(int target_index) {
  int parent_index = parent[target_index];
  if (parent_index == target_index) {
    return parent_index;
  } else {
    return parent[target_index] = find(parent_index);
  }
}
void merge(int first_index, int second_index) {
  int first_root = find(first_index);
  int second_root = find(second_index);
  if (first_root != second_root) {
    if (first_root > second_root) {
      parent[first_root] = second_root;
    } else {
      parent[second_root] = first_root;
    }
  }
}

void input() {
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    int weight, first_index, second_index;
    cin >> first_index >> second_index >> weight;
    PQ.push(make_tuple(-weight, first_index, second_index));
  }
}

void solve() {
  long long weight_sum = 0;
  for (int i = 1; i <= V; i++) {
    parent[i] = i;
  }
  while (!PQ.empty()) {
    int weight = -get<0>(PQ.top());
    int first_index = get<1>(PQ.top());
    int second_index = get<2>(PQ.top());
    int first_index_root = find(first_index);
    int second_index_root = find(second_index);
    if (first_index_root == second_index_root) {
      PQ.pop();
      continue;
    }
    merge(first_index, second_index);
    weight_sum += weight;
  }
  cout << weight_sum;
}
