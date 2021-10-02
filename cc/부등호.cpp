#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int k;
vector<char> A;
bool is_min_found = false;

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
  cin >> k;
  for (int i = 0; i < k; i++) {
    char c;
    cin >> c;
    A.push_back(c);
  }
}

void solve() {
  vector<int> min_list;
  vector<int> max_list;
  for (int i = 0; i <= k; i++) {
    min_list.push_back(i);
    max_list.push_back(9 - i);
  }

  do {
    int i;
    for (i = 0; i < k; i++) {
      if (A[i] == '<') {
        if (max_list[i] < max_list[i + 1]) {
          continue;
        } else {
          break;
        }
      } else {
        if (max_list[i] > max_list[i + 1]) {
          continue;
        } else {
          break;
        }
      }
    }
    if (i == k) {
      //출력
      for (int i = 0; i <= k; i++) {
        cout << max_list[i];
      }
      cout << endl;
      break;
    }
  } while (prev_permutation(max_list.begin(), max_list.end()));

  do {
    int i;
    for (i = 0; i < k; i++) {
      if (A[i] == '<') {
        if (min_list[i] < min_list[i + 1]) {
          continue;
        } else {
          break;
        }
      } else {
        if (min_list[i] > min_list[i + 1]) {
          continue;
        } else {
          break;
        }
      }
    }
    if (i == k) {
      //출력
      for (int i = 0; i <= k; i++) {
        cout << min_list[i];
      }
      cout << endl;
      break;
    }
  } while (next_permutation(min_list.begin(), min_list.end()));
}
