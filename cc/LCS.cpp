//문자열의 최대 크기를 MAX로 define 해놓고, 문자열의 길이를 cstring의 strlen으로
//자르자.

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000
#define endl '\n'

int answer = 0;
vector<vector<int>> dp;
char first[MAX + 1];
char second[MAX + 1];
int f_length;
int s_length;

void input();
void solve();
void init_dp();
void fill_dp();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  cout << answer;

  return 0;
}

void input() {
  cin >> first >> second;
  f_length = strlen(first);
  s_length = strlen(second);
}

void solve() {
  init_dp();
  fill_dp();
  /*
    for(auto row : dp){
      for(int col : row){
        cout << col << " ";
      }
      cout << endl;
    }
    */
  answer = dp[f_length][s_length];
}

void init_dp() {
  for (int i = 0; i <= f_length; i++) {
    vector<int> temp;
    for (int j = 0; j <= s_length; j++) {
      temp.push_back(0);
    }
    dp.push_back(temp);
  }
}

void fill_dp() {
  for (int i = 1; i <= f_length; i++) {
    for (int j = 1; j <= s_length; j++) {
      if (first[i - 1] == second[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        if (dp[i - 1][j] > dp[i][j - 1]) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
  }
}
