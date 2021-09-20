#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int N, K;
int Spot[100000 + 1];
int ans[100000 + 1];

void input();
void solve();
bool is_valid_index(int x);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() { cin >> N >> K; }

void solve() {
  queue<int> q;
  memset(Spot, -1, sizeof(Spot));
  q.push(N);
  Spot[N] = 0;
  ans[N] = 1;

  while (!q.empty()) {
    int now = q.front();
    int value = Spot[now];
    q.pop();

    if (is_valid_index(now - 1)) {
      if (Spot[now - 1] == -1) {
        Spot[now - 1] = value + 1;
        q.push(now - 1);
        ans[now - 1]++;
      } else if (Spot[now - 1] == value + 1) {
        ans[now - 1]++;
        q.push(now - 1);
      }
    }

    if (is_valid_index(now + 1)) {
      if (Spot[now + 1] == -1) {
        Spot[now + 1] = value + 1;
        q.push(now + 1);
        ans[now + 1]++;
      } else if (Spot[now + 1] == value + 1) {
        ans[now + 1]++;
        q.push(now + 1);
      }
    }

    if (is_valid_index(2 * now)) {
      if (Spot[2 * now] == -1) {
        Spot[2 * now] = value + 1;
        q.push(now * 2);
        ans[2 * now]++;
      } else if (Spot[2 * now] == value + 1) {
        ans[now * 2]++;
        q.push(now * 2);
      }
    }
  }
  cout << Spot[K] << endl << ans[K] << endl;
}

bool is_valid_index(int x) { return x >= 0 && x <= 100000; }
