#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> edges[2000];
bool visited[2000];

void input();
void solve();
void dfs(int now_index,int friend_number);

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
	for (int i = 0; i < N; i++) {
		visited[i] = true;
		dfs(i,0);
		visited[i] = false;
	}
	cout << "0";
}

void dfs(int now_index,int friend_number) {
	if (friend_number == 4) {
		cout << "1";
		exit(0);
	}

	for (int i = 0; i < edges[now_index].size(); i++) {
		if (!visited[edges[now_index][i]]) {
			visited[edges[now_index][i]] = true;
			dfs(edges[now_index][i], friend_number + 1);
			visited[edges[now_index][i]] = false;
		}
	}
}