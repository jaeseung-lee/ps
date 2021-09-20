#include <iostream>
#include <queue>

using namespace std;
#define endl '\n'
#define ll long long

ll L, N, RF, RB;
ll relative;                                            // 상대속도
pair<ll, ll> grass[1000000 + 1];                        // (x,c) 정보
priority_queue<pair<pair<ll, ll>, pair<ll, ll>>> infos; // (c*t,(c,t))
ll answer = 0;

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
  cin >> L >> N >> RF >> RB;
  for (int i = 0; i < N; i++) {
    ll x, c;
    cin >> x >> c;
    grass[i] = make_pair(x, c);
  }
}

void solve() {
  relative = RF - RB;
  // fill infos
  for (int i = 0; i < N; i++) {
    ll time = relative * grass[i].first;
    infos.push(make_pair(make_pair(grass[i].second * time, -grass[i].first),
                         make_pair(grass[i].second, time)));
  }
  ll max_grass = grass[N - 1].first;
  ll now_time = 0;

  while (!infos.empty()) {
    if (infos.top().second.second < now_time) {
      infos.pop();
      continue;
    }
    answer += infos.top().second.first * (infos.top().second.second - now_time);
    if (infos.top().first.second == -max_grass) {
      break;
    }
    now_time = infos.top().second.second;
    infos.pop();
  }
  cout << answer;
}
