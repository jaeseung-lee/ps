#include <iostream>

using namespace std;

#define ll long long
int N;
int A[100];
int target;
ll ans[21];
ll temp[21];

void input();
void solve();
bool is_promising(int value);

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
  for (int i = 0; i < N - 1; i++) {
    cin >> A[i];
  }
  cin >> target;
}

void solve() {
  ans[A[0]] = 1;
  for (int i = 1; i < N - 1; i++) {
    // initialize temp
    for (int j = 0; j <= 20; j++) {
      temp[j] = 0;
    }

    for (int j = 0; j <= 20; j++) {
      if (is_promising(j + A[i])) {
        temp[j + A[i]] += ans[j];
      } else {
        break;
      }
    }
    for (int j = 20; j >= 0; j--) {
      if (is_promising(j - A[i])) {
        temp[j - A[i]] += ans[j];
      } else {
        break;
      }
    }
    for (int j = 0; j <= 20; j++) {
      ans[j] = temp[j];
    }
  }
  cout << ans[target];
}

bool is_promising(int value) { return value >= 0 && value <= 20; }
