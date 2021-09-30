#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

#define endl '\n'

int N;
vector<int> A;
long long ans = 0;

void input();
void solve();
void dfs(int start_index, int end_index);

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
  dfs(0, N - 1);
  cout << ans << endl;
}

void dfs(int start_index, int end_index) {
  if (start_index == end_index) {
    return;
  }
  int mid = (start_index + end_index) / 2;
  dfs(start_index, mid);
  dfs(mid + 1, end_index);
  auto start_iter = A.begin();
  advance(start_iter, start_index);
  auto end_iter = A.begin();
  advance(end_iter, end_index + 1);
  auto mid_iter = A.begin();
  advance(mid_iter, mid + 1);
  for (int i = start_index; i <= mid; i++) {
    ans += distance(mid_iter, lower_bound(mid_iter, end_iter, A[i]));
  }
  sort(start_iter, end_iter);
}
