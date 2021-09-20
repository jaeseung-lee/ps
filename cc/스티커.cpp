#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

enum Status { UP, DOWN, EMPTY };

int T;
vector<int> tests;
vector<vector<vector<int>>> A;
vector<int> n_sizes;

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
  cin >> T;
  for (int i = 0; i < T; i++) {
    int n;
    cin >> n;
    n_sizes.push_back(n);
    vector<vector<int>> temp;
    for (int j = 0; j < 2; j++) {
      vector<int> row;
      for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        row.push_back(element);
      }
      temp.push_back(row);
    }
    A.push_back(temp);
  }
}

void solve() {
  for (int i = 0; i < T; i++) {
    int dp[3][100000];
    // boundary
    dp[UP][0] = A[i][0][0];
    dp[DOWN][0] = A[i][1][0];
    dp[EMPTY][0] = 0;
    // cout << dp[EMPTY][0] << " " << dp[UP][0] << " " << dp[DOWN][0] << endl;

    for (int j = 1; j < n_sizes[i]; j++) {
      if (dp[DOWN][j - 1] > dp[EMPTY][j - 1]) {
        dp[UP][j] = dp[DOWN][j - 1] + A[i][0][j];
      } else {
        dp[UP][j] = dp[EMPTY][j - 1] + A[i][0][j];
      }

      if (dp[EMPTY][j - 1] > dp[UP][j - 1]) {
        dp[DOWN][j] = dp[EMPTY][j - 1] + A[i][1][j];
      } else {
        dp[DOWN][j] = dp[UP][j - 1] + A[i][1][j];
      }

      dp[EMPTY][j] = dp[EMPTY][j - 1];
      if (dp[EMPTY][j] < dp[UP][j - 1]) {
        dp[EMPTY][j] = dp[UP][j - 1];
      }
      if (dp[EMPTY][j] < dp[DOWN][j - 1]) {
        dp[EMPTY][j] = dp[DOWN][j - 1];
      }
      // cout << dp[EMPTY][j] << " " << dp[UP][j] << " " << dp[DOWN][j] << endl;
    }

    int answer = dp[EMPTY][n_sizes[i] - 1];
    if (answer < dp[UP][n_sizes[i] - 1]) {
      answer = dp[UP][n_sizes[i] - 1];
    }
    if (answer < dp[DOWN][n_sizes[i] - 1]) {
      answer = dp[DOWN][n_sizes[i] - 1];
    }
    cout << answer << endl;
  }
}
