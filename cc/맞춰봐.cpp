// unsolved
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int N;
char S[21][21];
bool Positive[11];
bool Minus[11];
bool zero;
int sum[11][11];

void input();
void solve();

int main() {
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N;
  getchar();

  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      S[i][j] = getchar();
    }
  }
}

void solve() {
  for (int i = 1; i <= 10; i++) {
    Minus[i] = false;
    Positive[i] = false;
  }
  Zero = false;

  int A[11];
  int positive_number = 0;
  int minus_number = 0;
  for (int i = 0; i < N; i++) {
    if (S[i][i] == '-') {
      minus_number++;
    } else if (S[i][i] == '+') {
      positive_number++;
    } else {
      A[i] = 0;
    }
  }
}
