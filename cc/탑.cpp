#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define endl '\n'

int T[500000 + 1];
int N;

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
  for (int i = 1; i <= N; i++) {
    cin >> T[i];
  }
}

void solve() {
  int A[500000 + 1];
  stack<pair<int, int>> stk; // (T[i],i)
  for (int i = 1; i <= N; i++) {
    while (true) {
      if (stk.empty()) {
        stk.push(make_pair(T[i], i));
        A[i] = 0;
        break;
      } else {
        if (stk.top().first > T[i]) {
          A[i] = stk.top().second;
          stk.push(make_pair(T[i], i));
          break;
        } else {
          stk.pop();
        }
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << A[i] << " ";
  }
}
