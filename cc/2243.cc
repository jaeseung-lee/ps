#include <algorithm>
#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 1000001

int N;
// start~end 까지 원소의 합을 저장
unsigned int Tree[8000000];

unsigned int ans;

void input();
void solve();
// void fill_tree(int tree_index, int start, int end);
void find_target(int tree_index, int start, int end, int target_value);
void change_tree(int tree_index, int start, int end, int target_index,
                 int target_value);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() { cin >> N; }

void solve() {
  for (int i = 0; i < N; i++) {
    int A, B, C;
    cin >> A;
    if (A == 1) {
      cin >> B;
      find_target(1, 1, MAX, B);
      cout << ans << endl;
      change_tree(1, 1, MAX, ans, -1);
    } else {
      cin >> B >> C;
      change_tree(1, 1, MAX, B, C);
    }
  }
}

void find_target(int tree_index, int start, int end, int target_value) {
  if (start == end) {
    ans = start;
    return;
  }

  int mid = (start + end) / 2;
  if (target_value <= Tree[2 * tree_index]) {
    find_target(tree_index * 2, start, mid, target_value);
  } else {
    find_target(tree_index * 2 + 1, mid + 1, end,
                target_value - Tree[2 * tree_index]);
  }
}

void change_tree(int tree_index, int start, int end, int target_index,
                 int target_value) {
  if (start == end) {
    Tree[tree_index] += target_value;
    return;
  }
  int mid = (start + end) / 2;
  if (target_index <= mid) {
    change_tree(2 * tree_index, start, mid, target_index, target_value);
  } else {
    change_tree(2 * tree_index + 1, mid + 1, end, target_index, target_value);
  }
  Tree[tree_index] = Tree[2 * tree_index] + Tree[2 * tree_index + 1];
}
