#include <iostream>

using namespace std;

#define endl '\n'
#define ll long long

pair<ll, ll> Tree[8000000 + 1];
ll A[1000000 + 1];
int N, K, M;
ll ans = 0;

void input();
void solve();
void fill_tree(int tree_index, int start_index, int end_index);
void insert_target(int tree_index, int start_index, int end_index,
                   int target_start, int target_end, ll target_value);
ll find_target(int tree_index, int start_index, int end_index, int target_start,
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
      /*
      cout << "Tree : " << endl;
      for (int i = 1; i <= 2 * N; i++) {
        cout << Tree[i].first << " " << Tree[i].second << endl;
      }
      */

    } else {
      cin >> b >> c;
      cout << find_target(1, 1, N, b, c) << endl;
    }
  }
}

void fill_tree(int tree_index, int start_index, int end_index) {
  if (start_index == end_index) {
    Tree[tree_index] = make_pair(A[start_index], 0);
    return;
  }
  int mid = (start_index + end_index) / 2;
  fill_tree(2 * tree_index, start_index, mid);
  fill_tree(2 * tree_index + 1, mid + 1, end_index);
  Tree[tree_index] =
      make_pair(Tree[2 * tree_index].first + Tree[2 * tree_index + 1].first, 0);
  return;
}

void insert_target(int tree_index, int start_index, int end_index,
                   int target_start, int target_end, ll target_value) {
  if (start_index == end_index) {
    Tree[tree_index].second += target_value;
    return;
  }
  if (start_index == target_start && end_index == target_end) {
    Tree[tree_index].second += target_value;
    return;
  }

  int mid = (start_index + end_index) / 2;
  Tree[tree_index].first += target_value * (target_end - target_start + 1);
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

ll find_target(int tree_index, int start_index, int end_index, int target_start,
               int target_end) {
  // cout << "tree_index : " << tree_index << endl;
  if (Tree[tree_index].second != 0) {
    Tree[tree_index].first +=
        Tree[tree_index].second * (end_index - start_index + 1);
    if (start_index != end_index) {
      Tree[2 * tree_index].second += Tree[tree_index].second;
      Tree[2 * tree_index + 1].second += Tree[tree_index].second;
    }
    Tree[tree_index].second = 0;
  }

  if (start_index == end_index) {
    return Tree[tree_index].first;
  }

  if (start_index == target_start && end_index == target_end) {
    return Tree[tree_index].first;
  }

  int mid = (start_index + end_index) / 2;
  if (target_end <= mid) {
    return find_target(2 * tree_index, start_index, mid, target_start,
                       target_end);
  } else if (mid < target_start) {
    return find_target(2 * tree_index + 1, mid + 1, end_index, target_start,
                       target_end);
  } else {
    ll left, right;
    left = find_target(2 * tree_index, start_index, mid, target_start, mid);
    right = find_target(2 * tree_index + 1, mid + 1, end_index, mid + 1,
                        target_end);
    // cout << "tree_index : " << tree_index << endl;
    // cout << "left : " << left << " right : " << right << endl;
    return left + right;
  }
}
