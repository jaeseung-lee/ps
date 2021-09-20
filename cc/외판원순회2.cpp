#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int N;
int W[10][10];

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
    for (int j = 0; j < N; j++) {
      cin >> W[i][j];
    }
  }
}

void solve() {
  int answer = 10000001;
  vector<int> indice;
  for (int i = 0; i < N; i++) {
    indice.push_back(i);
  }

  do {
    int value = W[indice[N - 1]][indice[0]];
    if (value == 0) {
      continue;
    }
    bool is_route = true;
    for (int i = 0; i < N - 1; i++) {
      value += W[indice[i]][indice[i + 1]];
      if (W[indice[i]][indice[i + 1]] == 0) {
        is_route = false;
        break;
      }
    }
    if (is_route && answer > value) {
      answer = value;
    }
  } while (next_permutation(indice.begin(), indice.end()));
  cout << answer;
}
