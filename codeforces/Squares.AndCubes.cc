#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define MAX 1000000001

int n, t;

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

void input() { cin >> t; }

void solve() {

  while (t > 0) {
    t--;
    cin >> n;
    vector<int> numbers;
    for (int i = 1; i * i <= n; i++) {
      numbers.push_back(i * i);
    }
    for (int i = 1; i * i * i <= n; i++) {
      int st = int(sqrt(i));
      if (st * st != i) {
        numbers.push_back(i * i * i);
      }
    }
    cout << numbers.size() << endl;
  }
}
