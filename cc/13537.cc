#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

#define endl '\n'

int N, M;
int A[100001];
int ans = 0;
vector<int> Tree[800008];

void input();
void solve();
void fill_tree(int tree_index, int start_index, int end_index);
void fill_answer(int tree_index, int start_index, int end_index,
                 int target_start, int target_end, int target_value);

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
  fill_tree(1, 1, N);
  cin >> M;
  /*
  for (int i = 1; i <= 10; i++) {
    for (auto element : Tree[i]) {
      cout << element << " ";
    }
    cout << endl;
  }
  */
}

void solve() {
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    ans = 0;
    fill_answer(1, 1, N, a, b, c);
    cout << ans << endl;
  }
}

void fill_tree(int tree_index, int start_index, int end_index) {
  // cout << tree_index << " " << start_index << " " << end_index << endl;
  if (start_index == end_index) {
    Tree[tree_index].push_back(A[start_index]);
    return;
  }
  int mid = (start_index + end_index) / 2;
  fill_tree(2 * tree_index, start_index, mid);
  fill_tree(2 * tree_index + 1, mid + 1, end_index);
  Tree[tree_index].insert(Tree[tree_index].begin(),
                          Tree[2 * tree_index + 1].begin(),
                          Tree[2 * tree_index + 1].end());
  Tree[tree_index].insert(Tree[tree_index].begin(),
                          Tree[2 * tree_index].begin(),
                          Tree[2 * tree_index].end());
  sort(Tree[tree_index].begin(), Tree[tree_index].end());
}

void fill_answer(int tree_index, int start_index, int end_index,
                 int target_start, int target_end, int target_value) {
  if (start_index == end_index) {
    if (target_value < Tree[tree_index][0]) {
      ans++;
    }
    return;
  }
  if (start_index == target_start && end_index == target_end) {
    auto iter = upper_bound(Tree[tree_index].begin(), Tree[tree_index].end(),
                            target_value);
    ans += distance(iter, Tree[tree_index].end());
    return;
  }

  int mid = (start_index + end_index) / 2;
  if (target_end <= mid) {
    fill_answer(2 * tree_index, start_index, mid, target_start, target_end,
                target_value);
  } else if (target_start > mid) {
    fill_answer(2 * tree_index + 1, mid + 1, end_index, target_start,
                target_end, target_value);
  } else {
    fill_answer(2 * tree_index, start_index, mid, target_start, mid,
                target_value);
    fill_answer(2 * tree_index + 1, mid + 1, end_index, mid + 1, target_end,
                target_value);
  }
}
