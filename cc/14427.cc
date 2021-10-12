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
    cin >> a;
    if (a == 1) {
      cin >> b >> c;
      A[b] = c;
      change_target(1, 1, N, b, c);
    } else {
      cout << Tree[1] << endl;
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
