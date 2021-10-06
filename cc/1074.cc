#include <algorithm>
#include <iostream>

using namespace std;
#define endl '\n'

int N, r, c;
int ans = 0;
int pow2[16];

void input();
void solve();

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N >> r >> c;
  int value = 1;
  for (int i = 0; i <= 15; i++) {
    pow2[i] = value;
    value = value * 2;
  }
}

void solve() {
  int i;
  for (i = 0; i <= 15; i++) {
    if (r < pow2[i]) {
      i--;
      break;
    }
  }
  int j;
  for (j = 0; j <= 15; j++) {
    if (c < pow2[j]) {
      j--;
      break;
    }
  }
  while (i >= 0 || j >= 0) {
    if (i < j) {
      ans += pow2[j] * pow2[j];
      c -= pow2[j];
    } else if (i > j) {
      ans += pow2[i] * pow2[i] * 2;
      r -= pow2[i];
    } else {
      ans += pow2[i] * pow2[i] * 3;
      c -= pow2[j];
      r -= pow2[i];
    }

    for (i = 0; i <= 15; i++) {
      if (r < pow2[i]) {
        i--;
        break;
      }
    }
    for (j = 0; j <= 15; j++) {
      if (c < pow2[j]) {
        j--;
        break;
      }
    }
  }
  std::cout << ans << endl;
}
