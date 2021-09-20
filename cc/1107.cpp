#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define endl '\n'
#define INF 987654321

bool is_broken[10] = { 0, };
int N;
int answer = INF;
int broken_num;
int digits = 0;

void solve();
void input();
bool is_promising(int target);
bool is_out_of_index(int target);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	cout << answer;

	return 0;
}

void input() {
	cin >> N;
	cin >> broken_num;
	for (int i = 0; i < broken_num; i++) {
		int ch;
		cin >> ch;
		is_broken[ch] = true;
	}
	answer = abs(N - 100);
}

void solve() {
	int now = N;
	int up_best = 0;
	while (is_promising(now)) {
		up_best++;
		now++;
		if (up_best > answer) {
			break;
		}
	}
	up_best += digits;
	//cout << "up_best : " << up_best << endl;
	if (answer > up_best) {
		answer = up_best;
	}

	int down_best = 0;
	now = N;
	while (is_promising(now)) {
		//cout << "here" << endl;
		down_best++;
		now--;
		if (down_best > answer) {
			break;
		}
		if (is_out_of_index(now)) {
			down_best = INF;
			break;
		}
	}
	down_best += digits;
	//cout << "down_best : " << down_best << endl;

	if (answer > down_best) {
		answer = down_best;
	}
}

bool is_promising(int target) {
	//cout << "target : " << target << endl;
	//각 자리가 하나라도 broken의 원소라면 false 반환
	int i = 0;
	digits = 0;
	if (target == 0) {
		digits = 1;
		if (is_broken[0]) {
			return true;
		}
		else {
			return false;
		}
	}
	while(target > 0)
	{
		digits++;
		int r = target % 10;
		//이 r이 broken이라면 true
		if (is_broken[r]) {
			return true;
		}
		target = (target - r) / 10;
	}
	return false;
}

bool is_out_of_index(int target) {
	if (target < 0) {
		return true;
	}
	return false;
}