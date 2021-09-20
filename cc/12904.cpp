#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

vector<char> S;
vector<char> T;

void input();
void solve();

int main() {
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	while (true) {
		char temp = getchar();
		if (temp == '\n') {
			break;
		}
		else {
			S.push_back(temp);
		}
	}
	while (true) {
		char temp = getchar();
		if (temp == '\n') {
			break;
		}
		else {
			T.push_back(temp);
		}
	}
}

void solve() {
	int T_front = 0;
	int T_back = T.size() - 1;
	bool is_reversed = false;
	bool is_answer = true;
	while (true) {
		if ((T_back - T_front) == S.size() - 1) {
			break;
		}

		if (is_reversed) {
			if (T[T_front] == 'A') {
				T_front++;
			}
			else {
				T_front++;
				is_reversed = is_reversed ^ true;
			}
		}
		else {
			if (T[T_back] == 'A') {
				T_back--;
			}
			else {
				T_back--;
				is_reversed = is_reversed ^ true;
			}
		}
	}

	if (is_reversed) {
		for (int i = 0; i < S.size() - 1; i++) {
			if (S[i] != T[T_back - i]) {
				is_answer = false;
				break;
			}
		}
	}
	else {
		for (int i = 0; i < S.size() - 1; i++) {
			if (S[i] != T[T_front + i]) {
				is_answer = false;
				break;
			}
		}
	}

	if (is_answer) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
}