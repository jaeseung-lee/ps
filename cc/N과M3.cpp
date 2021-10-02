#include <iostream>

#define endl '\n'

using namespace std;

int N, M;
int A[9];

void input();
void solve();
void print(int print_num);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();
  return 0;
}

void input() { cin >> N >> M; }

void solve() { print(1); }

void print(int print_num) {
  if (print_num == M + 1) {
    for (int i = 1; i <= M; i++) {
      cout << A[i] << " ";
    }
    cout << endl;
    return;
  }

  for (int i = 1; i <= N; i++) {
    A[print_num] = i;
    print(print_num + 1);
  }
}
