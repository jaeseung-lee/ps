#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int N;
int A[1000 + 1];
int UP[1000 + 1];
int DOWN[1000 + 1];

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
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
}

void solve() {
  // boundary
  UP[1] = 1;
  DOWN[N] = 1;

  for (int i = 2; i <= N; i++) {
    UP[i] = 1;
    for (int j = 1; j < i; j++) {
      if (A[j] < A[i] && UP[j] + 1 > UP[i]) {
        UP[i] = UP[j] + 1;
      }
    }
    // cout << UP[i] << " ";
  }
  for (int i = N - 1; i >= 1; i--) {
    DOWN[i] = 1;
    for (int j = N; j > i; j--) {
      if (A[j] < A[i] && DOWN[j] + 1 > DOWN[i]) {
        DOWN[i] = DOWN[j] + 1;
      }
    }
    // cout << DOWN[i] << " ";
  }

  int answer = 0;
  for (int i = 1; i <= N; i++) {
    if (answer < UP[i] + DOWN[i] - 1) {
      answer = UP[i] + DOWN[i] - 1;
    }
  }
  cout << answer;
}
