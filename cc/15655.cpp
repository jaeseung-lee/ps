#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define endl '\n'

int N, M;
vector<int> numbers;
int indice[8];

void input();
void solve();
void print(int n);

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
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		numbers.push_back(a);
	}
}

void solve() {
	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < N; i++) {
		indice[0] = i;
		print(1);
	}
}

void print(int n) {
	if (n == M) {
		for (int i = 0; i < M; i++) {
			cout << numbers[indice[i]] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = indice[n-1]; i < N; i++) {
		indice[n] = i;
		print(n + 1);
	}
}