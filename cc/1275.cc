#include <iostream>

using namespace std;

#define endl '\n'
#define ll long long

int N, Q;
ll A[100001];
ll Tree[800008];

void input();
void solve();
void fill_tree(int tree_index, int start_index, int end_index);
ll find_target(int tree_index, int start_index, int end_index, int target_start,
               int target_end);
void change_target(int tree_index, int start_index, int end_index,
                   int target_index, int target_value);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  fill_tree(1, 1, N);
}

void solve() {
  for (int i = 0; i < Q; i++) {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    if (x < y)
      cout << find_target(1, 1, N, x, y) << endl;
    else
      cout << find_target(1, 1, N, y, x) << endl;
    A[x] = y;
    change_target(1, 1, N, a, b);
  }
}

void fill_tree(int tree_index, int start_index, int end_index) {
  if (start_index == end_index) {
    Tree[tree_index] = A[start_index];
    return;
  }
  int mid = (start_index + end_index) / 2;
  fill_tree(2 * tree_index, start_index, mid);
  fill_tree(2 * tree_index + 1, mid + 1, end_index);
  Tree[tree_index] = Tree[2 * tree_index] + Tree[tree_index * 2 + 1];
}

ll find_target(int tree_index, int start_index, int end_index, int target_start,
               int target_end) {
  if (start_index == end_index) {
    return Tree[tree_index];
  }
  if (start_index == target_start && end_index == target_end) {
    return Tree[tree_index];
  }
  int mid = (start_index + end_index) / 2;
  if (target_end <= mid) {
    return find_target(2 * tree_index, start_index, mid, target_start,
                       target_end);
  } else if (target_start > mid) {
    return find_target(2 * tree_index + 1, mid + 1, end_index, target_start,
                       target_end);
  } else {
    return find_target(2 * tree_index, start_index, mid, target_start, mid) +
           find_target(2 * tree_index + 1, mid + 1, end_index, mid + 1,
                       target_end);
  }
}
void change_target(int tree_index, int start_index, int end_index,
                   int target_index, int target_value) {
  if (start_index == end_index && start_index == target_index) {
    Tree[tree_index] = target_value;
    return;
  }
  int mid = (start_index + end_index) / 2;
  if (target_index <= mid) {
    change_target(2 * tree_index, start_index, mid, target_index, target_value);
  } else {
    change_target(2 * tree_index + 1, mid + 1, end_index, target_index,
                  target_value);
  }
  Tree[tree_index] = Tree[2 * tree_index] + Tree[2 * tree_index + 1];
}