#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

string word;
string target;
int ans = 0;

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
  getline(cin, word);
  getline(cin, target);
  if (word.length() < target.length()) {
    cout << "0" << endl;
    exit(0);
  }
}

void solve() {
  for (int start_index = 0; start_index <= word.length() - target.length();
       start_index++) {
    int now = 0;
    for (int j = start_index; j <= word.length() - target.length(); j++) {
      if (word.substr(j, target.length()) == target) {
        now++;
        j = j + target.length() - 1;
      }
    }
    if (now > ans) {
      ans = now;
    }
  }
  cout << ans << endl;
}
