#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

enum status {
	EMPTY,SNAKE,APPLE
};

enum direction {
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3
};

int N;
int K;
int L;

vector<vector<int>> board;
int direction = RIGHT;
vector<pair<int, char>> change;
vector<int> direction_record;
long answer = 0;
int cur_x = 0;
int cur_y = 0;
int change_index = 0;
int L_next_direction(int dir);
int D_next_direction(int dir);
int snake_length = 1;

void input();
void solve();
bool is_valid_index(int y, int x);
void display();

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
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < N; j++) {
			temp.push_back(EMPTY);
		}
		board.push_back(temp);
	}
	board[0][0] = SNAKE;

	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		board[y-1][x-1] = APPLE;
	}

	cin >> L;
	
	for (int i = 0; i < L; i++) {
		int time;
		char dir;
		cin >> time >> dir;
		change.push_back(make_pair(time, dir));
	}
}


void solve() {
	while (true) {
		//display();
		answer++;
		direction_record.push_back(direction);
		//cout << "cur_y : " << cur_y << " cur_x : " << cur_x << endl;
		if (direction == RIGHT) {
			cur_x++;
		}
		else if (direction == LEFT) {
			cur_x--;
		}
		else if (direction == UP) {
			cur_y--;
		}
		else {
			cur_y++;
		}

		if (!is_valid_index(cur_y, cur_x)||board[cur_y][cur_x]==SNAKE) {
			break;
		}
		//cout << "dir : " << direction << endl;
		//cout << "cur_y, cur_x : " << cur_y << ", " << cur_x << endl;

		if (board[cur_y][cur_x] == EMPTY) {
			//한 칸 전진
			board[cur_y][cur_x] = SNAKE;

			//꼬리제거
			int temp_y = cur_y;
			int temp_x = cur_x;
			int index = direction_record.size();

			for(int i=1;i<=snake_length;i++)
			{
				if (direction_record[index-i] == RIGHT) {
					temp_x--;
				}
				else if (direction_record[index-i] == LEFT) {
					temp_x++;
				}
				else if (direction_record[index-i] == UP) {
					temp_y++;
				}
				else {
					temp_y--;
				}
				
			}
			//cout << "temp_y, temp_x :" << temp_y << ", " << temp_x << endl;
			//cout << "tail- temp_y, temp_x : " << temp_y << ", " << temp_x << endl;
			board[temp_y][temp_x] = EMPTY;
			//cout << "here" << endl;
		}
		else if (board[cur_y][cur_x] == APPLE) {
			board[cur_y][cur_x] = SNAKE;
			snake_length++;
		}

		//방향전환
		if (change_index == change.size())
			continue;
		//cout << "change[change_index] : " << change[change_index].first << endl;
		if (change[change_index].first == answer) {
			if (change[change_index].second == 'L') {
				direction = L_next_direction(direction);
			}
			if (change[change_index].second == 'D') {
				direction = D_next_direction(direction);
			}
			change_index++;
		}
	}
}

bool is_valid_index(int y, int x) {
	return y < N && x < N && y >= 0 && x >= 0;
}

int D_next_direction(int dir) {
	int _answer = dir + 1;
	if (_answer == 4) {
		_answer = 0;
	}
	return _answer;
}

int L_next_direction(int dir) {
	int _answer = dir - 1;
	if (_answer == -1) {
		_answer = 3;
	}
	return _answer;
}

void display() {
	for (auto row : board) {
		for (auto element : row) {
			if (element == EMPTY) {
				cout << "1";
			}
			else if (element == SNAKE) {
				cout << "S";
			}
			else {
				cout << "A";
			}
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}