#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int N, M;

bool visited[100][100][10000];
char Board[100][100];
void input();
void solve();

bool is_valid_index(int y, int x);
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

int main() {
	//ios::sync_with_stdio(false);
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
		}
		getchar();
	}
}

void solve() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 0));
	visited[]
}

bool is_valid_index(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}