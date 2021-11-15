#include <iostream>

using namespace std;

int n, w, L;
int A[1000];
int Bridge[1000];
int ans = 0;

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
  cin >> n >> w >> L;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
}

void solve() {
  int first_truck = 0;
  int next_truck = 0;
  int now_weight = 0;
  int l = 0;
  while (first_truck < n) {
    //모든 다리위의 트럭을 한 칸씩 움직임 -> 다리의 1번자리는 무조건 비어있음
    for (int i = first_truck; i < next_truck; i++) {
      Bridge[i]++;
      if (Bridge[i] > w) {
        first_truck++;
        now_weight -= A[i];
        l--;
      }
    }
    //다음 트럭을 한 칸 올릴 수 있는지 확인
    if (next_truck < n && l + 1 <= w && now_weight + A[next_truck] <= L) {
      l++;
      now_weight += A[next_truck];
      Bridge[next_truck] = 1;
      next_truck++;
    }
    ans++;
  }

  cout << ans;
}
