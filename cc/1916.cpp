#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'

int N;
int M;
vector<vector<pair<int, int>>> map(1001);
int S;
int D;

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
		int s, d, w;
		cin >> s >> d >> w;
		map[s].push_back(make_pair(w, d));
	}
	cin >> S >> D;
}

void solve() {
	int INF = 987654321;
	priority_queue<pair<int, int>> pq;
	vector<int> dist(N+1,INF);
	dist[S] = 0;
	
	pq.push(make_pair(0, S));

	int cur = S;
	while (pq.size() > 0) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) {
			continue;
		}
		
		for (int i = 0; i < map[here].size(); i++) {
			int next_vertex = map[here][i].second;
			int new_distance = cost + map[here][i].first;
			if (dist[next_vertex] > new_distance) {
				dist[next_vertex] = new_distance;
				pq.push(make_pair(-new_distance, next_vertex));
			}
		}
	}
	cout << dist[D];
}