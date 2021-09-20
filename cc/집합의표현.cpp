#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

int n, m;
vector<vector<int>> edge;
struct operation {
  bool op;
  int a;
  int b;
};
vector<operation> ops;

operation make_op(bool _op, int _a, int _b);
void init_edge();
void input();
void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  init_edge();
  solve();

  return 0;
}

operation make_op(bool _op, int _a, int _b) {
  operation result;
  result.a = _a;
  result.b = _b;
  result.op = _op;
  return result;
}

void init_edge() {
  for (int i = 0; i <= n; i++) {
    vector<int> temp;
    // temp.push_back(i);
    edge.push_back(temp);
  }
}

void input() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    bool _op;
    int _a, _b;
    cin >> _op >> _a >> _b;
    ops.push_back(make_op(_op, _a, _b));
  }
}

void solve() {
  for (int i = 0; i < m; i++) {
    bool op = ops[i].op;
    int a = ops[i].a;
    int b = ops[i].b;
    if (!op) {
      // edge 추가
      edge[a].push_back(b);
      edge[b].push_back(a);

    } else {
      //교집합인지 확인
      int found = false;
      if (a == b) {
        found = true;
      } else {
        queue<int> q;
        q.push(a);
        bool visited[1000000 + 1] = {
            0,
        };
        visited[a] = true;
        while (!q.empty() && !found) {
          int now = q.front();
          for (int j = 0; j < edge[now].size(); j++) {
            if (edge[now][j] == b) {
              found = true;
              break;
            } else if (!visited[edge[now][j]]) {
              q.push(edge[now][j]);
              visited[edge[now][j]] = true;
            }
          }
          q.pop();
        }
      }

      if (found) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}
