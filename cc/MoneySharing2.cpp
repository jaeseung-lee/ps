#include <iostream>
#include <queue>
#include <vector>

#define ll long long
#define endl '\n'

using namespace std;

int n, m;
vector<ll> money_list;

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
  cin >> n >> m;
  for (int i = 0; i < n + m; i++) {
    ll value;
    cin >> value;
    money_list.push_back(value);
  }
}

void solve() {
  //처음에 +가 나올떄까지 확인
  int index = 0;
  while (true) {
    if (money_list[index] < 0) {
      cout << "declined" << endl;
      index++;
    } else {
      break;
    }
  }
  ll now_money = 0;

  bool is_approved[200001] = {
      false,
  };
  for (int i = 0; i < m; i++) {
    now_money += money_list[index];
    cout << "resupplied" << endl;
    priority_queue<pair<ll, int>> pq;
    int j = 1;
    while (true) {
      if (money_list[index + j] < 0) {
        pq.push(make_pair(money_list[index + j], index + j));
        j++;
      } else {
        break;
      }
    }

    while (!pq.empty()) {
      if (now_money + pq.top().first >= 0) {
        now_money += pq.top().first;
        is_approved[pq.top().second] = true;
        // cout << "now : " << now_money << endl;
        pq.pop();
      } else {
        break;
      }
    }

    for (int k = index + 1; k < index + j; k++) {
      if (is_approved[k]) {
        cout << "approved" << endl;
      } else {
        cout << "declined" << endl;
      }
    }
    index = index + j;
  }
}
