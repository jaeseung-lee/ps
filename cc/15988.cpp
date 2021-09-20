#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define mod 1000000009
#define MAX 1000000

int T;
vector<int> targets;
long long dp[4][MAX+1];

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
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		targets.push_back(n);
	}
}

void solve() {
	//boundary
	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[1][3] = 2;
	dp[2][1] = 0;
	dp[2][2] = 1;
	dp[2][3] = 1;
	dp[3][1] = 0;
	dp[3][2] = 0;
	dp[3][3] = 1;
	//fill_up
	for (int i = 4; i <= MAX; i++) {
		dp[3][i] = (dp[1][i - 3] + dp[2][i - 3] + dp[3][i - 3])%mod;
		dp[2][i] = (dp[1][i - 2] + dp[2][i - 2] + dp[3][i - 2])%mod;
		dp[1][i] = (dp[1][i - 1] + dp[2][i - 1] + dp[3][i - 1])%mod;
	}

	//display
	for (int i = 0; i < T; i++) {
		cout << (dp[1][targets[i]] + dp[2][targets[i]] + dp[3][targets[i]]) % mod << endl;
	}
}