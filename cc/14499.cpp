#include <iostream>
#include <vector>

using namespace std;

enum direction {
	EAST=1,WEST=2,NORTH=3,SOUTH=4
};

int N;
int M;
int x;
int y;
int K;
vector<vector<int>> board;
vector<int> order;
int dice[7];

void input();
void solve();
void roll(int direction);
bool is_valid_index(int _x, int _y);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			row.push_back(temp);
		}
		board.push_back(row);
	}

	for (int i = 0; i < K; i++) {
		int temp;
		cin >> temp;
		order.push_back(temp);
	}
}

void solve() {
	for (int i = 1; i <= 6; i++) {
		dice[i] = 0;
	}

	for (int i = 0; i < K; i++) {
		//x,y ÁÂÇ¥ È®ÀÎ + ÁÖ»çÀ§ ´« º¯°æ

		switch (order[i]) {
		case EAST:
			y++;
			if (!is_valid_index(x, y)) {
				y--;
				continue;
			}
			roll(EAST);
			break;
		case WEST:
			y--;
			if (!is_valid_index(x, y)) {
				y++;
				continue;
			}
			roll(WEST);
			break;
		case SOUTH:
			x++;
			if (!is_valid_index(x, y)) {
				x--;
				continue;
			}
			roll(SOUTH);
			break;
		case NORTH:
			x--;
			if (!is_valid_index(x, y)) {
				x++;
				continue;
			}
			roll(NORTH);
			break;
		}
		//cout << "x : " << x << " y : " << y << endl;
		if (board[x][y] == 0) {
			board[x][y] = dice[6];
		}
		else {
			dice[6] = board[x][y];
			board[x][y] = 0;
		}
		cout << dice[1] << endl;
	}
}

void roll(int direction) {
	int new_dice[7];
	switch (direction) {
	case EAST:
		new_dice[1] = dice[4];
		new_dice[2] = dice[2];
		new_dice[3] = dice[1];
		new_dice[4] = dice[6];
		new_dice[5] = dice[5];
		new_dice[6] = dice[3];
		break;
	case WEST:
		new_dice[1] = dice[3];
		new_dice[2] = dice[2];
		new_dice[3] = dice[6];
		new_dice[4] = dice[1];
		new_dice[5] = dice[5];
		new_dice[6] = dice[4];
		break;
	case NORTH:
		new_dice[1] = dice[5];
		new_dice[2] = dice[1];
		new_dice[3] = dice[3];
		new_dice[4] = dice[4];
		new_dice[5] = dice[6];
		new_dice[6] = dice[2];
		break;
	case SOUTH:
		new_dice[1] = dice[2];
		new_dice[2] = dice[6];
		new_dice[3] = dice[3];
		new_dice[4] = dice[4];
		new_dice[5] = dice[1];
		new_dice[6] = dice[5];
		break;
	}
	for (int i = 1; i <= 6; i++) {
		dice[i] = new_dice[i];
	}
}

bool is_valid_index(int _x, int _y) {
	return _x < N && _x >= 0 && _y < M && _y >= 0;
}