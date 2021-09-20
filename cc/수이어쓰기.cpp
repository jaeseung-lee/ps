#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int N;
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
  int log10 = 1;
  int temp = N;
  int answer = 0;
  int pow_10 = 1;
  while (true) {
    if (temp / 10 == 0) {
      answer += log10 * (N - pow_10 + 1);
      break;
    } else {
      answer += pow_10 * 9 * log10;
      pow_10 = pow_10 * 10;
      log10++;
      temp = temp / 10;
    }
  }
  cout << answer;
}
