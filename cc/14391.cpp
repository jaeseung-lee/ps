#include <iostream>

using namespace std;

#define endl '\n'

int N, M;
int Board[5][5];
int answer = 0;
bool visited[5][5];

void input();
void solve();
void dfs(int y, int x, int value);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> Board[i][j];
			visited[i][j] = false;
		}
	}
}

void solve() {
	dfs(0, 0, 0);
}

void dfs(int y, int x, int value) {
	if (y == N && x == M) {
		if (!visited[y][x] && answer < value + Board[y][x]) {
			answer = value + Board[y][x];
			return;
		}
		if (visited[y][x] && answer < value) {
			answer = value;
			return;
		}
	}

	if (visited[y][x]) {
		if (x < M) {
			dfs(y, x + 1, value);
		}
		else {
			dfs(y + 1, 1, value);
		}
		return;
	}

	//가로로 하나씩 넣어보기

	//세로로 하나씩 넣어보기
}