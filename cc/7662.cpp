#include <cstring>
#include <iostream>
#include <queue>

#define endl '\n'
#define ll long long

using namespace std;

void solve();
bool is_contained[1000000 + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}

void solve() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    memset(is_contained, false, sizeof(is_contained));
    priority_queue<pair<ll, int>> max_q;
    priority_queue<pair<ll, int>> min_q;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      char op;
      ll number;
      cin >> op >> number;
      // cout << "op,number" << op << " " << number<<endl;
      if (op == 'I') {
        is_contained[cnt] = true;
        max_q.push(make_pair(number, cnt));
        min_q.push(make_pair(-number, cnt));
        cnt++;
      } else if (number == 1) {
        while (true) {
          if (max_q.empty()) {
            break;
          }
          int index = max_q.top().second;
          if (!is_contained[index]) {
            max_q.pop();
          } else {
            is_contained[index] = false;
            max_q.pop();
            break;
          }
        }
      } else {
        while (true) {
          if (min_q.empty()) {
            break;
          }
          int index_ = min_q.top().second;
          if (!is_contained[index_]) {
            min_q.pop();
          } else {
            is_contained[index_] = false;
            min_q.pop();
            break;
          }
        }
      }
    }

    ll ans_M, ans_m;
    while (true) {
      if (max_q.empty()) {
        break;
      }
      int index = max_q.top().second;
      if (!is_contained[index]) {
        max_q.pop();
      } else {
        ans_M = max_q.top().first;
        break;
      }
    }

    if (max_q.empty()) {
      cout << "EMPTY" << endl;
      continue;
    }

    while (true) {
      if (min_q.empty()) {
        break;
      }
      int index_ = min_q.top().second;
      if (!is_contained[index_]) {
        min_q.pop();
      } else {
        ans_m = -min_q.top().first;
        break;
      }
    }

    if (min_q.empty()) {
      cout << "EMPTY" << endl;
      continue;
    }
    cout << ans_M << " " << ans_m << endl;
  }
}
