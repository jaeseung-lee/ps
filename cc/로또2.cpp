#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define ll long long

int T;
vector<pair<int, int>> testcases;
int pow2[11];
ll dp[10 + 1][2000 + 1];
int boundaries[10 + 1];

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
    int n, m;
    cin >> n >> m;
    testcases.push_back(make_pair(n, m));
  }
}

void solve() {
  int value = 1;
  for (int i = 0; i < 11; i++) {
    pow2[i] = value;
    value = value * 2;
  }

  for (int t = 0; t < T; t++) {
    int n = testcases[t].first;
    int m = testcases[t].second;
    int value = m;
    for (int i = n; i >= 1; i--) {
      boundaries[i] = value;
      value = value / 2;
    }

    // boundary
    for (int i = 1; i <= n; i++) {
      dp[i][pow2[i - 1]] = 1;
    }
    for (int i = 1; i <= m; i++) {
      dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
      for (int j = pow2[i - 1]; j <= boundaries[i]; j++) {
        dp[i][j] = 0;
        // cout << "dp[" << i << "][" << j << "] : ";
        for (int k = pow2[i - 2]; k <= j / 2; k++) {
          dp[i][j] += dp[i - 1][k];
          // cout << "dp["<<i-1<<"]["<<k<<"] ";
        }
        // cout << endl;
      }
    }
    ll answer = 0;
    for (int i = pow2[n - 1]; i <= m; i++) {
      answer += dp[n][i];
    }
    cout << answer << endl;
  }
}
