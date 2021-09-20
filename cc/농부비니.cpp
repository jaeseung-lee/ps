#include <iostream>
#include <vector>

#define endl '\n'
#define mod 1000000007

using namespace std;

int T;
vector<int> testcases;
long long a[10001][10][7];
long long b[10001][10][7];

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
    int temp;
    cin >> temp;
    testcases.push_back(temp);
  }
}

void solve() {
  // boundary
  for (int k = 0; k < 7; k++) {
    a[1][0][k] = 0;
  }
  for (int j = 1; j < 10; j++) {
    for (int k = 0; k < 7; k++) {
      if (j % 7 == k % 7) {
        a[1][j][k] = 1;
        b[1][j][k] = 1;
      } else {
        a[1][j][k] = 0;
        b[1][j][k] = 0;
      }
    }
  }

  b[1][7][0] = 0;

  // fill a
  for (int i = 2; i <= 10000; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 7; k++) {
        int index = k - (j % 7);
        if (index < 0) {
          index += 7;
        }
        a[i][j][k] = 0;
        for (int l = 0; l < 10; l++) {
          a[i][j][k] += a[i - 1][l][index];
        }
        a[i][j][k] %= mod;
      }
    }
  }

  // fill b
  for (int i = 2; i <= 10000; i++) {
    for (int j = 0; j < 10; j++) {
      if (j == 7 || j == 0) {
        for (int k = 0; k < 7; k++) {
          b[i][j][k] = 0;
        }
      } else {
        for (int k = 0; k < 7; k++) {
          int index = k - (j % 7);
          if (index < 0) {
            index += 7;
          }
          b[i][j][k] = 0;
          for (int l = 0; l < 10; l++) {
            b[i][j][k] += b[i - 1][l][index];
          }
          b[i][j][k] %= mod;
        }
      }
    }
  }

  for (int testcases_index = 0; testcases_index < T; testcases_index++) {
    int target = testcases[testcases_index];
    long long answer = 0;
    for (int j = 0; j < 10; j++) {
      // cout << a[target][j][0] <<" "<<b[target][j][0] << endl;
      answer += a[target][j][0];
      if (j != 7) {
        answer -= b[target][j][0];
      }
    }
    answer %= mod;
    if (answer < 0) {
      answer += mod;
    }
    cout << answer << endl;
  }
  cout << endl;
}
