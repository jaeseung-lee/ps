#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int N;
bool number[4000001];
vector<int> prime_numbers;
int dp[4000001];

void fillPrimeNumbers();
void input();
void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fillPrimeNumbers();
  input();
  solve();

  return 0;
}

void fillPrimeNumbers() {
  memset(number, true, sizeof(number));
  number[1] = false;
  for (int i = 2; i <= 4000000; i++) {
    if (number[i]) {
      for (int j = 2; j * i <= 4000000; j++) {
        number[j * i] = false;
      }
      prime_numbers.push_back(i);
      int temp = 0;
      for (int j = prime_numbers.size() - 1; j >= 0; j--) {
        temp += prime_numbers[j];
        if (temp > 4000000) {
          break;
        }
        dp[temp]++;
      }
    }
  }
}

void input() { cin >> N; }

void solve() { cout << dp[N] << endl; }
