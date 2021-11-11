#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

#define endl '\n'

using namespace std;

int N;
vector<int> A;
vector<pair<int, int>> numbers;

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
  cin >> N;
  int temp;
  for (int i = 0; i <= 4000; i++) {
    numbers.push_back(make_pair(0, i));
  }
  for (int i = 1; i <= 4000; i++) {
    numbers.push_back(make_pair(0, -i));
  }

  for (int i = 0; i < N; i++) {
    cin >> temp;
    A.push_back(temp);
    if (temp < 0) {
      numbers[4000 - temp].first++;
    } else {
      numbers[temp].first++;
    }
  }
}

void solve() {
  sort(A.begin(), A.end());
  int sum = accumulate(A.begin(), A.end(), 0);
  cout << round((double)(sum) / (double)(N)) << endl;
  cout << A[N / 2] << endl;
  sort(numbers.begin(), numbers.end(), [](pair<int, int> a, pair<int, int> b) {
    return a.first > b.first || (a.first == b.first && a.second < b.second);
  });
  if (numbers[0].first == numbers[1].first) {
    cout << numbers[1].second << endl;
  } else {
    cout << numbers[0].second << endl;
  }
  cout << A[A.size() - 1] - A[0] << endl;
}