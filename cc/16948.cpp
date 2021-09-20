#include <iostream>
#include <queue>

using namespace std;

int N;
int init_y;
int init_x;
int target_y;
int target_x;
int visited[201][201] = { 0, };

void input();
void solve();
bool is_valid_index(int y, int x);

int dy[6] = { -2,-2,0,0,2,2 };
int dx[6] = { -1,1,-2,2,-1,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> N;
	cin >> init_y >> init_x >> target_y >> target_x;
}

void solve() {
	queue<pair<int, int>> q;
	q.push(make_pair(init_y, init_x));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = -1;
		}
	}

	visited[init_y][init_x] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		int value = visited[y][x];
		q.pop();
		for (int d = 0; d < 6; d++) {
			if (is_valid_index(y + dy[d], x + dx[d]) && visited[y + dy[d]][x + dx[d]]==-1) {
				visited[y + dy[d]][x + dx[d]] = value+1;
				q.push(make_pair(y + dy[d], x + dx[d]));
				if (y + dy[d] == target_y && x + dx[d] == target_x) {
					cout << value;
					exit(0);
				}
			}
		}
	}
	cout << "-1";
}

bool is_valid_index(int y, int x) {
	return y < N && y >= 0 && x < N && x >= 0;
}