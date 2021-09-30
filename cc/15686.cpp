#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int answer = 10000;
int N;
int M;
int num_1 = 0;
int num_2 = 0;
vector<vector<int>> board;
vector<int> chicken;
vector<vector<int>> dist;

void solve();
void input();
void display(vector<vector<int>> target);
void display(vector<bool> target);
void select_chicken();
void select_chicken(int current_index, int selected, vector<bool> visited);
void calculate(vector<bool> visited);

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  cout << answer;
  return 0;
}

void input() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    vector<int> temp;
    for (int j = 0; j < N; j++) {
      int _temp;
      cin >> _temp;
      temp.push_back(_temp);
      if (_temp == 1) {
        num_1++;
      } else if (_temp == 2) {
        num_2++;
        chicken.push_back(N * i + j);
      }
    }
    board.push_back(temp);
  }
  // display(board);
  // cout << endl;
}

void solve() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 1) {
        vector<int> temp;
        for (int k = 0; k < num_2; k++) {
          temp.push_back(abs(i - chicken[k] / N) + abs(j - chicken[k] % N));
        }
        dist.push_back(temp);
      }
    }
  }
  // cout << "dist : " << endl;
  // display(dist);
  select_chicken();
}
void display(vector<vector<int>> target) {
  for (auto row : target) {
    for (auto col : row) {
      cout << col << " ";
    }
    cout << endl;
  }
}

void display(vector<bool> target) {
  for (auto element : target) {
    cout << element << " ";
  }
  cout << endl;
}

void select_chicken() {
  vector<bool> visited(13, false);
  select_chicken(0, 0, visited);
}

void select_chicken(int current_index, int selected, vector<bool> visited) {
  // cout << "current_index : " << current_index << " selected : " << selected
  // << " visted :" << endl; display(visited);
  if (selected == M) {
    calculate(visited);
    return;
  }

  if (current_index == num_2) {
    return;
  }

  visited[current_index] = true;
  select_chicken(current_index + 1, selected + 1, visited);
  visited[current_index] = false;
  select_chicken(current_index + 1, selected, visited);
}

void calculate(vector<bool> visited) {
  int temp_answer = 0;

  for (int i = 0; i < num_1; i++) {
    int shortest = 1000000000;

    int temp = 0;
    while (temp < num_2) {
      if (visited[temp] && shortest > dist[i][temp]) {
        shortest = dist[i][temp];
      }
      temp++;
    }
    // cout << "shortest : " << shortest << endl;
    temp_answer += shortest;
  }
  // cout << "temp_answer : " << temp_answer << endl;
  if (temp_answer < answer) {
    answer = temp_answer;
  }
}