#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int N, M;
char Board[10][10];
bool visited[10][10][10][10];
int answer = 0;
int init_r_y;
int init_r_x;
int init_b_y;
int init_b_x;

void input();
void solve();
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct state {
  int r_y;
  int r_x;
  int b_y;
  int b_x;
  int counts;
};

state make_state(int new_r_y, int new_r_x, int new_b_y, int new_b_x,
                 int new_counts) {
  state result;
  result.b_x = new_b_x;
  result.b_y = new_b_y;
  result.counts = new_counts;
  result.r_x = new_r_x;
  result.r_y = new_r_y;
  return result;
}

int main() {
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
      Board[i][j] = getchar();
      if (Board[i][j] == 'R') {
        init_r_y = i;
        init_r_x = j;
        Board[i][j] = '.';
      }
      if (Board[i][j] == 'B') {
        init_b_y = i;
        init_b_x = j;
        Board[i][j] = '.';
      }
    }
    getchar();
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << Board[i][j];
    }
    cout << endl;
  }
}

void solve() {
  queue<state> q;
  q.push(make_state(init_r_y, init_r_x, init_b_y, init_b_x, 0));
  visited[init_r_y][init_r_x][init_b_y][init_b_x] = true;

  while (!q.empty()) {
    int now_r_y = q.front().r_y;
    int now_r_x = q.front().r_x;
    int now_b_y = q.front().b_y;
    int now_b_x = q.front().b_x;
    int now_count = q.front().counts;
    cout << "\n******현재" << endl;
    cout << "now : " << now_r_y << " " << now_r_x << "  " << now_b_y << " "
         << now_b_x << endl;
    q.pop();
    if (now_count >= 10) {
      break;
    }

    for (int d = 0; d < 4; d++) {
      switch (d) {
        case 0:
          cout << "아래쪽..\n";
          break;
        case 1:
          cout << "위쪽..\n";
          break;
        case 2:
          cout << "오른쪽..\n";
          break;
        case 3:
          cout << "왼쪽..\n";
          break;

        default:
          break;
      }
      int next_r_y = now_r_y;
      int next_r_x = now_r_x;
      int next_b_y = now_b_y;
      int next_b_x = now_b_x;

      // 구슬 두개가 가게될 이동경로
      queue<pair<int, int>> red_q;
      cout << "red_q filling...\n";
      while (true) {
        if (Board[next_r_y + dir[d][0]][next_r_x + dir[d][1]] != '#') {
          cout << "y, x : " << next_r_y << " " << next_r_x << endl;
          red_q.push(make_pair(next_r_y + dir[d][0], next_r_x + dir[d][1]));
          next_r_y += dir[d][0];
          next_r_x += dir[d][1];
        } else {
          break;
        }
      }

      queue<pair<int, int>> blue_q;

      cout << "blue_q filling...\n";
      while (true) {
        if (Board[next_b_y + dir[d][0]][next_b_x + dir[d][1]] != '#') {
          cout << "y, x : " << next_b_y << " " << next_b_x << endl;
          blue_q.push(make_pair(next_b_y + dir[d][0], next_b_x + dir[d][1]));
          next_b_y += dir[d][0];
          next_b_x += dir[d][1];
        } else {
          break;
        }
      }
      bool is_red_in_hole = false;
      bool is_blue_in_hole = false;
      int rqy = now_r_y;
      int rqx = now_r_x;
      int bqy = now_b_y;
      int bqx = now_b_x;
      int prev_rqy = now_r_y;
      int prev_rqx = now_r_x;
      int prev_bqy = now_b_y;
      int prev_bqx = now_b_x;

      while (!red_q.empty()) {
        rqy = red_q.front().first;
        rqx = red_q.front().second;
        if (Board[rqy][rqx] == 'O') {
          is_red_in_hole = true;
          break;
        }
        if (rqy == now_b_y && rqx == now_b_x) {
          rqy = prev_rqy;
          rqx = prev_rqx;
          break;
        }

        red_q.pop();
        prev_rqy = rqy;
        prev_rqx = rqx;
      }

      while (!blue_q.empty()) {
        bqy = blue_q.front().first;
        bqx = blue_q.front().second;
        if (Board[bqy][bqx] == 'O') {
          cout << "blue in hole!\n";
          is_blue_in_hole = true;
          break;
        }
        if (rqy == bqy && rqx == bqx) {
          bqy = prev_bqy;
          bqx = prev_bqx;
          break;
        }

        blue_q.pop();
        prev_bqy = bqy;
        prev_bqx = bqx;
      }

      while (!is_red_in_hole && !red_q.empty()) {
        rqy = red_q.front().first;
        rqx = red_q.front().second;
        if (Board[rqy][rqx] == 'O') {
          is_red_in_hole = true;
          break;
        }
        if (rqy == bqy && rqx == bqx) {
          rqy = prev_rqy;
          rqx = prev_rqx;
          break;
        }
        red_q.pop();
        prev_rqy = rqy;
        prev_rqx = rqx;
      }

      if (is_blue_in_hole) {
        continue;
      } else if (is_red_in_hole) {
        cout << now_count + 1 << endl;
        exit(0);
      }

      if (!visited[rqy][rqx][bqy][bqx]) {
        visited[rqy][rqx][bqy][bqx] = true;
        q.push(make_state(rqy, rqx, bqy, bqx, now_count + 1));
        cout << "q pushed...\n";
        cout << "rqy, rqx, bqy, bqx : " << rqy << " " << rqx << " " << bqy
             << " " << bqx << endl;
      }
    }
  }
  cout << "-1" << endl;
}