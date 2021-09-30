#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define MAX 100000
#define mod 1000000009

vector<int> targets;
int T;
vector<int> a(MAX + 1);
vector<int> b(MAX + 1);
vector<int> c(MAX + 1);

void input();
void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
  input();

  return 0;
}

void input() {
  cin >> T;
  for (int i = 0; i < T; i++) {
    int n;
    cin >> n;
    cout << (a[n] + b[n] + c[n]) % mod << endl;
  }
}

void solve() {
  // boundary
  a[0] = 0;
  a[1] = 1;  // 1
  a[2] = 0;  // ����
  a[3] = 1;  // 2 + 1
  b[0] = 0;
  b[1] = 0;
  b[2] = 1;  // 2
  b[3] = 1;  // 1 + 2
  c[0] = 0;
  c[1] = 0;
  c[2] = 0;
  c[3] = 1;  // 3

  // fill up
  for (int j = 4; j <= MAX; j++) {
    a[j] = (b[j - 1] + c[j - 1]) % mod;
    b[j] = (a[j - 2] + c[j - 2]) % mod;
    c[j] = (a[j - 3] + b[j - 3]) % mod;
  }
}