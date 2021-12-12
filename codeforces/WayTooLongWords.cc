#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

int N;
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

void input() { cin >> N; }

void solve() {
  for (int i = 0; i < N; i++) {
    string word;
    cin >> word;
    if (word.length() <= 10) {
      cout << word << endl;
    } else {
      cout << word[0] << word.length() - 2 << word[word.length() - 1] << endl;
    }
  }
}
