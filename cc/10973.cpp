#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define endl '\n'

int N;
vector<int> target;

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
	for (int i = 0; i < N; i++) {
		target.push_back(i+1);
	}
}

void solve() {
	do {
		for (int i = 0; i < N; i++) {
			cout << target[i] << " ";
		}
		cout << endl;
	} while (next_permutation(target.begin(), target.end()));
}