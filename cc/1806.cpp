#include <iostream>

using namespace std;

#define endl '\n'
#define INF 999999999
int N, S;
int A[100000 + 1];

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
  cin >> N >> S;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
}

void solve() {
  int answer = INF;
  int start = 0;
  int end = 0;
  int sum = 0;
  while (end <= N) {
    if (sum >= S) {
      start++;
      sum -= A[start];
    } else {
      end++;
      sum += A[end];
    }
    if (sum >= S && answer > (end - start)) {
      answer = end - start;
    }
  }
  if (answer != INF) {
    cout << answer << endl;
  } else {
    cout << "0" << endl;
  }
}
