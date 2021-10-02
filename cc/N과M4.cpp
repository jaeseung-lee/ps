#include <iostream>

#define endl '\n'

using namespace std;

int N, M;
int A[9];

void input();
void solve();
void print(int print_index, int last_number);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() { cin >> N >> M; }

void solve() { print(1, 1); }

void print(int print_index, int last_number) {
  // cout << "print_index, last_number : " << print_index << " " << last_number
  // << endl;
  if (print_index == M + 1) {
    for (int i = 1; i <= M; i++) {
      cout << A[i] << " ";
    }
    cout << endl;
    return;
  }

  for (int i = last_number; i <= N; i++) {
    A[print_index] = i;
    print(print_index + 1, i);
  }
  return;
}
