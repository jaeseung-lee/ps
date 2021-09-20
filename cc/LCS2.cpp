#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define endl '\n'

string A;
string B;
int A_len;
int B_len;
int dp[1001][1001];

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
  cin >> A >> B;
  A_len = A.length();
  B_len = B.length();
}

void solve() {
  // boundary
  if (A[0] == B[0]) {
    dp[0][0] = 1;
  } else {
    dp[0][0] = 0;
  }
  for (int i = 1; i < A_len; i++) {
    if (B[0] == A[i]) {
      dp[i][0] = 1;
    } else {
      dp[i][0] = dp[i - 1][0];
    }
  }
  for (int i = 1; i < B_len; i++) {
    if (A[0] == B[i]) {
      dp[0][i] = 1;
    } else {
      dp[0][i] = dp[0][i - 1];
    }
  }

  for (int i = 1; i < A_len; i++) {
    for (int j = 1; j < B_len; j++) {
      if (A[i] == B[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  cout << dp[A_len - 1][B_len - 1] << endl;
  if (dp[A_len - 1][B_len - 1] == 0) {
    return;
  }

  /*
    for(int i=0;i<A_len;i++){
      for(int j=0;j<B_len;j++){
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }
  */

  stack<char> answer;
  int i = A_len - 1;
  int j = B_len - 1;
  while (i > 0 && j > 0) {
    if (A[i] == B[j]) {
      answer.push(A[i]);
      i--;
      j--;
    } else {
      if (dp[i - 1][j] == dp[i][j]) {
        i--;
      } else {
        j--;
      }
    }
  }
  if (dp[i][j] == 1) {
    if (i == 0) {
      answer.push(A[0]);
    } else {
      answer.push(B[0]);
    }
  }

  while (!answer.empty()) {
    cout << answer.top();
    answer.pop();
  }
}
