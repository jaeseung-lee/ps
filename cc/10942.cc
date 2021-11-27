#include <iostream>

using namespace std;

#define endl '\n'

int N, M;
int A[2001];
bool dp[2001][2001];
void input();
void fillDP();
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
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  fillDP();
  cin >> M;
}

void fillDP() {
  for (int i = 1; i <= N; i++) {
    dp[i][i] = true;
  }
  for (int i = 1; i < N; i++) {
    if (A[i] == A[i + 1]) {
      dp[i][i + 1] = true;
    }
  }
  for (int length = 2; length < N; length++) {
    for (int i = 1; i + length <= N; i++) {
      int a = i;
      int b = i + length;
      if (A[a] != A[b]) {
        continue;
      } else if (!dp[a + 1][b - 1]) {
        continue;
      } else {
        dp[a][b] = true;
      }
    }
  }
}

void solve() {
  int S, E;
  for (int m = 0; m < M; m++) {
    cin >> S >> E;
    cout << dp[S][E] << endl;
  }
}
