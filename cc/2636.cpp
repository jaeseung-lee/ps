#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int Board[100][100];
int EmptyBoard[100][100];
bool visited[100][100];
int R, C;
queue<pair<int, int>> target_q;
int CheeseCount = 0;
int answer = 0;

void input();
void solve();
void init_visited();
void init_EmptyBoard();
void fill_target_q();
bool is_valid_index(int y, int x);

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> Board[i][j];
      if (Board[i][j] == 1) {
        CheeseCount++;
      }
    }
  }
}

void solve() {
  init_EmptyBoard();
  // cout << "now q:" << target_q.size() << endl;
  while (true) {
    // EmptyBoard에서 target을 target_q에 올림
    fill_target_q();
    // cout << "now q:" << target_q.size() << endl;
    answer++;
    //그 수 만큼 CheeseCount 줄이는데 줄이기전에 CheeseCount=0이되면 answer출력
    if (CheeseCount == target_q.size()) {
      cout << answer << endl;
      cout << CheeseCount << endl;
      break;
    }
    CheeseCount -= target_q.size();

    // Target_q에 들어있는 것들보고 Board[][], EmptyBoard[][]도 0으로 만듦
    while (!target_q.empty()) {
      int y = target_q.front().first;
      int x = target_q.front().second;
      // cout << "y,x : " << y << " " << x<<endl;
      target_q.pop();
      Board[y][x] = 0;
    }
    init_EmptyBoard();
  }
}

void init_EmptyBoard() {
  init_visited();
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      EmptyBoard[i][j] = 1;
    }
  }

  vector<pair<int, int>> Crust_Index;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (i == 0 || j == 0 || i == R - 1 || j == C - 1) {
        Crust_Index.push_back(make_pair(i, j));
      }
    }
  }
  // cout << Crust_Index.size() << endl;
  for (int index = 0; index < Crust_Index.size(); index++) {
    int i = Crust_Index[index].first;
    int j = Crust_Index[index].second;
    // cout << "i,j : " << i << " " << j << endl;
    if (Board[i][j] == 0 && !visited[i][j]) {
      queue<pair<int, int>> q;
      q.push(make_pair(i, j));
      visited[i][j] = true;
      while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        EmptyBoard[y][x] = 0;
        q.pop();
        for (int d = 0; d < 4; d++) {
          if (is_valid_index(y + dir[d][0], x + dir[d][1]) &&
              !visited[y + dir[d][0]][x + dir[d][1]] &&
              Board[y + dir[d][0]][x + dir[d][1]] == 0) {
            visited[y + dir[d][0]][x + dir[d][1]] = true;
            q.push(make_pair(y + dir[d][0], x + dir[d][1]));
          }
        }
      }
    }
  }
}

void fill_target_q() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (EmptyBoard[i][j] == 1) {
        if (EmptyBoard[i + 1][j] == 0 || EmptyBoard[i - 1][j] == 0 ||
            EmptyBoard[i][j + 1] == 0 || EmptyBoard[i][j - 1] == 0) {
          target_q.push(make_pair(i, j));
        }
      }
    }
  }
}

bool is_valid_index(int y, int x) { return y < R && y >= 0 && x < C && x >= 0; }

void init_visited() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      visited[i][j] = false;
    }
  }
}
