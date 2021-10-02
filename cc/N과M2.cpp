#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

int N, M;
int A[9];
bool visited[9];

void input();
void solve();
void search(int now_index, int how_many_true);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() { cin >> N >> M; }

void solve() {
  for (int i = 1; i <= N; i++) {
    A[i] = i;
  }
  search(1, 0);
}

void search(int now_index, int how_many_true) {
  if (how_many_true == M) {
    for (int i = 1; i <= N; i++) {
      if (visited[i]) {
        cout << A[i] << " ";
      }
    }
    cout << endl;
    return;
  }

  if (now_index == N + 1) {
    return;
  }

  visited[now_index] = true;
  search(now_index + 1, how_many_true + 1);
  visited[now_index] = false;
  search(now_index + 1, how_many_true);
}
