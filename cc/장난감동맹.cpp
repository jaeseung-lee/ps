#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

int T;
int N[10];
int M[10];

vector<int> edges[10][300000 + 1];
bool visited[300000 + 1];
int color[300000 + 1];

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
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N[i] >> M[i];
    for (int j = 0; j < M[i]; j++) {
      int a, b;
      cin >> a >> b;
      edges[i][a].push_back(b);
      edges[i][b].push_back(a);
    }
  }
}

void solve() {
  for (int t = 0; t < T; t++) {
    for (int i = 1; i <= N[t]; i++) {
      visited[i] = false;
      color[i] = 0;
    }
    bool is_answer = true;

    for (int i = 1; i <= N[t] && is_answer; i++) {
      if (!visited[i]) {
        queue<int> q;
        color[i] = 1;
        visited[i] = true;
        q.push(i);
        while (!q.empty() && is_answer) {
          int now = q.front();
          q.pop();
          for (int j = 0; j < edges[t][now].size(); j++) {
            int target_node = edges[t][now][j];
            if (!visited[target_node]) {
              visited[target_node] = true;
              q.push(target_node);
            }
            if (color[target_node] == 0) {
              if (color[now] == 2) {
                color[target_node] = 1;
              } else {
                color[target_node] = 2;
              }
            } else if (color[target_node] == color[now]) {
              is_answer = false;
              break;
            } else {
              continue;
            }
          }
        }
      }
    }
    if (is_answer) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }

    /*
        cout << "color : "<<endl;
        for(int k=1;k<=N[t];k++){
          int element = color[k];
          cout << element << " ";
        }
        cout << endl << "visited" << endl;
        for(int k=1;k<=N[t];k++){
          bool element = visited[k];
          if(element){
            cout << "1 ";
          } else {
            cout << "0 ";
          }
        }
        cout << endl;
    */
  }
}
