#include <iostream>

using namespace std;

#define endl '\n'
#define max 100000

int n;
int A[max + 1];
int dp[max + 1];

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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
}

void solve() {
	dp[1] = A[1];
	for (int i = 2; i <= n; i++) {
		if (dp[i - 1] < 0) {
			dp[i] = A[i];
		}
		else {
			dp[i] = A[i] + dp[i - 1];
		}
	}

	int answer = dp[1];
	for (int i = 2; i <= n; i++) {
		if (answer < dp[i]) {
			answer = dp[i];
		}
	}
	cout << answer;
}