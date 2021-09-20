#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;
vector<vector<int>> testcases;
bool visited[13];
int numbers[6];

void input();
void solve();
void print(int now_index, int max_index, int testcase_index);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  int temp = -1;
  while (true) {
    cin >> temp;
    if (temp == 0) {
      break;
    }
    vector<int> A;
    for (int i = 0; i < temp; i++) {
      int x;
      cin >> x;
      A.push_back(x);
    }
    testcases.push_back(A);
  }
}

void solve() {
  for (int t = 0; t < testcases.size(); t++) {
    for (int i = 0; i < testcases[t].size(); i++) {
      visited[i] = false;
    }
    print(0, testcases[t].size(), t);
    cout << endl;
  }
}

void print(int now_index, int max_index, int testcase_index) {
  if (now_index == 6) {
    for (int i = 0; i < 6; i++) {
      cout << testcases[testcase_index][numbers[i]] << " ";
    }
    cout << endl;
    return;
  }
  int start = 0;
  if (now_index != 0) {
    start = numbers[now_index - 1] + 1;
  }
  for (int i = start; i < max_index; i++) {
    if (!visited[i]) {
      numbers[now_index] = i;
      visited[i] = true;
      print(now_index + 1, max_index, testcase_index);
      visited[i] = false;
    }
  }
}
