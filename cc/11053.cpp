#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int A[1001];
int dp[1001];
int N;

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

	//fill
	for (int i = 2; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j <= i-1; j++) {
			if (A[j] < A[i]) {
				int temp = dp[j] + 1;
				if (temp > dp[i]) {
					dp[i] = temp;
				}
			}
		}
	}

	//그중에서 제일 큰 거
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		//cout << dp[i] << " ";
		if (answer < dp[i]) {
			answer = dp[i];
		}
	}

	cout << answer;
}