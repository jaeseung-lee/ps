#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int N;
bool Board[101][101];
vector<pair<int, int>> temp;

void input();
void solve();
pair<int, int> make_next_pair(int x, int y, int d);
int ans = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() { cin >> N; }

void solve() {
  for (int i = 0; i < N; i++) {
    int x, y, d, g;
    cin >> x >> y >> d >> g;
    temp.clear();
    temp.push_back(make_pair(x, y));
    temp.push_back(make_next_pair(x, y, d));

    for (int j = 0; j < g; j++) {
      int init_x = temp[temp.size() - 1].first;
      int init_y = temp[temp.size() - 1].second;
      int len = temp.size() - 1;
      // cout << "init : " << init_x << " " << init_y << endl;
      for (int t = len - 1; t >= 0; t--) {
        int now_x = temp[t].first;
        int now_y = temp[t].second;
        int next_x = init_x + (init_y - now_y);
        int next_y = init_y - (init_x - now_x);
        temp.push_back(make_pair(next_x, next_y));
        // cout << "next : " << next_x << " " << next_y << endl;
      }
    }
    for (int j = 0; j < temp.size(); j++) {
      int now_x = temp[j].first;
      int now_y = temp[j].second;
      Board[now_x][now_y] = true;
      // cout << now_x << " " << now_y << endl;
    }
    // cout << endl;
  }
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      if (Board[i - 1][j - 1] && Board[i - 1][j] && Board[i][j - 1] &&
          Board[i][j]) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}

pair<int, int> make_next_pair(int x, int y, int d) {
  if (d == 0) {
    return make_pair(x + 1, y);
  } else if (d == 1) {
    return make_pair(x, y - 1);
  } else if (d == 2) {
    return make_pair(x - 1, y);
  } else {
    return make_pair(x, y + 1);
  }
}