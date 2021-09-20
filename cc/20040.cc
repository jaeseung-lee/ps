#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int n, m;
int parent[500000];
pair<int, int> testcases[1000000];

void solve();

// union-find
int find(int target_index);
void merge(int source_index, int target_index);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    testcases[i] = make_pair(a, b);
  }

  for (int i = 0; i < m; i++) {
    int a = testcases[i].first;
    int b = testcases[i].second;
    int p_a = find(a);
    int p_b = find(b);
    if (p_a == p_b) {
      cout << i + 1 << endl;
      exit(0);
    } else {
      merge(p_a, p_b);
    }
  }
  cout << "0" << endl;
}

int find(int target_index) {
  int parent_index = parent[target_index];
  if (parent_index == target_index) {
    return parent_index;
  } else {
    return parent[target_index] = find(parent_index);
  }
}
void merge(int source_index, int target_index) {
  int p_a = find(source_index);
  int p_b = find(target_index);
  if (p_a == p_b) {
    return;
  } else {
    if (p_a > p_b) {
      parent[p_b] = p_a;
    } else {
      parent[p_a] = p_b;
    }
  }
}
