#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define endl '\n'

int N, M;
bool used[9];
int A[9];

void input();
void solve();
void print(int print_index);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() { cin >> N >> M; }

void solve() {
  for (int i = 1; i <= N; i++) {
    used[i] = false;
    A[i] = 0;
  }
  print(1);
}

void print(int print_index) {
  if (print_index == M + 1) {
    for (int i = 1; i <= M; i++) {
      cout << A[i] << " ";
    }
    cout << endl;
    return;
  }

  for (int i = 1; i <= N; i++) {
    if (used[i]) {
      continue;
    }
    A[print_index] = i;
    used[i] = true;
    print(print_index + 1);
    used[i] = false;
  }
}
