#include <iostream>
#include <queue>

using namespace std;

#define ll long long

int N;
priority_queue<ll> pq;

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
  ll temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    pq.push(-temp);
  }
}

void solve() {
  ll ans = 0;
  while (pq.size() > 1) {
    ll a = pq.top();
    pq.pop();
    ll b = pq.top();
    pq.pop();
    cout << a << " " << b << endl;
    pq.push(a + b);
    ans += a + b;
  }
  cout << -ans << endl;
}