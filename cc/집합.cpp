#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'

int T;

void input();
void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}

void solve() {
  cin >> T;
  int number = 0b00000000000000000000;
  int all_number = 0b11111111111111111111;
  int empty_number = 0b00000000000000000000;

  for (int i = 0; i < T; i++) {
    string operation_name;
    cin >> operation_name;
    if (operation_name == "add") {
      int x;
      cin >> x;
      x--;
      number = number | (1 << x);
    } else if (operation_name == "remove") {
      int x;
      cin >> x;
      x--;
      number = number & (~(1 << x));
    } else if (operation_name == "check") {
      int x;
      cin >> x;
      x--;
      // cout << "check : "<<(number & (1<<x)) << endl;
      if ((number & (1 << x))) {
        cout << "1" << endl;
      } else {
        cout << "0" << endl;
      }
    } else if (operation_name == "toggle") {
      int x;
      cin >> x;
      x--;
      number = number ^ (1 << x);
    } else if (operation_name == "all") {
      number = all_number;
    } else if (operation_name == "empty") {
      number = empty_number;
    } else {
      cout << "error!" << endl;
    }
  }
}
