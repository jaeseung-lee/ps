#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'

int N;
vector<string> words;

void input();
void solve();
bool isSubstr(string a, string b) { return b.substr(0, a.size()) == a; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    string temp;
    cin >> temp;
    words.push_back(temp);
  }
  sort(words.begin(), words.end(),
       [](string a, string b) { return a.length() < b.length(); });
}

void solve() {
  int ans = N;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (isSubstr(words[i], words[j])) {
        ans--;
        break;
      }
    }
  }
  cout << ans << endl;
}
