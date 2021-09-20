#include <iostream>

using namespace std;

#define endl '\n'
#define MAX 1000001

int a[MAX];
int target;

int min3(int a, int b, int c);
int min2(int a, int b);
void solve();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> target;
	solve();
	cout << a[target];

	return 0;
}

int min3(int a, int b, int c){
	if (a < b) {
		if (a < c) {
			return a;
		}
		else {
			return c;
		}
	}
	else {
		if (b < c) {
			return b;
		}
		else {
			return c;
		}
	}
}
int min2(int a, int b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}

void solve() {
	a[1] = 0;
	for (int i = 2; i <= target; i++) {
		//cout << i << endl;
		if (i % 3 == 0) {
			if (i % 2 == 0) {
				a[i] = min3(a[i / 3], a[i / 2], a[i - 1]) + 1;
			}
			else {
				a[i] = min2(a[i / 3], a[i - 1]) + 1;
			}
		}
		else {
			if (i % 2 == 0) {
				a[i] = min2(a[i / 2], a[i - 1]) + 1;
			}
			else {
				a[i] = a[i - 1] + 1;
			}
		}
	}
}