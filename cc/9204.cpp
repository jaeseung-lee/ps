#include <iostream>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

#define endl '\n'

struct node {
	bool visited;
	int prev_y;
	int prev_x;
	int value;
};

int T;
vector<pair<pair<int, int>, pair<int, int>>> testcases;
node map[8][8];

void input();
void solve();
int to_index(char alphabet);
char to_alphabet(int index);
bool is_black(int y, int x);
bool is_valid_index(int y, int x);

int dy[4] = { 1,1,-1,-1 };
int dx[4] = { 1,-1,1,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		char a,c;
		int b,d;
		cin >> a >> b >> c >> d;
		testcases.push_back(make_pair(make_pair(a, b-1), make_pair(c, d-1)));
	}
}

void solve() {
	for (int t = 0; t < T; t++) {
		int source_y = to_index(testcases[t].first.first);
		int source_x = testcases[t].first.second;
		int target_y= to_index(testcases[t].second.first);
		int target_x= testcases[t].second.second;
		//cout << "source : " << source_y << " " << source_x << endl;
		//cout << "target : " << target_y << " " << target_x << endl;
		if (is_black(source_y, source_x) != is_black(target_y, target_x)) {
			cout << "Impossible" << endl;
			continue;
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				map[i][j].prev_x = -1;
				map[i][j].prev_y = -1;
				map[i][j].visited = false;
				map[i][j].value = 0;
			}
		}

		queue<pair<int, int>> q;
		q.push(make_pair(source_y, source_x));
		map[source_y][source_x].visited = true;
		bool found = false;
		while (!q.empty() && !found) {
			int now_y = q.front().first;
			int now_x = q.front().second;
			int value = map[now_y][now_x].value;
			if (now_y == target_y && now_x == target_x) {
				break;
			}
			q.pop();
			//cout << "now_y : " << now_y << " now_x : " << now_x << endl;
			for (int d = 0; d < 4 && !found; d++) {
				int temp_y = now_y;
				int temp_x = now_x;
				
				while (!found) {
					temp_y += dy[d];
					temp_x += dx[d];
					//cout << "temp_y : " << temp_y << " temp_x : " << temp_x << endl;
					if (!is_valid_index(temp_y, temp_x)) {
						break;
					}
					if (map[temp_y][temp_x].visited) {
						continue;
					}
					map[temp_y][temp_x].prev_y = now_y;
					map[temp_y][temp_x].prev_x = now_x;
					map[temp_y][temp_x].value = value + 1;
					map[temp_y][temp_x].visited = true;
					if (temp_y == target_y && temp_x == target_x) {
						found = true;
					}
					q.push(make_pair(temp_y, temp_x));
				}
				//cout << "next" << endl;
			}
		}

		stack<pair<int, int>> answer;
		int y = target_y;
		int x = target_x;
		while (true) {
			//cout <<  "target : " << y << " " << x << endl;
			if (y == -1 && x == -1) {
				break;
			}
			answer.push(make_pair(y, x));
			int prev_y = map[y][x].prev_y;
			int prev_x = map[y][x].prev_x;
			y = prev_y;
			x = prev_x;
		}

		cout << answer.size() - 1 << " ";
		while (!answer.empty()) {
			cout << to_alphabet(answer.top().first) << " " << answer.top().second + 1 << " ";
			answer.pop();
		}
		cout << endl;
	}
}

int to_index(char alphabet) {
	return (int)alphabet - (int)'A';
}

char to_alphabet(int index) {
	return (char)(index + (int)'A');
}

bool is_black(int y, int x) {
	return abs(y - x) % 2 == 0;
}

bool is_valid_index(int y, int x) {
	return y < 8 && y >= 0 && x < 8 && x >= 0;
}