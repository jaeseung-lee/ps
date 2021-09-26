#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

int N, M;
int A[100001];
// <max,min>
pair<int, int> Tree[800008];
void fill_Tree(int tree_index, int start_index, int end_index);
pair<int, int> find_target(int tree_index, int start_index, int end_index,
                           int target_start, int target_end);

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
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
}

void solve() {
  // construct segment-tree
  fill_Tree(1, 1, N);

  for (int i = 0; i < M; i++) {
    int start, end;
    cin >> start >> end;
    pair<int, int> ans = find_target(1, 1, N, start, end);
    cout << ans.first << " " << ans.second << endl;
  }
}

void fill_Tree(int tree_index, int start_index, int end_index) {
  if (start_index == end_index) {
    Tree[tree_index] = make_pair(A[start_index], A[start_index]);
  } else {
    int mid = (start_index + end_index) / 2;
    fill_Tree(2 * tree_index, start_index, mid);
    fill_Tree(2 * tree_index + 1, mid + 1, end_index);
    int m = min(Tree[2 * tree_index].first, Tree[2 * tree_index + 1].first);
    int M = max(Tree[2 * tree_index].second, Tree[2 * tree_index + 1].second);
    Tree[tree_index] = make_pair(m, M);
  }
}

pair<int, int> find_target(int tree_index, int start_index, int end_index,
                           int target_start, int target_end) {
  if (start_index == end_index) {
    return Tree[tree_index];
  }
  if (start_index == target_start && end_index == target_end) {
    return Tree[tree_index];
  }
  int mid = (start_index + end_index) / 2;
  if (mid < target_start) {
    return find_target(2 * tree_index + 1, mid + 1, end_index, target_start,
                       target_end);
  } else if (mid >= target_end) {
    return find_target(2 * tree_index, start_index, mid, target_start,
                       target_end);
  } else {
    pair<int, int> fst =
        find_target(2 * tree_index, start_index, mid, target_start, mid);
    pair<int, int> snd = find_target(2 * tree_index + 1, mid + 1, end_index,
                                     mid + 1, target_end);
    return make_pair(min(fst.first, snd.first), max(fst.second, snd.second));
  }
}
