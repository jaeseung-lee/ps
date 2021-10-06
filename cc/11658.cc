#include <iostream>

using namespace std;

#define endl '\n'

int N, M;
int A[1025][1025];
int Tree[3 * 1025][3 * 1025];

void input();
void solve();
void fill_tree(int col_tree, int col_start, int col_end, int row_tree,
               int row_start, int row_end);
void fill_rest(int col_tree, int col_start, int col_end, int row_tree,
               int row_start, int row_end);
void change_target(int row_tree, int row_start, int row_end, int col_tree,
                   int col_start, int col_end, int target_row, int target_col,
                   int target_value);
void change_rest(int row_tree, int row_start, int row_end, int col_tree,
                 int col_start, int col_end, int target_row, int target_col,
                 int target_value);
int find_target(int row_tree, int row_start, int row_end, int col_tree,
                int col_start, int col_end, int r_target_start,
                int r_target_end, int c_target_start, int c_target_end);

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
    for (int j = 1; j <= N; j++) {
      cin >> A[i][j];
    }
  }
  fill_tree(1, 1, N, 1, 1, N);
  /*
  cout << "Tree : " << endl;
  for (int i = 1; i <= 12; i++) {
    for (int j = 1; j <= 12; j++) {
      cout << Tree[i][j] << '\t';
    }
    cout << endl;
  }
  */
}

void solve() {
  for (int i = 0; i < M; i++) {
    int a, b, c, d, e;
    cin >> a;
    if (a == 1) {
      cin >> b >> c >> d >> e;
      cout << find_target(1, 1, N, 1, 1, N, b, d, c, e) << endl;
    } else {
      cin >> b >> c >> d;
      change_target(1, 1, N, 1, 1, N, b, c, d);
      A[b][c] = d;
    }
  }
}

void fill_tree(int col_tree, int col_start, int col_end, int row_tree,
               int row_start, int row_end) {
  if (row_start == row_end) {
    if (col_start == col_end) {
      Tree[row_tree][col_tree] = A[row_start][col_start];
    }
    return;
  }

  if (col_start == col_end) {
    int row_mid = (row_start + row_end) / 2;
    fill_tree(col_tree, col_start, col_end, 2 * row_tree, row_start, row_mid);
    fill_tree(col_tree, col_start, col_end, 1 + 2 * row_tree, row_mid + 1,
              row_end);
    Tree[row_tree][col_tree] =
        Tree[2 * row_tree][col_tree] + Tree[2 * row_tree + 1][col_tree];

  } else {
    int col_mid = (col_start + col_end) / 2;
    fill_tree(2 * col_tree, col_start, col_mid, row_tree, row_start, row_end);
    fill_tree(2 * col_tree + 1, col_mid + 1, col_end, row_tree, row_start,
              row_end);
    Tree[row_tree][col_tree] =
        Tree[row_tree][2 * col_tree] + Tree[row_tree][2 * col_tree + 1];
    fill_rest(col_tree, col_start, col_end, row_tree, row_start, row_end);
  }
}

void fill_rest(int col_tree, int col_start, int col_end, int row_tree,
               int row_start, int row_end) {
  if (row_start == row_end) {
    Tree[row_tree][col_tree] =
        Tree[row_tree][2 * col_tree] + Tree[row_tree][2 * col_tree + 1];
    return;
  }
  int row_mid = (row_start + row_end) / 2;
  fill_rest(col_tree, col_start, col_end, row_tree * 2, row_start, row_mid);
  fill_rest(col_tree, col_start, col_end, row_tree * 2 + 1, row_mid + 1,
            row_end);
  Tree[row_tree][col_tree] =
      Tree[2 * row_tree][col_tree] + Tree[2 * row_tree + 1][col_tree];
}

void change_rest(int row_tree, int row_start, int row_end, int col_tree,
                 int col_start, int col_end, int target_row, int target_col,
                 int target_value) {
  if (row_start == row_end) {
    Tree[row_tree][col_tree] =
        Tree[row_tree][2 * col_tree] + Tree[row_tree][2 * col_tree + 1];
    return;
  }
  int row_mid = (row_start + row_end) / 2;
  if (target_row <= row_mid) {
    change_rest(2 * row_tree, row_start, row_mid, col_tree, col_start, col_end,
                target_row, target_col, target_value);
  } else {
    change_rest(2 * row_tree + 1, row_mid + 1, row_end, col_tree, col_start,
                col_end, target_row, target_col, target_value);
  }
  Tree[row_tree][col_tree] =
      Tree[row_tree * 2][col_tree] + Tree[row_tree * 2 + 1][col_tree];
}

