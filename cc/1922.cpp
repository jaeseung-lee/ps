#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int M;
vector<pair<int, int>> edge[1001];
priority_queue<pair<int,pair<int, int>>> pq;
int answer = 0;

void input();
void solve();

//union-find
int parent[1001];
int find(int target_index);
void merge(int source, int target);

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
		int a, b, c;
		cin >> a >> b >> c;
		pq.push(make_pair(-c, make_pair(a, b)));
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	while (!pq.empty()) {
		int weight = -pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();
		if (find(a) != find(b)) {
			merge(a, b);
			answer += weight;
		}
	}
	cout << answer << endl;
}

int find(int target_index) {
	int parent_index = parent[target_index];
	if (parent_index == target_index) {
		return target_index;
	}
	else {
		return parent_index = find(parent_index);
	}
}
void merge(int source, int target) {
	int source_parent = find(source);
	int target_parent = find(target);
	if (source_parent == target_parent) {
		return;
	}
	else {
		if (source_parent > target_parent) {
			parent[target_parent] = source_parent;
		}
		else {
			parent[source_parent] = target_parent;
		}
	}
}