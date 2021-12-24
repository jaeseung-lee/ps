#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int t;
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
    string word;
    cin >> word;
    if (word.size() % 2 == 1) {
      cout << "NO" << endl;
      continue;
    }
    bool is_anwer = true;
    for (int i = 0; i < word.size() / 2; i++) {
      if (word[i] != word[word.size() / 2 + i]) {
        is_anwer = false;
        break;
      }
    }
    if (is_anwer) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
