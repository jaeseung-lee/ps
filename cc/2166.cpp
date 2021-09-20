#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

#define endl '\n'
#define ll long long

int N;
pair<int, int> points[10000];

void input();
void solve();
ll sum = 0;

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
		ll a, b;
		cin >> a >> b;
		points[i] = make_pair(a, b);
	}
}

void solve() {
	ll x = points[0].first;
	ll y = points[0].second;
	for (int i = 1; i < N - 1; i++) {
		ll x1 = points[i].first;
		ll y1 = points[i].second;
		ll x2 = points[i + 1].first;
		ll y2 = points[i + 1].second;

		ll ax = x1 - x;
		ll ay = y1 - y;
		ll bx = x2 - x;
		ll by = y2 - y;
		sum += ax*by - ay * bx;
	}
	cout << fixed;
	cout.precision(1);
	sum = abs(sum);
	cout << (double)(sum) / 2.0;

}

