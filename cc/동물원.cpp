#include <iostream>
#include <vector>

#define endl '\n'
#define mod 9901

using namespace std;
enum Status { EMPTY, LEFT, RIGHT };

int N;
int dp[100000 + 1][4];

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

void input() { cin >> N; }

void solve() {
  // boundary
  dp[1][EMPTY] = 1;
  dp[1][LEFT] = 1;
  dp[1][RIGHT] = 1;

  for (int i = 2; i <= N; i++) {
    dp[i][EMPTY] =
        (dp[i - 1][EMPTY] + dp[i - 1][LEFT] + dp[i - 1][RIGHT]) % mod;
    dp[i][LEFT] = (dp[i - 1][RIGHT] + dp[i - 1][EMPTY]) % mod;
    dp[i][RIGHT] = (dp[i - 1][LEFT] + dp[i - 1][EMPTY]) % mod;
  }

  cout << (dp[N][EMPTY] + dp[N][RIGHT] + dp[N][LEFT]) % mod;
}
