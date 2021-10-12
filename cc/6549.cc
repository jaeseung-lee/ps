#include <algorithm>
#include <iostream>
#include <iterator>
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

  vector<int> A = {2, 1, 4, 5, 7, 8, 8};
  auto iter = lower_bound(A.begin(), A.end(), 5);
  cout << *iter << endl;
  /*
  while (true) {
    input();
    solve();
  }
  */

  return 0;
}

void input() {
  cin >> N;
  if (N == 0) {
    exit(0);
  }
}

void solve() {}