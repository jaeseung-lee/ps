#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'
#define ll long long

using namespace std;

int T;
vector<pair<ll, ll>> testcases;

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
  cin >> T;
  for (int i = 0; i < T; i++) {
    ll a, b;
    cin >> a >> b;
    testcases.push_back(make_pair(a, b));
  }
}

void solve() {
  priority_queue<pair<ll, int>> PQ;
  vector<ll> answer;
  for (int t = 0; t < T; t++) {
    ll target = testcases[t].second - testcases[t].first;
    PQ.push(make_pair(-target, t));
    answer.push_back(0);
  }

  ll n = 1;
  while (!PQ.empty()) {
    if (-PQ.top().first <= n * n) {
      answer[PQ.top().second] = n * 2 - 1;
      PQ.pop();
      continue;
    }

    if (-PQ.top().first <= n * (n + 1)) {
      answer[PQ.top().second] = n * 2;
      PQ.pop();
      continue;
    }
    n++;
  }

  for (int t = 0; t < T; t++) {
    cout << answer[t] << endl;
  }
}
