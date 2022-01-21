#include <algorithm>
#include <cstring>
#include <iostream>

#define endl '\n'

using namespace std;

int dp[1000000 + 1];  // dp[i] : i 비용으로 만들 수 있는 고객수
int N, C;
pair<int, int> A[21];  //<비용, 고객수>
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
  cin >> C >> N;
  for (int i = 1; i <= N; i++) {
    int c, n;
    cin >> c >> n;
    A[i] = make_pair(c, n);
  }
}

void solve() {
  for (int i = 0; i <= 1000000; i++) {
    for (int j = 1; j <= N; j++) {
      if (i - A[j].first >= 0 && dp[i] < dp[i - A[j].first] + A[j].second) {
        dp[i] = dp[i - A[j].first] + A[j].second;
      }
    }
  }
  for (int i = 0; i <= 1000000; i++) {
    if (dp[i] >= C) {
      cout << i << endl;
      break;
    }
  }
}
