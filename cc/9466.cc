#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int T;
int edges[100001];
// -1 이면 아직 방문하지 않은 점
// 0 이상의 정수라면 번째수
// second는 몇 번째 사이클인지
pair<int, int> is_visited[100001];
int n;

void input();
void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();

  return 0;
}

void input() {
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> n;
    for (int j = 1; j <= n; j++) {
      cin >> edges[j];
    }
    solve();
  }
}

void solve() {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    is_visited[i] = make_pair(-1, -1);
  }
  int cycle_number = 0;

  for (int i = 1; i <= n; i++) {
    if (is_visited[i].first == -1) {
      is_visited[i].first = 0;
      is_visited[i].second = cycle_number;
      int prev = i;
      int next = edges[i];
      while (is_visited[next].first == -1) {
        is_visited[next].first = is_visited[prev].first + 1;
        is_visited[next].second = cycle_number;
        prev = next;
        next = edges[next];
      }
      if (is_visited[next].second == is_visited[prev].second) {
        ans += is_visited[next].first;
      } else {
        ans += is_visited[prev].first + 1;
      }
      // cout << "prev : " << prev << " next : " << next << endl;
      cycle_number++;
    }
  }
  cout << ans << endl;
}
