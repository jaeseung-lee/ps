#include <iostream>

using namespace std;

#define MAX 11
#define endl '\n'

int a[MAX];
int target_num;
int target[11];
void solve();
void boundary();
void fill_up();


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> target_num;
	for (int i = 0; i < target_num; i++) {
		cin >> target[i];
	}
	solve();

	for (int i = 0; i < target_num; i++) {
		cout << a[target[i]] << endl;
	}
	return 0;
}

void solve() {
	boundary();
	fill_up();
}

void boundary() {
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;
}

void fill_up() {
	for (int i = 4; i < 11; i++) {
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	}
}