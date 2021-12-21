#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int N;
int ans = 1000000001;
vector<pair<int, int>> foods;
void input();
void solve();

void dfs(int food_index, int S, int B, int food_number);

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
    int a, b;
    cin >> a >> b;
    foods.push_back(make_pair(a, b));
  }
}

void solve() {
  dfs(0, 1, 0, 0);
  cout << ans << endl;
}

void dfs(int food_index, int S, int B, int food_number) {
  if (food_index == N) {
    if (abs(S - B) < ans && food_number != 0) {
      ans = abs(S - B);
    }
    return;
  }
  dfs(food_index + 1, S * foods[food_index].first, B + foods[food_index].second,
      food_number + 1);
  dfs(food_index + 1, S, B, food_number);
}
