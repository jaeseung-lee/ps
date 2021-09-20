#include <iostream>

using namespace std;

int N, S;
int A[20];
bool is_contained[20] = { false, };
int answer = 0;

void input();
void solve();
void dfs(int now_index);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
}

void solve() {
	if (S == 0) {
		answer = -1;
	}
	dfs(0);
	cout << answer;
}

void dfs(int now_index) {
	if (now_index == N) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			if (is_contained[i]) {
				temp += A[i];
			}
		}
		if (temp == S) {
			answer++;
		}
		return;
	}

	is_contained[now_index] = true;
	dfs(now_index + 1);
	is_contained[now_index] = false;
	dfs(now_index + 1);

	return;
}