#include <algorithm>
#include <iostream>
#include <set>
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
  for (int _ = 0; _ < t; _++) {
    string S, T;
    cin >> S >> T;

    vector<int> alphabets;

    int value = int('a');
    for (int i = 0; i < 26; i++) {
      alphabets.push_back(0);
    }

    for (char element : S) {
      alphabets[int(element) - value]++;
    }

    if (alphabets[0] == 0 || alphabets[1] == 0 || alphabets[2] == 0 ||
        T != "abc") {
      for (int i = 0; i < alphabets.size(); i++) {
        for (int j = 0; j < alphabets[i]; j++) {
          cout << char(value + i);
        }
      }
    } else {
      for (int i = 0; i < alphabets[0]; i++) {
        cout << 'a';
      }
      for (int i = 0; i < alphabets[2]; i++) {
        cout << 'c';
      }
      for (int i = 0; i < alphabets[1]; i++) {
        cout << 'b';
      }
      for (int i = 3; i < alphabets.size(); i++) {
        for (int j = 0; j < alphabets[i]; j++) {
          cout << char(value + i);
        }
      }
    }
    cout << endl;
  }
}
