#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define endl '\n'

// state를 vector<vector<int>> -> int로 바꾸자.

//게임 상태가 등장했었는지 저장하는 집합
set<int> Set;

//초기 상태
int init;

//초기 0의 위치
int initY, initX;

// 4 방향
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int pow10[10];

struct state {
  int state;
  int zero_y;
  int zero_x;
  int move;
};

void input();
void solve();

state make_state(const int target, const int zero_y, const int zero_x,
                 const int move) {
  state result;
  result.state = target;
  result.zero_y = zero_y;
  result.zero_x = zero_x;
  result.move = move;
  return result;
}

// target의 locate 자리 번째 숫자 반환
int digit(const int target, const int locate) {
  return (target / pow10[locate]) % 10;
}

void changeDigit(int& target, const int locate, int target_digit) {
  target -= digit(target, locate) * pow10[locate];
  target += target_digit * pow10[locate];
}

bool isAnswer(const int target) { return target == 123456780; }

bool isValidIndex(const int& y, const int& x) {
  return y < 3 && y >= 0 && x < 3 && x >= 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();

  // test
  /*
  cout << digit(61234, 2) << endl;
  int target = 10500;
  changeDigit(target, 2, 3);
  cout << target << endl;
  */

  solve();

  return 0;
}

void input() {
  // fill pow10
  int value = 1;
  for (int i = 0; i < 10; i++) {
    pow10[i] = value;
    value *= 10;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int temp;
      cin >> temp;
      init = init * 10 + temp;
      if (temp == 0) {
        initY = 2 - i;
        initX = 2 - j;
      }
    }
  }
}

void solve() {
  Set.insert(init);
  queue<state> q;
  q.push(make_state(init, initY, initX, 0));

  while (!q.empty()) {
    state now_state = q.front();
    q.pop();
    if (isAnswer(now_state.state)) {
      cout << now_state.move << endl;
      exit(0);
    }
    /*
    if (now_state.move > 3) {
      exit(0);
    }
    cout << "now : " << now_state.state << endl;
    cout << "move : " << now_state.move << endl;
    cout << "zero : " << now_state.zero_y << " " << now_state.zero_x << endl;
    */
    for (int d = 0; d < 4; d++) {
      if (isValidIndex(now_state.zero_y + dir[d][0],
                       now_state.zero_x + dir[d][1])) {
        int next = now_state.state;
        changeDigit(next, 3 * now_state.zero_y + now_state.zero_x,
                    digit(now_state.state, 3 * (now_state.zero_y + dir[d][0]) +
                                               (now_state.zero_x + dir[d][1])));
        changeDigit(
            next,
            3 * (now_state.zero_y + dir[d][0]) + (now_state.zero_x + dir[d][1]),
            digit(now_state.state, 3 * now_state.zero_y + now_state.zero_x));
        // cout << "next : " << next << endl;
        if (Set.find(next) == Set.end()) {
          Set.insert(next);
          q.push(make_state(next, now_state.zero_y + dir[d][0],
                            now_state.zero_x + dir[d][1], now_state.move + 1));
        }
      }
    }
  }

  // cout << Set.size() << endl;
  cout << "-1" << endl;
}
