#include <iostream>

using namespace std;

#define endl '\n'

bool isPrime[20];
bool number[100001];
int A, B;
int ans = 0;

void input();
void solve();
int div(int target) {
  int result = 1;
  for (int i = 2; i * i <= target; i++) {
    if (target % i == 0) {
      result++;
      target /= i;
      i = 1;
    }
  }
  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() { cin >> A >> B; }

void solve() {
  // 소수
  isPrime[2] = true;
  isPrime[3] = true;
  isPrime[5] = true;
  isPrime[7] = true;
  isPrime[11] = true;
  isPrime[13] = true;
  isPrime[17] = true;
  isPrime[19] = true;

  for (int i = 2; i <= 100001; i++) {
    number[i] = isPrime[div(i)];
  }
  for (int i = A; i <= B; i++) {
    if (number[i]) {
      ans++;
    }
  }
  cout << ans;
}
