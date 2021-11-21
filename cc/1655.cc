#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
int N;
priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;

void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}

void solve() {
  cin >> N;
  int temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    if (max_pq.size() > min_pq.size()) {
      if (temp >= max_pq.top()) {
        min_pq.push(temp);
      } else {
        max_pq.push(temp);
        min_pq.push(max_pq.top());
        max_pq.pop();
      }
      cout << min(max_pq.top(), min_pq.top()) << endl;
    } else {
      if (max_pq.empty()) {
        max_pq.push(temp);
        cout << temp << endl;
        continue;
      }
      if (temp < min_pq.top()) {
        max_pq.push(temp);
      } else {
        min_pq.push(temp);
        max_pq.push(min_pq.top());
        min_pq.pop();
      }
      cout << max_pq.top() << endl;
    }
  }
}
