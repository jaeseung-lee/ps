#include <iostream>

using namespace std;

#define endl '\n'
#define ll long long

ll N, M;
ll A[300000];

void input();
void solve();
bool bs(ll k);

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
  for (int i = 0; i < M; i++) {
    cin >> A[i];
  }
}

void solve() {
  ll start = 1;
  ll end = 0;
  for (int i = 0; i < M; i++) {
    end += A[i];
  }
  while (start < end) {
    // cout << "now : " << start << " " << end << endl;
    ll mid = (start + end) / 2;
    if (bs(mid)) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }
  cout << start;
}

bool bs(ll k) {
  ll result = 0;
  for (int i = 0; i < M; i++) {
    result += A[i] / k;
    if (A[i] % k != 0) {
      result++;
    }
  }
  return result <= N;
}
