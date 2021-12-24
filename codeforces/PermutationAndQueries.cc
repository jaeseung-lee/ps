#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int numbers[100001];
int n, q;
int op, a, b;
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

void input() { cin >> n >> q; }

void solve() {
  for (int i = 1; i <= n; i++) {
    cin >> numbers[i];
  }

  while (q > 0) {
    q--;
    cin >> op >> a >> b;
    if (op == 1) {
      int temp = numbers[a];
      numbers[a] = numbers[b];
      numbers[b] = temp;
    } else {
      int ans = numbers[a];
      while (b > 1) {
        b--;
        ans = numbers[ans];
      }
      cout << ans << endl;
    }
  }
}
