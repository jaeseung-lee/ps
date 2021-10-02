#include <iostream>

using namespace std;

#define endl '\n'
#define ll long long

ll Tree[8000000 + 1];
ll A[1000000 + 1];
int N, K, M;
ll ans = 0;

void input();
void solve();
void fill_tree(int tree_index, int start_index, int end_index);
void insert_target(int tree_index, int start_index, int end_index,
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
  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  fill_tree(1, 1, N);
}

void solve() {
  for (int i = 0; i < M + K; i++) {
    ll a, b, c, d;
    cin >> a;
    if (a == 1) {
      cin >> b >> c >> d;
      insert_target(1, 1, N, b, c, d);
      for (int i = 1; i <= 2 * N; i++) {
        cout << Tree[i] << " ";
      }
      cout << endl;
    } else {
      cin >> b;
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
void insert_target(int tree_index, int start_index, int end_index,
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
    insert_target(2 * tree_index, start_index, mid, target_start, target_end,
                  target_value);
  } else if (target_start > mid) {
    insert_target(2 * tree_index + 1, mid + 1, end_index, target_start,
                  target_end, target_value);
  } else {
    insert_target(2 * tree_index, start_index, mid, target_start, mid,
                  target_value);
    insert_target(2 * tree_index + 1, mid + 1, end_index, mid + 1, target_end,
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
  if (target_index <= mid) {
    find_target(2 * tree_index, start_index, mid, target_index);
  } else {
    find_target(2 * tree_index + 1, mid + 1, end_index, target_index);
  }
}
