#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, V;

bool visited[1001] = { false, };
vector<int> edges[1001];

void input();
void solve();
void dfs(int now_index);
void bfs();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> N >> M >> V;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(edges[i].begin(), edges[i].end());
	}
}

void solve() {
	visited[V] = true;
	dfs(V);
	cout << endl;
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
	visited[V] = true;
	bfs();
}

void dfs(int now_index) {
	cout << now_index << " ";
	for (int i = 0; i < edges[now_index].size(); i++){
		if (!visited[edges[now_index][i]]) {
			visited[edges[now_index][i]] = true;
			dfs(edges[now_index][i]);
		}
	}
	return;
}

void bfs() {
	queue<int> q;
	q.push(V);
	while (!q.empty()) {
		int now_index = q.front();
		cout << now_index << " ";
		q.pop();
		for (int i = 0; i < edges[now_index].size(); i++) {
			if (!visited[edges[now_index][i]]) {
				visited[edges[now_index][i]] = true;
				q.push(edges[now_index][i]);
			}
		}
	}
}