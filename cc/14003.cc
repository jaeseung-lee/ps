#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

#define endl '\n'

int N;
vector<int> A;
vector<int> ans;
vector<int> A_index;
vector<int> real_ans;

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
      A_index.push_back(i);
    } else {
      if (ans.back() < A[i]) {
        ans.push_back(A[i]);
        A_index.push_back(ans.size() - 1);
      } else {
        auto iter = lower_bound(ans.begin(), ans.end(), A[i]);
        if (*iter > A[i]) {
          *iter = A[i];
        }
        A_index.push_back(distance(ans.begin(), iter));
      }
    }
  }
  cout << ans.size() << endl;
  int index = ans.size() - 1;
  for (int i = A_index.size() - 1; i >= 0; i--) {
    if (index == A_index[i]) {
      real_ans.push_back(A[i]);
      index--;
    }
  }
  for (int i = real_ans.size() - 1; i >= 0; i--) {
    cout << real_ans[i] << " ";
  }
}