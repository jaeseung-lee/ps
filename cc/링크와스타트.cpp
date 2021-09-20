#include <cmath>
#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int N;
int stats[20][20];
int answer = 400000;
int visited[20];

void input();
void solve();
void search(int now_index, int selected);

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
    for (int j = 0; j < N; j++) {
      cin >> stats[i][j];
    }
  }
}

void solve() {
  for (int i = 0; i < N; i++) {
    visited[i] = false;
  }
  search(0, 0);
  cout << answer;
}

void search(int now_index, int selected) {
  if (now_index == N) {
    //계산해서 비교
    int team0 = 0;
    int team1 = 0;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (visited[i] == visited[j]) {
          if (visited[i] == 0) {
            team0 += stats[i][j];
          } else {
            team1 += stats[i][j];
          }
        }
      }
    }

    if (abs(team0 - team1) < answer) {
      answer = abs(team0 - team1);
    }

    return;
  }

  if (selected != N - 1) {
    visited[now_index] = 1;
    search(now_index + 1, selected + 1);
  }
  visited[now_index] = 0;
  search(now_index + 1, selected);
}
