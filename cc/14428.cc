#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'

int N, M;
int A[100000 + 1];
int Tree[8 * 100000];

void input();
void solve();
void fill_tree(int tree_index, int start, int end);
void change_target(int tree_index, int start, int end, int target_index,
                   int target_value);
int find_target(int tree_index, int start, int end, int target_start,
                int target_end);

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
}

void solve() {
  cin >> M;
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      A[b] = c;
      change_target(1, 1, N, b, c);
    } else {
      cout << find_target(1, 1, N, b, c) << endl;
    }
  }
}

void fill_tree(int tree_index, int start, int end) {
  if (start == end) {
    Tree[tree_index] = start;
    return;
  }

  int mid = (start + end) / 2;
  fill_tree(2 * tree_index, start, mid);
  fill_tree(2 * tree_index + 1, mid + 1, end);
  if (A[Tree[2 * tree_index]] <= A[Tree[2 * tree_index + 1]]) {
    Tree[tree_index] = Tree[2 * tree_index];
  } else {
    Tree[tree_index] = Tree[2 * tree_index + 1];
  }
}

void change_target(int tree_index, int start, int end, int target_index,
                   int target_value) {
  if (start == end) {
    Tree[tree_index] = target_index;
    return;
  }
  int mid = (start + end) / 2;
  if (target_index <= mid) {
    change_target(2 * tree_index, start, mid, target_index, target_value);
  } else {
    change_target(2 * tree_index + 1, mid + 1, end, target_index, target_value);
  }

  if (A[Tree[2 * tree_index]] <= A[Tree[2 * tree_index + 1]]) {
    Tree[tree_index] = Tree[2 * tree_index];
  } else {
    Tree[tree_index] = Tree[2 * tree_index + 1];
  }
}

int find_target(int tree_index, int start, int end, int target_start,
                int target_end) {
  if (start == end) {
    return Tree[tree_index];
  }
  if (start == target_start && end == target_end) {
    return Tree[tree_index];
  }

  int mid = (start + end) / 2;
  int left_index, right_index;
  if (target_end <= mid) {
    return find_target(2 * tree_index, start, mid, target_start, target_end);

  } else if (target_start > mid) {
    return find_target(2 * tree_index + 1, mid + 1, end, target_start,
                       target_end);
  } else {
    left_index = find_target(2 * tree_index, start, mid, target_start, mid);
    right_index =
        find_target(2 * tree_index + 1, mid + 1, end, mid + 1, target_end);
  }

  if (A[left_index] <= A[right_index]) {
    return left_index;
  } else {
    return right_index;
  }
}