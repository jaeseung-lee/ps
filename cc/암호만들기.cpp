/*
이 문제는 벡트래킹을 사용해야한다. 왜냐면 경우의 수를 구하는 문제니까.
그래서 "promising" 한지 아닌지를 생각했다면 조금 더 빨리 풀 수 있지 않았을까?
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

vector<char> target;
int max_length;

void input();
bool is_aeiou(const char *alphabet);
void solve();
void print_target(vector<char> answer, int flag);
bool is_answer(vector<char> target_answer);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  int alphabet_number;
  cin >> max_length >> alphabet_number;
  for (int i = 0; i < alphabet_number; i++) {
    char alphabet;
    cin >> alphabet;
    target.push_back(alphabet);
  }
  sort(target.begin(), target.end());
}

bool is_aeiou(char alphabet) {
  return alphabet == 'a' || alphabet == 'e' || alphabet == 'i' ||
         alphabet == 'o' || alphabet == 'u';
}

void solve() {
  vector<char> a;
  for (int i = 0; i < target.size(); i++) {
    print_target(a, i);
  }
}

void print_target(vector<char> answer, int flag) {
  answer.push_back(target[flag]);
  if (answer.size() == max_length) {
    if (is_answer(answer)) {
      for (int i = 0; i < max_length; i++) {
        cout << answer[i];
      }
      cout << endl;
    }
  } else {
    for (int i = flag + 1; i < target.size(); i++) {
      print_target(answer, i);
    }
  }
}

bool is_answer(vector<char> target_answer) {
  int aeiou_count = 1;
  int other_count = 2;
  for (int i = 0; i < target_answer.size(); i++) {
    if (is_aeiou(target_answer[i])) {
      aeiou_count--;
    } else {
      other_count--;
    }
    if (aeiou_count <= 0 && other_count <= 0) {
      return true;
    }
  }
  return false;
}
