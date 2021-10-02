#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

vector<int> A;
vector<bool> visited;

void input();
void solve();
void search(int index, int left, int sum);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  for (int i = 0; i < 9; i++) {
    int temp;
    cin >> temp;
    A.push_back(temp);
    visited.push_back(false);
  }
}

void solve() {
  sort(A.begin(), A.end());
  search(0, 7, 0);
}

void search(int index, int left, int sum) {
  if (left == 0) {
    if (sum == 100) {
      for (int i = 0; i < 9; i++) {
        if (visited[i]) {
          cout << A[i] << endl;
        }
      }
      exit(0);
    } else {
      return;
    }
  }

  if (index == 9 || sum > 100) {
    return;
  }

  visited[index] = false;
  search(index + 1, left, sum);
  visited[index] = true;
  search(index + 1, left - 1, sum + A[index]);
  visited[index] = false;
  return;
}
