#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define endl '\n'

int N;
vector<int> edges[100000 + 1];
int target[100000];

void input();
void solve();
bool is_closed[100000 + 1];
int parent[100000 + 1];
void fill_parent(int now_index,int prev_index);

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
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		cin >> target[i];
	}
}

void solve() {
	//who's my parent?
	parent[1] = 1;
	fill_parent(1,1);

	memset(is_closed, false, sizeof(is_closed));
	stack<int> stk;
	stk.push(1);
	if (target[0] != 1) {
		cout << "0";
		exit(0);
	}

	for (int i = 1; i < N; i++) {
		int now = target[i];
		if (stk.top() == now) {
			stk.push(now);
		}
		else {
			if (is_closed[parent[now]]) {
				cout << "0";
				exit(0);
			}
			else {
				while (!stk.empty()) {
					if (stk.top() != parent[now]) {
						is_closed[stk.top()] = true;
						stk.pop();
					}
					else {
						stk.push(now);
						break;
					}
				}
				if (stk.empty()) {
					cout << "0";
					exit(0);
				}
			}
		}
	}
	cout << "1";
}

void fill_parent(int now_index,int prev_index) {
		for (int i = 0; i < edges[now_index].size(); i++) {
			if (edges[now_index][i] != prev_index) {
				parent[edges[now_index][i]] = now_index;
				fill_parent(edges[now_index][i],now_index);
			}
		}
}