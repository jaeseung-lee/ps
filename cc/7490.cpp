#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define endl '\n'

int N;
vector<int> targets;
char op[8];

void input();
void solve();
void fill_stack(int now, int max);
void calculate(int max);

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
		int temp;
		cin >> temp;
		targets.push_back(temp);
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		fill_stack(0, targets[i] - 1);
		cout << endl;
	}
}

void fill_stack(int now, int max) {
	if (now == max) {
		//계산수행하고 0이라면 출력
		calculate(max);
		return;
	}
	op[now] = ' ';
	fill_stack(now + 1, max);

	op[now] = '+';
	fill_stack(now + 1, max);

	op[now] = '-';
	fill_stack(now + 1, max);
}

void calculate(int max) {
	stack<int> numbers;
	stack<char> operators;
	numbers.push(1);
	for (int i = 0; i < max; i++) {
		if (operators.empty()) {
			if (op[i] == ' ') {
				int temp = numbers.top() * 10 + (i + 2);
				numbers.pop();
				numbers.push(temp);
			}
			else {
				operators.push(op[i]);
				numbers.push(i + 2);
			}
		}
		else {
			if (op[i] == ' ') {
				int temp = numbers.top() * 10 + (i + 2);
				numbers.pop();
				numbers.push(temp);
			}
			else {
				if (operators.top() == '+') {
					int r = numbers.top();
					numbers.pop();
					int l = numbers.top();
					numbers.pop();
					numbers.push(l + r);
					numbers.push(i + 2);
					operators.push(op[i]);
				}
				else {
					int r = numbers.top();
					numbers.pop();
					int l = numbers.top();
					numbers.pop();
					numbers.push(l - r);
					numbers.push(i + 2);
					operators.push(op[i]);
				}
			}
		}
	}

	if (!operators.empty()) {
		if (operators.top() == '+') {
			int r = numbers.top();
			numbers.pop();
			int l = numbers.top();
			numbers.pop();
			numbers.push(l + r);
		}
		else {
			int r = numbers.top();
			numbers.pop();
			int l = numbers.top();
			numbers.pop();
			numbers.push(l - r);
		}
	}

	if (numbers.top() == 0) {
		cout << "1";
		for (int i = 0; i < max; i++) {
			cout << op[i] << i + 2;
		}
		cout << endl;
	}
}