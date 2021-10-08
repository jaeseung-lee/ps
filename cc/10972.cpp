#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int N;
int numbers[10000 + 1];

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
  for (int i = 1; i <= N; i++) {
    cin >> numbers[i];
  }
}

void solve() {
  int i;
  int y;
  int index_y = -1;
  int index_x = N;
  int x = numbers[N];
  for (i = N - 1; i >= 1; i--) {
    if (x > numbers[i]) {
      y = numbers[i];
      index_y = i;
      break;
    } else {
      x = numbers[i];
    }
  }

  // cout << "index_y : " << index_y << " index_x : " << index_x << endl;

  if (i == 0) {
    cout << "-1" << endl;
  } else {
    priority_queue<int> pq;
    for (int k = index_y; k <= N; k++) {
      pq.push(-numbers[k]);
    }
    int pq_cursor = index_y + 1;
    bool is_y_filled = false;

    while (!pq.empty()) {
      int target = -pq.top();
      pq.pop();
      // cout << "target : " << target << endl;
      if (is_y_filled) {
        numbers[pq_cursor] = target;
        pq_cursor++;
      } else {
        if (y < target) {
          numbers[index_y] = target;
          is_y_filled = true;
        } else {
          numbers[pq_cursor] = target;
          pq_cursor++;
        }
      }
    }

    for (int i = 1; i <= N; i++) {
      cout << numbers[i] << " ";
    }
  }
}