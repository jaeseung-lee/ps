#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define ll long long

int T;
vector<pair<pair<int, int>, pair<int, int>>> testcases;

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
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N, M, x, y;
    cin >> M >> N >> x >> y;
    testcases.push_back(make_pair(make_pair(M, N), make_pair(x, y)));
  }
}

void solve() {
  for (int t_index = 0; t_index < T; t_index++) {
    int M = testcases[t_index].first.first;
    int N = testcases[t_index].first.second;
    int x = testcases[t_index].second.first;
    int y = testcases[t_index].second.second;
    int answer = y;
    x = x % M;
    y = y % N;
    // cout << "x , y : " << x << " " << y << endl;
    int i;
    for (i = 0; i < M; i++) {
      if (answer % M == x) {
        break;
      }
      answer += N;
    }

    if (i == M) {
      cout << "-1" << endl;
    } else {
      cout << answer << endl;
    }
  }
}
