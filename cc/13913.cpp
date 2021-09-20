#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#define endl '\n'

int N, K;
int Spot[100000 + 1];
int Prev[100000 + 1];

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
	cin >> N >> K;
}

void solve() {
	for (int i = 0; i <= 100000; i++) {
		Spot[i] = -1;
		Prev[i] = -1;
	}
	queue<int> q;
	q.push(N);
	Spot[N] = 0;
	Prev[N] = -2;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int value = Spot[now];
		if (now + 1 <= 100000) {
			if (Spot[now + 1] == -1) {
				Spot[now + 1] = value + 1;
				q.push(now + 1);
				Prev[now + 1] = now;
			}
		}  

		if (now - 1 >= 0) {
			if (Spot[now - 1] == -1) {
				Spot[now - 1] = value + 1;
				q.push(now - 1);
				Prev[now - 1] = now;
			}
		}

		if (2 * now <= 100000 && 2 * now >= 0) {
			if (Spot[2*now] == -1) {
				Spot[2 * now] = value + 1;
				q.push(2 * now);
				Prev[2*now] = now;
			}
		}
	}
	cout << Spot[K] << endl;
	
	stack<int> stk;
	//stk.push(K);
	q.push(K);
	while (true) {
		int now = q.front();
		q.pop();
		if (now == N) {
			break;
		}
		q.push(Prev[now]);
		stk.push(now);
	}
	stk.push(N);
	while (!stk.empty()) {
		cout << stk.top() << " ";
		stk.pop();
	}
	
}