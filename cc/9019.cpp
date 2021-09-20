#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

#define endl '\n'
#define mod 10000

int T;
vector<pair<int, int>> testcases;
pair<char, int> visited[10000];

void input();
void solve();
int D(int target);
int S(int target);
int L(int target);
int R(int target);

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
		int a, b;
		cin >> a >> b;
		testcases.push_back(make_pair(a, b));
	}
}

void solve() {
	for (int t = 0; t < T; t++) {
		for (int i = 0; i < 10000; i++) {
			visited[i] = make_pair('X', -1);
		}
		int a = testcases[t].first;
		int b = testcases[t].second;
		visited[a] = make_pair('X', 10000);

		queue<int> q;
		q.push(a);

		while (!q.empty()) {
			int source = q.front();
			int target;
			q.pop();

			target = D(source);
			if (visited[target].second == -1) {
				visited[target].second = source;
				visited[target].first = 'D';
				if (target == b) {
					break;
				}
				q.push(target);
				//cout << "target : "<< target <<" pushed : " << visited[target].first << " " << visited[target].second << endl;
			}

			target = S(source);
			if (visited[target].second == -1) {
				visited[target].second = source;
				visited[target].first = 'S';
				if (target == b) {
					break;
				}
				q.push(target);
				//cout << "target : " << target << " pushed : " << visited[target].first << " " << visited[target].second << endl;
			}

			target = L(source);
			if (visited[target].second == -1) {
				visited[target].second = source;
				visited[target].first = 'L';
				if (target == b) {
					break;
				}
				q.push(target);
				//cout << "target : " << target << " pushed : " << visited[target].first << " " << visited[target].second << endl;
			}

			target = R(source);
			if (visited[target].second == -1) {
				visited[target].second = source;
				visited[target].first = 'R';
				if (target == b) {
					break;
				}
				q.push(target);
				//cout << "target : " << target << " pushed : " << visited[target].first << " " << visited[target].second << endl;
			}
		}

		stack<char> answer_stack;
		int target = b;
		while (true) {
			//cout << "target : " << target << endl;
			answer_stack.push(visited[target].first);
			target = visited[target].second;
			if (target == a) {
				break;
			}
		}

		while (!answer_stack.empty()) {
			cout << answer_stack.top();
			answer_stack.pop();
		}
		cout << endl;
		/*
		for (auto element : visited) {
			if (element.second != -1) {

			cout << element.first << " " << element.second << endl;
			}
		}
		cout << endl;
		*/
		
	}
}

int D(int target) {
	target = target * 2;
	if (target >= mod) {
		target = target - mod;
	}
	return target;
}

int S(int target) {
	target--;
	if (target == -1) {
		target = 9999;
	}
	return target;
}

int L(int target) {
	int d1 = target / 1000;
	target = target - d1 * 1000;
	int d2 = target / 100;
	target = target - d2 * 100;
	int d3 = target / 10;
	target = target - d3 * 10;
	int d4 = target;
	return ((d2 * 10 + d3) * 10 + d4) * 10 + d1;
}

int R(int target) {
	int d1 = target / 1000;
	target = target - d1 * 1000;
	int d2 = target / 100;
	target = target - d2 * 100;
	int d3 = target / 10;
	target = target - d3 * 10;
	int d4 = target;
	return ((d4 * 10 + d1) * 10 + d2) * 10 + d3;
}
