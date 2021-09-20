#include <iostream>

using namespace std;

#define endl '\n'

int X1, Y1, X2, Y2, X3, Y3;

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
	cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
}

void solve() {
	int ax = X2 - X1;
	int ay = Y2 - Y1;
	int bx = X3 - X2;
	int by = Y3 - Y2;

	int value = ax * by - bx * ay;
	if (value == 0) {
		cout << "0" << endl;
	}
	else if (value > 0) {
		cout << "1" << endl;
	}
	else {
		cout << "-1" << endl;
	}
}