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
void dfs(int start, int end);

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
  int temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    A.push_back(temp);
  }
}

void solve() {
  dfs(0, N - 1);
  cout << ans << endl;
}

void dfs(int start, int end) {
  if (start == end) {
    return;
  }
  int mid = (start + end) / 2;
  dfs(start, mid);
  dfs(mid + 1, end);
  auto target_start = A.begin();
  advance(target_start, mid + 1);
  auto target_end = A.begin();
  advance(target_end, end + 1);
  for (int i = start; i <= mid; i++) {
    auto iter_start = A.begin();
    advance(iter_start, i);
    ans += distance(target_start, lower_bound(target_start, target_end, A[i]));
  }
  auto iter_start = A.begin();
  auto iter_end = A.begin();
  advance(iter_start, start);
  advance(iter_end, end + 1);
  sort(iter_start, iter_end);
}
