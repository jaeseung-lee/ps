/*
1. cin과 scanf,getchar를 혼용해서 쓸거면 ios::sync_with_stdio(false) 쓰면 안됨.
2. bfs은 queue에 넣기전에 visited=true로 바꿔야한다.
*/

#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define INF 987654321

int N, M;
char board[101][101];
bool visited[101][101];
int answer = INF;

void input();
void solve();
bool is_valid_index(int y, int x);

int main(void) {
	//ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	cout << answer;
	return 0;
}

void input() {
	cin >> N >> M;
	getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char inp = getchar();
			board[i][j] = inp;
			//cout << "board[" << i << "][" << j << "] : " << board[i][j] << endl;
		}
		getchar();
	}
}

void solve() {
	//((y,x),now)
	queue<pair<pair<int,int>,int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}
	visited[0][0] = true;
	q.push(make_pair(make_pair(0, 0), 1));

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int now = q.front().second;
		//cout << "y : " << y << " x : " << x << " now : " << now << endl;
		q.pop();
		if (y == N - 1 && x == M - 1) {
			answer = now;
			break;
		}

		if (is_valid_index(y + 1, x) && !visited[y + 1][x] && board[y + 1][x] == '1') {
			visited[y + 1][x] = true;
			q.push(make_pair(make_pair(y + 1, x), now + 1));
		}
		if (is_valid_index(y - 1, x) && !visited[y - 1][x] && board[y - 1][x] == '1') {
			visited[y - 1][x] = true;
			q.push(make_pair(make_pair(y - 1, x), now + 1));
		}
		if (is_valid_index(y, x + 1) && !visited[y][x + 1] && board[y][x + 1] == '1') {
			visited[y][x + 1] = true;
			q.push(make_pair(make_pair(y, x + 1), now + 1));
		}
		if (is_valid_index(y, x - 1) && !visited[y][x - 1] && board[y][x - 1] == '1') {
			visited[y][x - 1] = true;
			q.push(make_pair(make_pair(y, x - 1), now + 1));
		}

	}
}

bool is_valid_index(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}