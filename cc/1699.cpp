#include <iostream>

using namespace std;

#define endl '\n'
#define max 100000
#define INF 987654321

int N;
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
	cin >> N;
}

void solve() {
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = INF;
		for (int j = 1; j*j <=i; j++) {
			int j_square = j * j;
			if (i > j_square) {
				if (dp[i] > dp[j_square] + dp[i-j_square]) {
					dp[i] = dp[j_square] + dp[i - j_square];
				}
			}
			else {
				dp[i] = 1;
			}
		}
		//cout << "dp[" << i << "] : " << dp[i] << endl;
	}
	cout << dp[N];
}