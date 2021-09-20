#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int N;
int K;
vector<pair<int, int>> V;
int dp[101][100001];

void input();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	cout << dp[N][K];

	return 0;
}

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int w, v;
		cin >> w >> v;
		V.push_back(make_pair(w, v));
	}
}

void solve() {
	//boundary
	for (int i = 0; i <= K; i++) {
		dp[0][i] = 0;
	}
	for (int i = 0; i <= N; i++) {
		dp[i][N] = 0;
	}

	for (int n = 1; n <= N; n++) {
		for (int w = 1; w <= K; w++) {
			if (w - V[n - 1].first < 0) {
				dp[n][w] = dp[n - 1][w];
			}
			else {
				if (dp[n - 1][w] > dp[n - 1][w - V[n - 1].first]+V[n-1].second) {
					dp[n][w] = dp[n - 1][w];
				}
				else {
					dp[n][w] = dp[n - 1][w - V[n - 1].first] + V[n - 1].second;
				}
			}
		}
	}
}