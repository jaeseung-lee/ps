#include <iostream>

using namespace std;

#define endl '\n'

int n, m;
double dp[101][101];

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
	cin >> n >> m;
}

void solve() {
	for (int i = 1; i <= n; i++) {
		dp[n][0] = 1.0;
	}
}