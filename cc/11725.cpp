#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int V;
vector<int> edges[100001];
int parent[100001];
void input();
void solve();
void dfs(int now_index,int parent_index);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> V;
	for (int i = 0; i < V - 1; i++) {
		int s, d, w;
		cin >> s >> d;
		edges[s].push_back(d);
		edges[d].push_back(s);
	}
}

void solve() {
	for (int i = 2; i <= V; i++) {
		parent[i] = 0;
	}
	parent[1] = 1;
	dfs(1,1);
	for (int i = 2; i <= V; i++) {
		cout << parent[i] << endl;
	}
}

void dfs(int now_index, int parent_index) {
	for (int i = 0; i < edges[now_index].size(); i++) {
		int next = edges[now_index][i];
		if (parent[next] == 0) {
			parent[next] = now_index;
			dfs(next, now_index);
		}
	}
}