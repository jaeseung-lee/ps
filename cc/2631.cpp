#include <iostream>

using namespace std;

#define endl '\n'

int N;
int A[201];
int dp[201];
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
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
}

void solve() {
	//boundary
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[j]<A[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	int max_dp = dp[1];
	for (int i = 2; i <= N; i++) {
		if (max_dp < dp[i]) {
			max_dp = dp[i];
		}
	}
	cout << N - max_dp;
}