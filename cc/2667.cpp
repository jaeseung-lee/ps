#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define endl '\n'

char Board[25][25];
int visited[25][25] = {0, };
int N;
vector<int> answer;

void input();
void solve();
bool is_valid_index(int y, int x);

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int main() {
	//ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> N;
	getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Board[i][j] = getchar();
		}
		getchar();
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Board[i][j]=='1' && visited[i][j]==0) {
				int size = 1;
				queue<pair<int,int>> q;
				q.push(make_pair(i, j));
				visited[i][j] = true;
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int d = 0; d < 4; d++) {
						if (is_valid_index(y + dir[d][0],x + dir[d][1]) &&
							Board[y + dir[d][0]][x + dir[d][1]] == '1' && visited[y + dir[d][0]][x + dir[d][1]]==0) {
							visited[y + dir[d][0]][x + dir[d][1]] = 1;
							q.push(make_pair(y + dir[d][0], x + dir[d][1]));
							size++;
						}
					}
				}
				answer.push_back(size);
			}
		}
	}
	cout << answer.size() << endl;
	sort(answer.begin(), answer.end());
	for (auto element : answer) {
		cout << element << endl;
	}
}

bool is_valid_index(int y, int x) {
	return y < N && x < N && y >= 0 && x >= 0;
}
