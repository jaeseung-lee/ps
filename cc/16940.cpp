#include <iostream>
#include <queue>
#include <vector>

#define endl '\n'

using namespace std;

int N;
vector<int> edges[100001];
void input();
void solve();
queue<int> opened_index;
int parent[100001];
int target[100001];
bool is_closed[100001];

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
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    opened_index.push(a);
    target[i] = a;
  }
}

void solve() {
  // parent index부터 init
  parent[1] = -1;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int now = q.front();
    // cout << "now : " << now << endl;
    q.pop();
    for (int i = 0; i < edges[now].size(); i++) {
      if (parent[edges[now][i]] == 0) {
        parent[edges[now][i]] = now;
        q.push(edges[now][i]);
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    is_closed[i] = false;
  }

  if (opened_index.front() != 1) {
    cout << "0";
    exit(0);
  }

  for (int i = 1; i < N; i++) {
    int now_index = target[i];
    if (parent[now_index] == opened_index.front()) {
      continue;
    } else {
      if (is_closed[parent[now_index]]) {
        cout << "0" << endl;
        exit(0);
      } else {
        is_closed[opened_index.front()] = true;
        opened_index.pop();
        if (opened_index.front() != parent[now_index]) {
          // cout << "target : " << target[i] << " parent[now_index] : "<<
          // parent[now_index] << " opened_index : " << opened_index.front() <<
          // endl;
          while (true) {
            opened_index.pop();
            if (opened_index.front() == parent[now_index]) {
              break;
            } else if (opened_index.front() == now_index) {
              cout << "0" << endl;
              exit(0);
            }
          }
        }
      }
    }
  }
  cout << "1" << endl;
}
