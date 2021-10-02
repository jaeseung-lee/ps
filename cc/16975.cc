#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

#define endl '\n'
#define ll long long

int N, M;
ll A[100001];
ll Tree[800008];
ll ans;

void input();
void solve();
void fill_tree(int tree_index, int start_index, int end_index);
void insert_tree(int tree_index, int start_index, int end_index,
                 int target_start, int target_end, ll target_value);
void find_target(int tree_index, int start_index, int end_index,
                 int target_index);

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
    cin >> A[i];
  }
  cin >> M;
}

void solve() {
  for (int i = 0; i < M; i++) {
    ll a, b, c, d;
    cin >> a >> b;
    if (a == 1) {
      cin >> c >> d;
      insert_tree(1, 1, N, b, c, d);
    } else {
      ans = A[b];
      find_target(1, 1, N, b);
      cout << ans << endl;
    }
  }
}

void fill_tree(int tree_index, int start_index, int end_index) {
  Tree[tree_index] = 0;
  if (start_index == end_index) {
    return;
  }
  int mid = (start_index + end_index) / 2;
  fill_tree(2 * tree_index, start_index, mid);
  fill_tree(2 * tree_index + 1, mid + 1, end_index);
}

void insert_tree(int tree_index, int start_index, int end_index,
                 int target_start, int target_end, ll target_value) {
  if (start_index == end_index) {
    Tree[tree_index] += target_value;
    return;
  }
  if (start_index == target_start && end_index == target_end) {
    Tree[tree_index] += target_value;
    return;
  }

  int mid = (start_index + end_index) / 2;
  if (target_end <= mid) {
    insert_tree(2 * tree_index, start_index, mid, target_start, target_end,
                target_value);
  } else if (target_start > mid) {
    insert_tree(2 * tree_index + 1, mid + 1, end_index, target_start,
                target_end, target_value);
  } else {
    insert_tree(2 * tree_index, start_index, mid, target_start, mid,
                target_value);
    insert_tree(2 * tree_index + 1, mid + 1, end_index, mid + 1, target_end,
                target_value);
  }
}
void find_target(int tree_index, int start_index, int end_index,
                 int target_index) {
  ans += Tree[tree_index];
  if (start_index == end_index) {
    return;
  }
  int mid = (start_index + end_index) / 2;
  // ans += accumulate(Tree[tree_index].begin(), Tree[tree_index].end(), 0);
  if (target_index <= mid) {
    find_target(2 * tree_index, start_index, mid, target_index);
  } else {
    find_target(2 * tree_index + 1, mid + 1, end_index, target_index);
  }
}
