#include <iostream>

using namespace std;

#define endl '\n'

int N;
int Board[16][16];
int dp[16][16][3];

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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Board[i][j];
		}
	}
}

void solve() {
	//boundary
	for (int i = 0; i < N; i++) {
		if (Board[0][i] == 0) {
			dp[0][i][0] = 1;
		}
		else {
			break;
		}
	}
	
	for (int i = 1; i < N; i++) {
		for (int j = 2; j < N; j++) {
			if (Board[i][j] == 1) {
				continue;
			}
			else {
				dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
				dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
				if (Board[i][j - 1] == 0 && Board[i - 1][j] == 0) {
					dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
				}
			}
		}
	}
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << dp[i][j][0] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << dp[i][j][1] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << dp[i][j][2] << " ";
		}
		cout << endl;
	}
	*/
	cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
	
}