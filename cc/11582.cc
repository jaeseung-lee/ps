#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

#define endl '\n'

int N, K;
vector<int> A;

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
  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    A.push_back(temp);
  }
  cin >> K;
}

void solve() {
  int chunks = N / K;
  auto fst_iter = A.begin();
  auto lst_iter = A.begin() + chunks;
  for (int i = 0; i < K; i++) {
    sort(fst_iter, lst_iter);
    fst_iter += chunks;
    lst_iter += chunks;
  }
  for (auto element : A) {
    cout << element << " ";
  }
}
