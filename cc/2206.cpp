#include <iostream>
#include <queue>

using namespace std;

#define INF 987654321
#define endl '\n'

struct node {
	int y;
	int x;
	int now;
	bool is_broken;
};

node make_node(int _y, int _x, int _now, bool _is_broken) {
	node a;
	a.y = _y;
	a.x = _x;
	a.now = _now;
	a.is_broken = _is_broken;
	return a;
}

int N, M;
char board[1001][1001];
bool visited[2][1001][1001];
int answer = INF;

void input();
void solve();
bool is_valid_index(int y, int x);

int main() {
	//ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	if (answer == INF) {
		cout << "-1";
	}
	else {
		cout << answer;
	}

	return 0;
}

void input() {
	cin >> N >> M;
	getchar();
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++)
		{
			board[i][j] = getchar();
			visited[0][i][j] = false;
			visited[1][i][j] = false;
			//cout << "board[" << i << "][" << j << "] : " << board[i][j] << endl;
		}
		getchar();
	}
}

void solve() {
	queue<node> q;
	visited[0][0][0] = true;
	q.push(make_node(0, 0, 1, false));
	
	while (!q.empty()) {
		int n_x = q.front().x;
		int n_y = q.front().y;
		int n_now = q.front().now;
		bool n_is_broken = q.front().is_broken;
		q.pop();

		if (n_y == N - 1 && n_x == M - 1) {
			answer = n_now;
			break;
		}

		if (is_valid_index(n_y + 1, n_x) && !visited[n_is_broken][n_y + 1][n_x] && board[n_y + 1][n_x] == '0') {
			visited[n_is_broken][n_y + 1][n_x] = true;
			q.push(make_node(n_y + 1, n_x, n_now + 1, n_is_broken));
		}
		if (is_valid_index(n_y - 1, n_x) && !visited[n_is_broken][n_y - 1][n_x] && board[n_y - 1][n_x] == '0') {
			visited[n_is_broken][n_y - 1][n_x] = true;
			q.push(make_node(n_y - 1, n_x, n_now + 1, n_is_broken));
		}
		if (is_valid_index(n_y, n_x + 1) && !visited[n_is_broken][n_y][n_x + 1] && board[n_y][n_x + 1] == '0') {
			visited[n_is_broken][n_y][n_x + 1] = true;
			q.push(make_node(n_y, n_x + 1, n_now + 1, n_is_broken));
		}
		if (is_valid_index(n_y, n_x - 1) && !visited[n_is_broken][n_y][n_x - 1] && board[n_y][n_x - 1] == '0') {
			visited[n_is_broken][n_y][n_x - 1] = true;
			q.push(make_node(n_y, n_x - 1, n_now + 1, n_is_broken));
		}

		if (!n_is_broken) {
			if (is_valid_index(n_y + 1, n_x) && !visited[n_is_broken][n_y + 1][n_x] && board[n_y + 1][n_x] == '1') {
				visited[1][n_y + 1][n_x] = true;
				q.push(make_node(n_y + 1, n_x, n_now + 1, true));
			}
			if (is_valid_index(n_y - 1, n_x) && !visited[n_is_broken][n_y - 1][n_x] && board[n_y - 1][n_x] == '1') {
				visited[1][n_y - 1][n_x] = true;
				q.push(make_node(n_y - 1, n_x, n_now + 1, true));
			}
			if (is_valid_index(n_y, n_x + 1) && !visited[n_is_broken][n_y][n_x + 1] && board[n_y][n_x + 1] == '1') {
				visited[1][n_y][n_x + 1] = true;
				q.push(make_node(n_y, n_x + 1, n_now + 1, true));
			}
			if (is_valid_index(n_y, n_x - 1) && !visited[n_is_broken][n_y][n_x - 1] && board[n_y][n_x - 1] == '1') {
				visited[1][n_y][n_x - 1] = true;
				q.push(make_node(n_y, n_x - 1, n_now + 1, true));
			}
		}
	}

}

bool is_valid_index(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}
