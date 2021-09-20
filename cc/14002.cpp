#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 1000

int N;
int A[MAX + 1];
int dp[MAX + 1];

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
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		int best = 0;
		for (int j = 1; j < i; j++) {
			if (A[j]<A[i] && dp[j] > best) {
				best = dp[j];
			}
		}
		dp[i] = best + 1;
	}

	int answer = 0;
	int max_index = N;
	for (int i = 1; i <= N; i++) {
		//cout << "i : " << dp[i] << endl;
		if (answer < dp[i]) {
			answer = dp[i];
			max_index = i;
		}
	}
	cout << answer << endl;

	bool choosed[1001] = { false, };
	choosed[max_index] = true;
	while (max_index >= 1) {
		int now = 0;
		for (int i = 0; i <= max_index; i++) {
			if (dp[now] < dp[i] && A[i] < A[max_index]) {
				now = i;
			}
		}
		max_index = now ;
		choosed[now] = true;
		//cout << "max_index : " << max_index << endl;
	}
	for (int i = 1; i <= N; i++) {
		if (choosed[i]) {
			cout << A[i] << " ";
		}
	}
}