#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define ll long long

ll N, M;
vector<ll> T;

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
  cin >> N >> M;
  ll temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    T.push_back(temp);
  }
}

void solve() {}
