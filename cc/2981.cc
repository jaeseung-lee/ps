#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int N;
vector<int> numbers;

void input();
void solve();
int gcd(int a, int b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();
  // cout << gcd(90, 40);
  return 0;
}

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    numbers.push_back(temp);
  }
  sort(numbers.begin(), numbers.end());
  int value = numbers[0];
  for (int i = 0; i < N; i++) {
    numbers[i] -= value;
  }
}

void solve() {
  int ans = numbers[1];
  for (int i = 1; i < N; i++) {
    ans = gcd(ans, numbers[i]);
  }
  cout << ans << endl;
}

int gcd(int a, int b) {
  int max, min;
  if (a > b) {
    max = a, min = b;
  } else {
    max = b, min = a;
  }
  if (max % min == 0) {
    return min;
  } else {
    return gcd(max % min, min);
  }
}
