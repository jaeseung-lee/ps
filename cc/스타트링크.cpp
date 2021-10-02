#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int F, S, G, U, D;
int floor[1000000 + 1];

void input();
void solve();
bool is_valid_floor(int target);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() { cin >> F >> S >> G >> U >> D; }

void solve() {
  for (int i = 1; i <= F; i++) {
    floor[i] = -1;
  }
  floor[S] = 0;
  queue<int> q;
  q.push(S);

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    if (now == G) {
      cout << floor[G] << endl;
      return;
    }

    if (is_valid_floor(now + U) && floor[now + U] == -1) {
      floor[now + U] = floor[now] + 1;
      q.push(now + U);
    }

    if (is_valid_floor(now - D) && floor[now - D] == -1) {
      floor[now - D] = floor[now] + 1;
      q.push(now - D);
    }
  }
  cout << "use the stairs" << endl;
}

bool is_valid_floor(int target) { return target >= 1 && target <= F; }
