#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int N;
vector<int> A;
vector<int> ans;

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
    int temp;
    cin >> temp;
    A.push_back(temp);
  }
}

void solve() {
  for (int i = 0; i < N; i++) {
    if (ans.empty()) {
      ans.push_back(A[i]);
    } else {
      if (ans.back() < A[i]) {
        ans.push_back(A[i]);
      } else {
        auto iter = lower_bound(ans.begin(), ans.end(), A[i]);
        if (*iter > A[i]) {
          *iter = A[i];
        }
      }
    }
  }
  cout << ans.size() << endl;
}