#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int N;
vector<int> A;

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

  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    A.push_back(temp);
  }
}

void solve() {
  int answer = 0;
  sort(A.begin(), A.end());
  do {
    int value = 0;
    for (int i = 0; i < N - 1; i++) {
      value += abs(A[i] - A[i + 1]);
    }
    if (value > answer) {
      answer = value;
    }
  } while (next_permutation(A.begin(), A.end()));
  cout << answer << endl;
}
