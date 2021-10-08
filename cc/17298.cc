#include <iostream>
#include <stack>

using namespace std;

int N;
int A[1000000 + 1];
stack<int> ans;
stack<int> temp;

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
    cin >> A[i];
  }
}

void solve() {
  ans.push(-1);
  temp.push(A[N]);
  for (int i = N - 1; i >= 1; i--) {
    while (true) {
      if (temp.empty() || temp.top() > A[i]) {
        if (temp.empty()) {
          ans.push(-1);
        } else {
          ans.push(temp.top());
        }
        temp.push(A[i]);
        break;
      } else {
        temp.pop();
      }
    }
  }
  while (!ans.empty()) {
    cout << ans.top() << " ";
    ans.pop();
  }
}