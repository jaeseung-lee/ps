#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'

int N;
vector<int> numbers(26, 0);
int pow[9];
void input();
void solve();
int to_index(char target) { return int(target - 'A'); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();

  return 0;
}

void input() {
  int value = 1;
  for (int i = 0; i < 9; i++) {
    pow[i] = value;
    value = value * 10;
  }

  cin >> N;
  string temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    int len = temp.length();
    for (int j = 0; j < len; j++) {
      numbers[to_index(temp[j])] += pow[len - j - 1];
    }
  }

  sort(numbers.begin(), numbers.end(), [](int a, int b) { return a > b; });
  int answer = 0;
  int _value = 9;
  for (int element : numbers) {
    // cout << "element : " << element << endl;
    if (element == 0) {
      break;
    }
    answer += element * _value;
    _value--;
  }
  cout << answer << endl;
}
