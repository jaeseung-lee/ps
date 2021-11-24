#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'

string word;
string bomb;

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

void input() { cin >> word >> bomb; }

void solve() {
  stack<pair<char, int>> stk;
  for (int i = 0; i < word.length(); i++) {
    char letter = word[i];
    if (stk.empty()) {
      if (letter == bomb[0]) {
        stk.push(make_pair(letter, 0));
      } else {
        stk.push(make_pair(letter, -1));
      }
      if (bomb.size() == 1 && letter == bomb[0]) {
        stk.pop();
      }
    } else {
      if (bomb[0] == letter) {
        stk.push(make_pair(letter, 0));
        //    cout << letter << " " << 0 << endl;
      } else if (bomb[stk.top().second + 1] == letter) {
        stk.push(make_pair(letter, stk.top().second + 1));
        //    cout << letter << " " << stk.top().second + 1 << endl;
      } else {
        stk.push(make_pair(letter, -1));
        //   cout << letter << " " << -1 << endl;
      }
      if (stk.top() == make_pair(letter, (int)bomb.length() - 1)) {
        for (int j = 0; j < bomb.length(); j++) {
          stk.pop();
        }
      }
    }
  }
  if (stk.empty()) {
    cout << "FRULA" << endl;
    return;
  }

  vector<char> ans;
  while (!stk.empty()) {
    ans.push_back(stk.top().first);
    stk.pop();
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[ans.size() - 1 - i];
  }
}