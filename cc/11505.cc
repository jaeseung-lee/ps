#include <iostream>

using namespace std;

#define endl '\n'
#define mod 1000000007
#define ll long long

int N, M, K;
ll A[1000001];
ll Tree[8000001];

void input();
void solve();
void fill_tree(int tree_index, int start_index, int end_index);
ll find_target(int tree_index, int start_index, int end_index, int target_start,
               int target_end);
void change_target(int tree_index, int start_index, int end_index,
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
  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  fill_tree(1, 1, N);
}

void solve() {
  for (int i = 0; i < M + K; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      A[b] = c;
      change_target(1, 1, N, b);
    } else {
      cout << find_target(1, 1, N, b, c) << endl;
    }
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
  Tree[tree_index] = Tree[2 * tree_index] * Tree[tree_index * 2 + 1] % mod;
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
  if (mid >= target_end) {
    return find_target(2 * tree_index, start_index, mid, target_start,
                       target_end);
  } else if (mid < target_start) {
    return find_target(2 * tree_index + 1, mid + 1, end_index, target_start,
                       target_end);
  } else {
    return find_target(2 * tree_index, start_index, mid, target_start, mid) *
           find_target(2 * tree_index + 1, mid + 1, end_index, mid + 1,
                       target_end) %
           mod;
  }
}
void change_target(int tree_index, int start_index, int end_index,
                   int target_index) {
  if (start_index == end_index && start_index == target_index) {
    Tree[tree_index] = A[start_index];
    return;
  }
  int mid = (start_index + end_index) / 2;
  if (mid >= target_index) {
    change_target(2 * tree_index, start_index, mid, target_index);
  } else {
    change_target(2 * tree_index + 1, mid + 1, end_index, target_index);
  }
  Tree[tree_index] = Tree[2 * tree_index] * Tree[2 * tree_index + 1] % mod;
}