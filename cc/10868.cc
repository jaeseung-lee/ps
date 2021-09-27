#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

int A[100001];
int Tree[800008];
int N, M;

void fill_Tree(int tree_index, int start_index, int end_index);
int find_target(int tree_index, int start_index, int end_index,
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
  fill_Tree(1, 1, N);
  /*
  for (int i = 1; i <= N; i++) {
    cout << Tree[i] << " ";
  }
  */
}

void solve() {
  for (int i = 0; i < M; i++) {
    int start, end;
    cin >> start >> end;
    cout << find_target(1, 1, N, start, end) << endl;
  }
}

void fill_Tree(int tree_index, int start_index, int end_index) {
  if (start_index == end_index) {
    Tree[tree_index] = A[start_index];
    return;
  }
  int mid = (start_index + end_index) / 2;
  fill_Tree(2 * tree_index, start_index, mid);
  fill_Tree(2 * tree_index + 1, mid + 1, end_index);
  Tree[tree_index] = min(Tree[tree_index * 2], Tree[tree_index * 2 + 1]);
}

int find_target(int tree_index, int start_index, int end_index,
                int target_start, int target_end) {
  if (start_index == end_index) {
    return Tree[tree_index];
  }

  if (start_index == target_start && end_index == target_end) {
    return Tree[tree_index];
  }

  int mid = (start_index + end_index) / 2;
  if (target_start > mid) {
    return find_target(2 * tree_index + 1, mid + 1, end_index, target_start,
                       target_end);
  } else if (target_end <= mid) {
    return find_target(2 * tree_index, start_index, mid, target_start,
                       target_end);
  } else {
    return min(find_target(2 * tree_index, start_index, mid, target_start, mid),
               find_target(2 * tree_index + 1, mid + 1, end_index, mid + 1,
                           target_end));
  }
}
