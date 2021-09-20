#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define INF 2000000001

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
  int temp;
  for (int i = 1; i <= N; i++) {
    cin >> temp;
    A.push_back(temp);
  }
}

void solve() {
  sort(A.begin(), A.end());
  int start = 0;
  int end = N - 1;
  int ans = INF;
  int min_index;
  int max_index;

  do {
    int value = abs(A[start] + A[end]);
    if (ans > value) {
      ans = value;
      min_index = start;
      max_index = end;
    }
    if (abs(A[start + 1] + A[end]) < abs(A[start] + A[end - 1])) {
      start++;
    } else {
      end--;
    }
  } while (start != end);
  cout << A[min_index] << " " << A[max_index];
}
