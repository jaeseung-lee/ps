#include <cmath>
#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

int N, L, R;
int board[50][50];
bool visited[50][50];

void input();
void solve();
void init_visited();
bool is_valid_index(int y, int x);
bool is_edge(int first_y, int first_x, int second_y, int second_x);

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N >> L >> R;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
}

void solve() {
  int answer = 0;
  while (true) {
    init_visited();
    bool is_all_countries_closed = true;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (!visited[i][j]) {
          vector<pair<int, int>> countries;
          countries.push_back(make_pair(i, j));
          visited[i][j] = true;
          int index = 0;
          // cout << "i,j : " <<i << " " << j << endl;
          while (index != countries.size()) {
            int front_y = countries[index].first;
            int front_x = countries[index].second;
            // cout << "front_y,front_x : " << front_y << " " << front_x <<
            // endl;
            for (int d_index = 0; d_index < 4; d_index++) {
              int now_y = front_y + dy[d_index];
              int now_x = front_x + dx[d_index];
              if (is_valid_index(now_y, now_x) && !visited[now_y][now_x] &&
                  is_edge(now_y, now_x, front_y, front_x)) {
                countries.push_back(make_pair(now_y, now_x));
                visited[now_y][now_x] = true;
              }
            }
            index++;
          }

          if (countries.size() != 1) {
            is_all_countries_closed = false;
            // cout<< "closed false" << endl;
          }
          int sum = 0;
          for (int c_index = 0; c_index < countries.size(); c_index++) {
            sum += board[countries[c_index].first][countries[c_index].second];
          }
          int average = sum / countries.size();
          for (int c_index = 0; c_index < countries.size(); c_index++) {
            board[countries[c_index].first][countries[c_index].second] =
                average;
          }
        }
      }
    }
    if (is_all_countries_closed) {
      break;
    }
    // cout << "answer : "<<answer<<endl;
    answer++;
  }
  cout << answer;
}

void init_visited() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      visited[i][j] = false;
    }
  }
}
bool is_valid_index(int y, int x) { return y < N && y >= 0 && x < N && x >= 0; }
bool is_edge(int first_y, int first_x, int second_y, int second_x) {
  int value = abs(board[first_y][first_x] - board[second_y][second_x]);
  return value <= R && value >= L;
}
