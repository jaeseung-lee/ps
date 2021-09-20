#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

#define endl '\n'
#define mod 10000

int T;
vector<pair<int, int>> testcases;
int operations[4][10000];
bool visited[10000];

void input();
void solve();
int D(int target);
int S(int target);
int L(int target);
int R(int target);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> T;
  for (int i = 0; i < T; i++) {
    int a, b;
    cin >> a >> b;
    testcases.push_back(make_pair(a, b));
  }
}

void solve() {
  for (int t = 0; t < T; t++) {
    for (int i = 0; i < 10000; i++) {
      visited[i] = false;
    }
    int a = testcases[t].first;
    int b = testcases[t].second;

    queue<tuple<char, string, int>> q;
    q.push(make_tuple('D', "", a));
    q.push(make_tuple('S', "", a));
    q.push(make_tuple('L', "", a));
    q.push(make_tuple('R', "", a));
    visited[a] = true;

    while (!q.empty()) {
      char next_op = get<0>(q.front());
      string last_ops = get<1>(q.front());
      int target = get<2>(q.front());
      q.pop();
      // cout << "now : " << target << endl;

      if (target == b) {
        cout << last_ops << endl;
        break;
      }

      if (next_op == 'D') {
        target = D(target);
        // cout << "After D : " << target << endl;
      } else if (next_op == 'S') {
        target = S(target);
        // cout << "After S : " << target << endl;
      } else if (next_op == 'L') {
        target = L(target);
        // cout << "After L : " << target << endl;
      } else {
        target = R(target);
        // cout << "After R : " << target << endl;
      }
      if (visited[target] == true) {
        continue;
      } else {
        visited[target] = true;
      }
      last_ops.push_back(next_op);
      q.push(make_tuple('D', last_ops, target));
      q.push(make_tuple('S', last_ops, target));
      q.push(make_tuple('L', last_ops, target));
      q.push(make_tuple('R', last_ops, target));
    }
  }
}

int D(int target) {
  target = target * 2;
  if (target > mod) {
    target = target - mod;
  }
  return target;
}

int S(int target) {
  target--;
  if (target < 0) {
    target = 9999;
  }
  return target;
}

int L(int target) {
  int d1 = target / 1000;
  target = target - d1 * 1000;
  int d2 = target / 100;
  target = target - d2 * 100;
  int d3 = target / 10;
  target = target - d3 * 10;
  int d4 = target;
  return ((d2 * 10 + d3) * 10 + d4) * 10 + d1;
}

int R(int target) {
  int d1 = target / 1000;
  target = target - d1 * 1000;
  int d2 = target / 100;
  target = target - d2 * 100;
  int d3 = target / 10;
  target = target - d3 * 10;
  int d4 = target;
  return ((d4 * 10 + d1) * 10 + d2) * 10 + d3;
}
