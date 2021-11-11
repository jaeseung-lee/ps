#include <iostream>

using namespace std;

#define endl '\n'

int N, K;
pair<int, bool> A[201];
int start_index = 1;
int end_index;
int answer = 1;

void input();
void solve();

int next_index(int target) {
  if (target == 1) {
    return 2 * N;
  } else {
    return target - 1;
  }
}

int prev_index(int target) {
  if (target == 2 * N) {
    return 1;
  } else {
    return target + 1;
  }
}

void rotate() {
  start_index = next_index(start_index);
  end_index = next_index(end_index);
  A[end_index].second = false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N >> K;
  for (int i = 1; i <= 2 * N; i++) {
    int temp;
    cin >> temp;
    A[i] = make_pair(temp, false);
  }
  start_index = 1;
  end_index = N;
}

void solve() {
  while (true) {
    rotate();
    int i = next_index(end_index);
    while (i != next_index(start_index)) {
      if (A[i].second && !A[prev_index(i)].second &&
          A[prev_index(i)].first != 0) {
        A[i].second = false;
        A[prev_index(i)].first--;
        if (prev_index(i) == end_index) {
          A[prev_index(i)].second = false;
        } else {
          A[prev_index(i)].second = true;
        }
        if (A[prev_index(i)].first == 0) {
          K--;
        }
      }
      i = next_index(i);
    }
    A[end_index].second = false;
    if (A[start_index].first != 0) {
      A[start_index].second = true;
      A[start_index].first--;
      if (A[start_index].first == 0) {
        K--;
      }
    }
    if (K <= 0) {
      break;
    }
    answer++;
  }
  cout << answer;
}