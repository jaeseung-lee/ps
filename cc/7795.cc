#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int T, N, M;

void input();
void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  for (int i = 0; i < T; i++) {
    solve();
  }

  return 0;
}

void input() { cin >> T; }

void solve() {
  cin >> N >> M;
  vector<int> A;
  vector<int> B;
  int temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    A.push_back(temp);
  }
  for (int i = 0; i < M; i++) {
    cin >> temp;
    B.push_back(temp);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int answer = 0;

  for (int i = 0; i < N; i++) {
    auto iter = lower_bound(B.begin(), B.end(), A[i]);
    answer += distance(B.begin(), iter);
    // cout << "now : " << answer << endl;
    if (iter == B.end()) {
      answer += (N - 1 - i) * B.size();
      break;
    }
  }
  cout << answer << endl;
}
