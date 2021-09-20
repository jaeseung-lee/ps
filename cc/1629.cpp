#include <iostream>

using namespace std;

#define endl '\n'
#define ll long long

ll A, C;
int B;
void input();
void solve();
ll divide(int n);

ll power[32];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> A >> B >> C;
}

/*
void solve() {
	ll value = 1;
	for (int i = 0; i < 31; i++) {
		power[i] = (value*A) % C;
	}

	bool is_contained[32] = { false, };
	int k = 0;
	int temp = (int)B;
	while ((int)B > (1 << k)) {
		if ((temp & 1)==1) {
			is_contained[k] = true;
		}
		temp = temp >> 1;
		k++;
	}

	ll answer = 1;
	for (int i = 0; i < 32; i++) {
		if (is_contained[i]) {
			answer = answer * power[i];
			answer = answer % C;
		}
	}
	cout << answer;
}
*/

void solve() {
	ll answer = divide(B);
	cout << answer;
}

ll divide(int n) {
	if (n == 0) {
		return 1;
	}

	ll value = divide(n / 2);
	if (n % 2 == 0) {
		return (value * value)%C;
	} else {
		return ((value * value)%C) * A%C;
	}
}