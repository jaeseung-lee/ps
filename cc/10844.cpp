#include <iostream>

using namespace std;

#define endl '\n'
#define mod 1000000000
#define MAX 100

int dp[MAX + 1][10];

void solve();
void input();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	input();
	return 0;
}

void solve() {
	//boundary
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	dp[1][0] = 0;
	for (int n = 2; n <= MAX; n++) {
		dp[n][0] = (dp[n - 1][1])%mod;
		//cout << dp[n][0] << " ";
		for (int i = 1; i <= 8; i++) {
			dp[n][i] = (dp[n - 1][i - 1] + dp[n - 1][i + 1])%mod;
			//cout << dp[n][i] << " ";
		}
		dp[n][9] = (dp[n - 1][8])%mod;
		//cout << dp[n][9] << endl;
	}
}

void input() {
	int N;
	cin >> N;
	int answer=0;
	for (int i = 0; i <= 9; i++) {
		answer = (answer + dp[N][i])%mod;
	}
	cout << answer % mod << endl;
}