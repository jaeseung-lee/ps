#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int n;
int A[100000 + 1];
int a[100000 + 1];
int b[100000 + 1];
int answer;

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
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
}

void solve() {
  if (n == 1) {
    cout << A[1];
    return;
  }
  // boundary
  a[1] = A[1];
  b[n] = A[n];

  // cout << a[1] << " ";

  // fill a[]
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] < 0) {
      a[i] = A[i];
    } else {
      a[i] = A[i] + a[i - 1];
    }
    // cout << a[i] << " ";
  }

  // fill b[]
  for (int i = n - 1; i >= 1; i--) {
    if (b[i + 1] < 0) {
      b[i] = A[i];
    } else {
      b[i] = A[i] + b[i + 1];
    }
  }

  // cout << endl;
  /*
  for(int i=1;i<=n;i++){
    cout << b[i] << " ";
  }
  */

  // cout << endl;
  answer = a[1];
  for (int i = 1; i <= n; i++) {
    if (answer < a[i]) {
      answer = a[i];
    }
  }

  // cout << "init answer :" << answer << endl;
  // cout << b[2] << " ";
  if (answer < b[2]) {
    answer = b[2];
  }

  for (int i = 1; i <= n - 2; i++) {
    int temp = a[i] + b[i + 2];
    // cout << temp << " ";
    if (answer < a[i] + b[i + 2]) {
      answer = a[i] + b[i + 2];
    }
  }

  if (answer < a[n - 1]) {
    answer = a[n - 1];
  }

  cout << answer;
}
