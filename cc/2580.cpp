#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#define endl '\n'

int A[9][9];
int answer[9][9];
vector<pair<int, int>> blank;
int blank_size;

void input();
void solve();
void dfs(int b_index);
bool is_promising(int y, int x);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
	return 0;
}

void input() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int value;
			cin >> value;
			if (value == 0) {
				blank.push_back(make_pair(i, j));
			}
			A[i][j] = value;
		}
	}
	blank_size = blank.size();
}

void solve() {
	dfs(0);
}

void dfs(int b_index) {
	/*
	cout << "b_index : " << b_index << endl;
		for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
		  cout << A[i][j] << " ";
		}
		cout << endl;
	  }
	*/

	if (b_index == blank_size) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}

	for (int i = 1; i <= 9; i++) {
		A[blank[b_index].first][blank[b_index].second] = i;
		if (is_promising(blank[b_index].first, blank[b_index].second)) {
			dfs(b_index + 1);
		}
		A[blank[b_index].first][blank[b_index].second] = 0;
	}
}

bool is_promising(int y, int x) {
	//세로줄 확인

	for (int i = 0; i < 9; i++) {
		if (i != y && A[i][x] == A[y][x]) {
			return false;
		}
	}

	//가로줄 확인
	for (int i = 0; i < 9; i++) {
		if (i != x && A[y][i] == A[y][x]) {
			return false;
		}
	}
	//정사각형 확인
	int a = (y / 3) * 3;
	int b = (x / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i + a == y && j + b == x) {
				continue;
			}
			if (A[i + a][j + b] == A[y][x]) {
				return false;
			}
		}
	}

	return true;
}
