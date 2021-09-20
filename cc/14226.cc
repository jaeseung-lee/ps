#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int S;
int num[1001][1001];
void input();
void solve();
int ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() { cin >> S; }

void solve() {
  queue<pair<int, int>> q;
  q.push(make_pair(1, 0));
  while (true) {
    int now = q.front().first;
    int save = q.front().second;
    int value = num[now][save];
    // cout << "now, save, value : " << now << " " << save << " " << value <<
    // endl;
    q.pop();
    if (now == S) {
      ans = value;
      break;
    }
    if (num[now][now] == 0) {
      q.push(make_pair(now, now));
      num[now][now] = value + 1;
    }
    if (now + save <= 1000 && save != 0) {
      q.push(make_pair(now + save, save));
      num[now + save][save] = value + 1;
    }
    if (now - 1 >= 0 && num[now - 1][save] == 0) {
      q.push(make_pair(now - 1, save));
      num[now - 1][save] = value + 1;
    }
  }

  cout << ans;
}
