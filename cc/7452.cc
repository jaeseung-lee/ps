#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int N;
vector<int> A, B, C, D;
vector<int> AB, CD;
long long ans = 0;

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
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    A.push_back(a);
    B.push_back(b);
    C.push_back(c);
    D.push_back(d);
  }
}

void solve() {
  for (int a = 0; a < N; a++) {
    for (int b = 0; b < N; b++) {
      AB.push_back(A[a] + B[b]);
    }
  }
  for (int c = 0; c < N; c++) {
    for (int d = 0; d < N; d++) {
      CD.push_back(C[c] + D[d]);
    }
  }
  sort(AB.begin(), AB.end());
  sort(CD.begin(), CD.end());

  // lower_bound로 보자
  for (int i = 0; i < AB.size(); i++) {
    auto lower_iter = lower_bound(CD.begin(), CD.end(), -AB[i]);
    if (*lower_iter != -AB[i]) {
      continue;
    }
    auto upper_iter = upper_bound(CD.begin(), CD.end(), -AB[i]);
    ans += distance(lower_iter, upper_iter);
  }
  cout << ans << endl;
}
