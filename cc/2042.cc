#include <iostream>

using namespace std;

#define endl '\n'
#define ll long long

int N, M, K;
ll A[1000001];
ll TreeSum[8000001];
void fill_tree(int tree_index, int start_index, int end_index);
void change_target(int tree_index, int target_index, ll target_num,
                   int start_index, int end_index);
ll partial_sum(int tree_index, int start_index, int end_index, int target_start,
               int target_end);
void input();
void solve();

int main() {
  ios::sync_with_stdio(false);
  input();
  // solve();

  return 0;
}

void input() {
  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  solve();
  for (int i = 0; i < M + K; i++) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    if (a == 1) {
      change_target(1, b - 1, c, 0, N - 1);
      /*
      for (int i = 1; i <= 2 * N; i++) {
        cout << TreeSum[i] << '\t';
      }
      cout << endl;
      */
      A[b - 1] = c;
    } else {
      cout << partial_sum(1, 0, N - 1, b - 1, c - 1) << endl;
    }
  }
}

void solve() {
  fill_tree(1, 0, N - 1);
  /*
  for (int i = 1; i <= 2 * N; i++) {
    cout << TreeSum[i] << '\t';
  }
  cout << endl;
  */
}

void fill_tree(int tree_index, int start_index, int end_index) {
  if (start_index == end_index) {
    TreeSum[tree_index] = A[start_index];
    return;
  }
  int start = start_index;
  int mid = (end_index + start_index) / 2;
  int end = end_index;
  fill_tree(2 * tree_index, start, mid);
  fill_tree(2 * tree_index + 1, mid + 1, end_index);
  TreeSum[tree_index] = TreeSum[2 * tree_index] + TreeSum[2 * tree_index + 1];
  return;
}

void change_target(int tree_index, int target_index, ll target_num,
                   int start_index, int end_index) {
  if (target_index <= end_index && target_index >= start_index) {
    TreeSum[tree_index] -= A[target_index];
    TreeSum[tree_index] += target_num;
    if (start_index != end_index) {
      int mid = (start_index + end_index) / 2;
      if (target_index <= mid) {
        change_target(2 * tree_index, target_index, target_num, start_index,
                      mid);
      } else {
        change_target(2 * tree_index + 1, target_index, target_num, mid + 1,
                      end_index);
      }
    }
  }
}
ll partial_sum(int tree_index, int start_index, int end_index, int target_start,
               int target_end) {
  /*
cout << tree_index << " " << target_start << " " << target_end << " "
<< start_index << " " << end_index << endl;
  */
  if (target_start == start_index && target_end == end_index) {
    return TreeSum[tree_index];
  }
  int mid = (start_index + end_index) / 2;
  if (mid < target_start) {
    return partial_sum(2 * tree_index + 1, mid + 1, end_index, target_start,
                       target_end);
  } else if (mid >= target_end) {
    return partial_sum(2 * tree_index, start_index, mid, target_start,
                       target_end);
  } else {
    return partial_sum(2 * tree_index, start_index, mid, target_start, mid) +
           partial_sum(2 * tree_index + 1, mid + 1, end_index, mid + 1,
                       target_end);
  }
}
