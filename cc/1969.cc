#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int N, M;
int words[4][1000];
int ans = 0;

void input();
void solve();
void printMax(int index);

int main() {
  // ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N >> M;
  getchar();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      char letter = getchar();
      switch (letter) {
        case 'A':
          words[0][j]++;
          break;

        case 'C':
          words[1][j]++;
          break;

        case 'G':
          words[2][j]++;
          break;

        case 'T':
          words[3][j]++;
          break;

        default:
          break;
      }
    }
    getchar();
  }
}

void solve() {
  for (int i = 0; i < M; i++) {
    printMax(i);
  }
  cout << endl << ans << endl;
}

void printMax(int index) {
  int maxIndex = 0;
  for (int i = 1; i <= 3; i++) {
    if (words[i][index] > words[maxIndex][index]) {
      maxIndex = i;
    }
  }
  ans += N - words[maxIndex][index];
  switch (maxIndex) {
    case 0:
      cout << 'A';
      break;

    case 1:
      cout << 'C';
      break;

    case 2:
      cout << 'G';
      break;

    case 3:
      cout << 'T';
      break;

    default:
      break;
  }
}
