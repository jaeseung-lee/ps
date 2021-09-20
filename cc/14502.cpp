#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int N;
int M;
vector<vector<int>> s_board;
int best = 0;

void input();
void solve();
bool is_valid_index(int x, int y);
void solve_board(int i, int j, int k);
void spread(int x,int y, vector<vector<int>> &board);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
	cout << best;
	return 0;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < M; j++) {
			int object;
			cin >> object;
			temp.push_back(object);
		}
		s_board.push_back(temp);
	}
}

void solve() {
	for (int i = 0; i < N*M; i++) {
		while (i < N*M) {
			if (s_board[i / M][i%M] != 0) {
				i++;
			}
			else {
				break;
			}
		}

		if (i == N * M)
			break;

		for (int j = i + 1; j < N*M; j++) {
			while (j < N*M) {
				if (s_board[j / M][j%M] != 0) {
					j++;
				}
				else {
					break;
				}
			}

			if (j == N * M)
				break;

			for (int k = j + 1; k < N*M; k++) {
				while (k < N*M) {
					if (s_board[k / M][k%M] != 0) {
						k++;
					}
					else {
						break;
					}
				}
				if (k == N * M)
					break;
				//cout << "i : " << i << " j : " << j << " k : " << k << endl;
				solve_board(i, j, k);
			}
		}
	}
}

bool is_valid_index(int x, int y) {
	return x >= 0 && x < M && y >= 0 && y < N;
}

void solve_board(int i, int j, int k) {
	//cout << "i : " << i << " j : " << j << " k : " << k << endl;
	vector<vector<int>> board = s_board;
	board[i / M][i%M] = 1;
	board[j / M][j%M] = 1;
	board[k / M][k%M] = 1;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			//cout << "y : " << y << " x : " << x << endl;
			spread(x, y, board);
		}
	}

	int count = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (board[y][x] == 0) {
				count++;
			}
		}
	}

	if (count > best) {
		//cout << "i : " << i << " j : " << j << " k : " << k << endl;
		best = count;
	}
}

void spread(int x,int y, vector<vector<int>> &board) {
	if (board[y][x] != 2) {
		return;
	}

	if (is_valid_index(x + 1, y)) {
		if (board[y][x + 1] == 0) {
			board[y][x + 1] = 2;
			spread(x + 1, y, board);
		}
	}

	if (is_valid_index(x, y - 1)) {
		if (board[y - 1][x] == 0) {
			board[y - 1][x] = 2;
			spread(x, y - 1, board);
		}
	}

	if (is_valid_index(x - 1, y)) {
		if (board[y][x - 1] == 0) {
			board[y][x - 1] = 2;
			spread(x-1, y, board);
		}
	}

	if (is_valid_index(x, y + 1)) {
		if (board[y + 1][x] == 0) {
			board[y + 1][x] = 2;
			spread(x, y+1, board);
		}
	}
}