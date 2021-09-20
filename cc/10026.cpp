#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

enum Color {
	R,G,B,X
};

int N;
vector<vector<int>> RGB_board;
vector<vector<int>> RB_board;

int RGB_answer=0;
int RB_answer=0;

void input();
void solve();
void RGB_section(int color,int y, int x);
void RB_section(int color, int y, int x);
bool is_valid_index(int y, int x);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	cout << RGB_answer << " " << RB_answer;
	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<int> RGB_temp;
		vector<int> RB_temp;
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;
			if (temp == 'R') {
				RGB_temp.push_back(R);
				RB_temp.push_back(R);
			}
			else if (temp == 'G') {
				RGB_temp.push_back(G);
				RB_temp.push_back(R);
			}
			else {
				RGB_temp.push_back(B);
				RB_temp.push_back(B);
			}
		}
		RGB_board.push_back(RGB_temp);
		RB_board.push_back(RB_temp);
	}
}

void solve() {
	//RGB∫Œ≈Õ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (RGB_board[i][j] != X) {
				RGB_answer++;
				RGB_section(RGB_board[i][j],i,j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (RB_board[i][j] != X) {
				RB_answer++;
				RB_section(RB_board[i][j], i, j);
			}
		}
	}
}

void RGB_section(int color, int y, int x) {
	RGB_board[y][x] = X;
	if (is_valid_index(y - 1, x) && RGB_board[y - 1][x] == color) {
		RGB_section(color, y - 1, x);
	}
	if (is_valid_index(y + 1, x) && RGB_board[y + 1][x] == color) {
		RGB_section(color, y + 1, x);
	}
	if (is_valid_index(y, x - 1) && RGB_board[y][x - 1] == color) {
		RGB_section(color, y, x - 1);
	}
	if (is_valid_index(y, x + 1) && RGB_board[y][x + 1] == color) {
		RGB_section(color, y, x + 1);
	}
}

void RB_section(int color, int y, int x) {
	RB_board[y][x] = X;
	if (is_valid_index(y - 1, x) && RB_board[y - 1][x] == color) {
		RB_section(color, y - 1, x);
	}
	if (is_valid_index(y + 1, x) && RB_board[y + 1][x] == color) {
		RB_section(color, y + 1, x);
	}
	if (is_valid_index(y, x - 1) && RB_board[y][x - 1] == color) {
		RB_section(color, y, x - 1);
	}
	if (is_valid_index(y, x + 1) && RB_board[y][x + 1] == color) {
		RB_section(color, y, x + 1);
	}
}

bool is_valid_index(int y, int x){
	return y < N && x < N && y >= 0 && x >= 0;
}