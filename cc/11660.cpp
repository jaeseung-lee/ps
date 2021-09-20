#include <iostream>

using namespace std;

#define endl '\n'

int N, M;
int Board[1025][1025];
int S[1025][1025];
pair<pair<int, int>, pair<int, int>> TestCases[100000];

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
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Board[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		TestCases[i] = make_pair(make_pair(a, b), make_pair(c, d));
	}
}

void solve() {
	int value = Board[1][1];
	S[1][1] = value;
	for (int i = 2; i <= N; i++) {
		S[1][i] = S[1][i - 1] + Board[1][i];
		S[i][1] = S[i - 1][1] + Board[i][1];
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + Board[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int a = TestCases[i].first.first;
		int b = TestCases[i].first.second;
		int c = TestCases[i].second.first;
		int d = TestCases[i].second.second;

		int value = S[c][d] - S[a - 1][d] - S[c][b - 1] + S[a - 1][b - 1];
		cout << value << endl;
	}
}