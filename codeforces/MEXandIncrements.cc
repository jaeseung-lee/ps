#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int t, n;

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
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      numbers.push_back(temp);
    }
    sort(numbers.begin(), numbers.end());
    bool have_to_check = true;
    for (int i = 0; i <= n; i++) {
      int ans;
      if (have_to_check) {
        if (numbers[i] < i) {
          ans = -1;
          have_to_check = false;
        } else {
          auto uiter = upper_bound(numbers.begin(), numbers.end(), i);
        }
      } else {
        ans = -1;
      }
      cout << ans << " ";
    }
    cout << endl;
  }
}
