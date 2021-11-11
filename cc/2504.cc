#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define endl '\n'

string word;
int length;
stack<char> op;  // 짝이 맞는지
stack<int> number;
int answer;

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
  cin >> word;
  length = word.size();
}

void solve() {
  for (int i = 0; i < length; i++) {
    cout << "index : " << i << " op.size() : " << op.size() << endl;
    if (!number.empty()) {
      cout << number.top() << endl;
    }
    char letter = word[i];
    if (letter == '(' || letter == '[') {
      op.push(letter);
    } else {
      if (number.empty()) {
        if (letter == ')' && op.top() == '(') {
          op.pop();
          number.push(2);
        } else if (letter = ']' && op.top() == '[') {
          op.pop();
          number.push(3);
        } else {
          cout << "0" << endl;
          exit(0);
        }
      } else {
        if (letter == ')' && op.top() == '(') {
          op.pop();
          if (op.empty()) {
            int temp = number.top() + 2;
            number.pop();
            number.push(temp);
          } else if (op.top() == '(' || op.top() == '[') {
            int temp = number.top() * 2;
            number.pop();
            number.push(temp);
          } else {
            int temp = number.top() + 2;
            number.pop();
            number.push(temp);
          }
        } else if (letter == ']' && op.top() == '[') {
          op.pop();
          if (op.empty()) {
            int temp = number.top() + 3;
            number.pop();
            number.push(temp);
          } else if (op.top() == '(' || op.top() == '[') {
            int temp = number.top() * 3;
            number.pop();
            number.push(temp);
          } else {
            int temp = number.top() + 3;
            number.pop();
            number.push(temp);
          }
        } else {
          cout << "0" << endl;
          exit(0);
        }
      }
    }
  }
  if (op.empty()) {
    cout << number.top() << endl;
  } else {
    cout << "0" << endl;
  }
}
