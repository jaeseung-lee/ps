#include <iostream>

using namespace std;

#define endl '\n'
#define mod 1000000000

int N, K;
long long dp[201][201];

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
	//boundary
	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}
	
	for (int k = 2; k <= K; k++) {
		for (int n = 0; n <= N; n++) {
			long long value = 0;
			for (int i = 0; i <= n; i++) {
				value = value + dp[k - 1][i];
			}
			dp[k][n] = value % mod;
		}
	}
	cout << dp[K][N];
}