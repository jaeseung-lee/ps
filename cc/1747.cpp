#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
bool numbers[10000001] = { false, };

void input();
void solve();
bool is_prime_number(int target);

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
}

void solve() {
	//한자리 a
	numbers[2] = true;
	numbers[3] = true;
	numbers[5] = true;
	numbers[7] = true;

	//두자리 aa
	numbers[11] = true;

	//aba
	for (int a = 1; a <= 9; a++) {
		for (int b = 0; b <= 9; b++) {
			if (is_prime_number(101 * a + 10*b)) {
				numbers[101 * a + 10*b] = true;
			}
		}
	}


	//abba
	for (int a = 1; a <= 9; a++) {
		for (int b = 0; b <= 9; b++) {
			if (is_prime_number(1001 * a + 110*b)) {
				numbers[1001 * a + 110*b] = true;
			}
		}
	}

	//abcba
	for (int a = 1; a <= 9; a++) {
		for (int b = 0; b <= 9; b++) {
			for (int c = 0; c <= 9; c++) {
				if (is_prime_number(10001 * a + 1010 * b + 100*c)) {
					numbers[10001 * a + 1010 * b + 100 * c] = true;
				}
			}
		}
	}

	//abccba
	for (int a = 1; a <= 9; a++) {
		for (int b = 0; b <= 9; b++) {
			for (int c = 0; c <= 9; c++) {
				if (is_prime_number(100001 * a + 10010 * b + 1100 * c)) {
					numbers[100001 * a + 10010 * b + 1100 * c] = true;
				}
			}
		}
	}

	
	/*
	for (int i = 1; i <= 1000000; i++) {
		if (numbers[i]) {
			cout << i << endl;
		}
	}
	*/
	

	
	//searching
	for (int i = N; i <= 1000000; i++) {
		if (numbers[i]) {
			cout << i;
			return;
		}
	}
	cout << 1003001;
	
}

bool is_prime_number(int target) {
	int p = sqrt(target) + 1;
	for (int i = 2; i <= p; i++) {
		if (target%i == 0) {
			return false;
		}
	}
	return true;
}