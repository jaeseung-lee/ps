#include <iostream>

using namespace std;

#define endl '\n'

int N, M;
int A[10000 + 1];

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
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
}

void solve() {
  int start_index = 0;
  int end_index = 0;
  int answer = 0;
  int sum = 0;
  while (end_index <= N) {
    if (sum >= M) {
      start_index++;
      sum -= A[start_index];
    } else {
      end_index++;
      sum += A[end_index];
    }
    if (sum == M) {
      answer++;
    }
  }
  cout << answer;
}
