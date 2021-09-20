#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> edges[1001];
int answer = 0;
bool visited[1001] = { false, };

void input();
void solve();

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
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			answer++;
			visited[i] = true;
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int now_index = q.front();
				q.pop();
				for (int j = 0; j < edges[now_index].size(); j++) {
					if (!visited[edges[now_index][j]]) {
						q.push(edges[now_index][j]);
						visited[edges[now_index][j]] = true;
					}
				}
			}

		}

	}
	cout << answer;
}