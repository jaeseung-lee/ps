#include <algorithm>
#include <iostream>

using namespace std;

int N;
int prev_max[3] = {
    0,
};
int prev_min[3] = {
    0,
};
int next_max[3];
int next_min[3];

void input();
void solve();

#define endl '\n'

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
    /*
    cout << "i :" << i << endl;
    for (auto element : prev_max) {
      cout << element << " ";
    }
    cout << endl;
    for (auto element : prev_min) {
      cout << element << " ";
    }
    cout << endl;
    */

    int a, b, c;
    cin >> a >> b >> c;

    next_max[0] = max(prev_max[0], prev_max[1]) + a;
    next_min[0] = min(prev_min[0], prev_min[1]) + a;

    next_max[1] = max({prev_max[0], prev_max[1], prev_max[2]}) + b;
    next_min[1] = min({prev_min[0], prev_min[1], prev_min[2]}) + b;

    next_max[2] = max(prev_max[1], prev_max[2]) + c;
    next_min[2] = min(prev_min[1], prev_min[2]) + c;

    for (int j = 0; j < 3; j++) {
      prev_max[j] = next_max[j];
      prev_min[j] = next_min[j];
    }
  }
  cout << max({next_max[0], next_max[1], next_max[2]}) << " "
       << min({next_min[0], next_min[1], next_min[2]});
}
