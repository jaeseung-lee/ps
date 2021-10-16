#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int N, L;
int A[5000000 + 1];

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
  cin >> N >> L;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
}

void solve() {
  priority_queue<pair<int, int>> pq;
  for (int i = 1; i <= N; i++) {
    int target_start = i - L + 1;
    if (target_start <= 0) {
      target_start = 1;
    }
    pq.push(make_pair(-A[i], i));
    while (true) {
      if (pq.top().second < target_start) {
        pq.pop();
      } else {
        cout << -pq.top().first << " ";
        break;
      }
    }
  }
}
