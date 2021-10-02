#include <iostream>
#include <vector>
//#include <algorithm>

#define endl '\n'

using namespace std;

int N;
vector<pair<int, int>> lists;
int answer = 0;

void input();
void solve();
void search(int now_index, int p);

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
    int t, p;
    cin >> t >> p;
    lists.push_back(make_pair(t, p));
  }
}

void solve() {
  search(0, 0);
  cout << answer;
}

void search(int now_index, int p) {
  if (now_index > N) {
    return;
  }
  if (now_index == N) {
    if (answer < p)
      answer = p;
    return;
  }
  // cout << "now_index: " << now_index << endl;
  search(lists[now_index].first + now_index, p + lists[now_index].second);
  search(now_index + 1, p);
}
