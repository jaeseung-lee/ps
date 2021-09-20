#include <algorithm>
#include <iostream>

#define INF 100000000
#define endl '\n'

using namespace std;

int TC;
int N[6];
int M[6];
int W[6];
int D[6][501][501];

void input();
void solve();

int main() {
  ios::sync_with_stdio(false);
  input();
  solve();

  return 0;
}

void input() {
  cin >> TC;
  for (int t = 0; t < TC; t++) {
    cin >> N[t] >> M[t] >> W[t];
    for (int i = 1; i <= N[t]; i++) {
      for (int j = 1; j <= N[t]; j++) {
        if (i != j) {
          D[t][i][j] = INF;
        } else {
          D[t][i][j] = 0;
        }
      }
    }

    for (int i = 0; i < M[t]; i++) {
      int S, E, T;
      cin >> S >> E >> T;
      if (D[t][S][E] == INF || D[t][S][E] > T) {
        D[t][S][E] = T;
      }
      if (D[t][E][S] == INF || D[t][E][S] > T) {
        D[t][E][S] = T;
      }
    }
    for (int i = 0; i < W[t]; i++) {
      int S, E, T;
      cin >> S >> E >> T;
      if (D[t][S][E] == INF || D[t][S][E] > -T) {
        D[t][S][E] = -T;
      }
    }
  }
}

void solve() {
  for (int t = 0; t < TC; t++) {
    int n = N[t];
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          D[t][i][j] = min(D[t][i][j], D[t][i][k] + D[t][k][j]);
        }
      }
    }
    /*
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(D[t][i][j]==INF){
          cout << "INF\t";
        } else{
          cout << D[t][i][j] << "\t";
        }
      }
      cout << endl;
    }
    cout << endl;
    */
    int i;
    for (i = 1; i <= n; i++) {
      if (D[t][i][i] < 0) {
        break;
      }
    }
    if (i == n + 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
