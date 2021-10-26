#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

#define endl '\n'
#define ll long long

int N, M;
vector<int> T;

void input();
void solve();
bool bs(int k);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N >> M;
  int temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    T.push_back(temp);
  }
}

void solve() {
  int start = 1;
  int end = 0;
  for (int i = 0; i < N; i++) {
    end += T[i];
  }
  while (start < end) {
    int mid = (start + end) / 2;
    if (bs(mid)) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }
  cout << start << endl;
}

bool bs(int k) {
  int m = 0;
  int now = 0;
  for (int i = 0; i < N; i++) {
    if (k < T[i]) {
      return false;
    }
    if (now - T[i] < 0) {
      now = k - T[i];
      m++;
    } else {
      now -= T[i];
    }
  }
  return m <= M;
}
