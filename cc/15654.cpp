#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define endl '\n'

int N, M;
vector<int> numbers;
int indice[8];
bool is_exists[10000 + 1] = { false, };

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
	int count = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (is_exists[a]) {
			count++;
			continue;
		}
		else {
			numbers.push_back(a);
			is_exists[a] = true;
		}
	}
	N = N - count;
}

void solve() {
	sort(numbers.begin(), numbers.end());
	print(0);
}

void print(int n) {
	if (n == M) {
		for (int i = 0; i < M; i++) {
			cout << numbers[indice[i]] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < N; i++) {
		indice[n] = i;
		print(n + 1);
		
	}
}