void change_target(int row_tree, int row_start, int row_end, int col_tree,
                   int col_start, int col_end, int target_row, int target_col,
                   int target_value) {
  if (row_start == row_end) {
    if (row_start == target_row && col_start == target_col) {
      Tree[row_tree][col_tree] = target_value;
    }
    return;
  }

  if (col_start == col_end) {
    int row_mid = (row_start + row_end) / 2;
    if (target_row <= row_mid) {
      change_target(row_tree * 2, row_start, row_mid, col_tree, col_start,
                    col_end, target_row, target_col, target_value);
    } else {
      change_target(row_tree * 2 + 1, row_mid + 1, row_end, col_tree, col_start,
                    col_end, target_row, target_col, target_value);
    }
    Tree[row_tree][col_tree] =
        Tree[2 * row_tree][col_tree] + Tree[2 * row_tree + 1][col_tree];
  } else {
    int col_mid = (col_start + col_end) / 2;
    if (target_col <= col_mid) {
      change_target(row_tree, row_start, row_end, col_tree * 2, col_start,
                    col_mid, target_row, target_col, target_value);
    } else {
      change_target(row_tree, row_start, row_end, col_tree * 2 + 1, col_mid + 1,
                    col_end, target_row, target_col, target_value);
    }
    Tree[row_tree][col_tree] =
        Tree[row_tree][2 * col_tree] + Tree[row_tree][2 * col_tree + 1];
    change_rest(row_tree, row_start, row_end, col_tree, col_start, col_end,
                target_row, target_col, target_value);
  }
}

int find_target(int row_tree, int row_start, int row_end, int col_tree,
                int col_start, int col_end, int r_target_start,
                int r_target_end, int c_target_start, int c_target_end) {
  if (col_start == col_end ||
      (c_target_start == col_start && c_target_end == col_end)) {
    if (row_start == row_end ||
        (r_target_start == row_start && r_target_end == row_end)) {
      return Tree[row_tree][col_tree];
    } else {
      int row_mid = (row_start + row_end) / 2;
      if (r_target_end <= row_mid) {
        return find_target(2 * row_tree, row_start, row_mid, col_tree,
                           col_start, col_end, r_target_start, r_target_end,
                           c_target_start, c_target_end);
      } else if (r_target_start > row_mid) {
        return find_target(2 * row_tree + 1, row_mid + 1, row_end, col_tree,
                           col_start, col_end, r_target_start, r_target_end,
                           c_target_start, c_target_end);
      } else {
        return find_target(2 * row_tree, row_start, row_mid, col_tree,
                           col_start, col_end, r_target_start, row_mid,
                           c_target_start, c_target_end) +
               find_target(2 * row_tree + 1, row_mid + 1, row_end, col_tree,
                           col_start, col_end, row_mid + 1, r_target_end,
                           c_target_start, c_target_end);
      }
    }
  } else {
    int col_mid = (col_start + col_end) / 2;
    if (c_target_end <= col_mid) {
      return find_target(row_tree, row_start, row_end, 2 * col_tree, col_start,
                         col_mid, r_target_start, r_target_end, c_target_start,
                         c_target_end);
    } else if (c_target_start > col_mid) {
      return find_target(row_tree, row_start, row_end, 2 * col_tree + 1,
                         col_mid + 1, col_end, r_target_start, r_target_end,
                         c_target_start, c_target_end);
    } else {
      return find_target(row_tree, row_start, row_end, 2 * col_tree, col_start,
                         col_mid, r_target_start, r_target_end, c_target_start,
                         col_mid) +
             find_target(row_tree, row_start, row_end, 2 * col_tree + 1,
                         col_mid + 1, col_end, r_target_start, r_target_end,
                         col_mid + 1, c_target_end);
    }
  }
}
