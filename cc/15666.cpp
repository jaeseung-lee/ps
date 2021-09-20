#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int N, M;
vector<int> numbers;
bool is_contained[10000 + 1] = { false, };
int indice[8];

void input();
void solve();
void print(int now_index);

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
		int temp;
		cin >> temp;
		if (!is_contained[temp]) {
			is_contained[temp] = true;
			numbers.push_back(temp);
		}
		else {
			count++;
		}
	}
	N -= count;
	sort(numbers.begin(), numbers.end());
}

void solve() {
	print(0);
}

void print(int now_index) {
	if (now_index == M) {
		for (int i = 0; i < M; i++) {
			cout << numbers[indice[i]] << " ";
		}
		cout << endl;
		return;
	}

	if (now_index == 0) {
		for (int i = 0; i < N; i++) {
			indice[0] = i;
			print(now_index + 1);
		}
	}
	else {
		for (int i = indice[now_index - 1]; i < N; i++) {
			indice[now_index] = i;
			print(now_index + 1);
		}
	
	}

}

