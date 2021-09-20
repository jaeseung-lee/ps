#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int N;
vector<int> a(1001);
vector<int> p(1000);
void input();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
	cout << a[N];

	return 0;
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
}

void solve() {
	a[0] = 0;
	for (int i = 1; i <= N; i++) {
		int temp = 9876543210;
		for (int k = 0; k < i; k++) {
			if (temp > a[k] + p[i - k - 1]) {
				temp = a[k] + p[i - k - 1];
			}
		}
		a[i] = temp;
	}
}