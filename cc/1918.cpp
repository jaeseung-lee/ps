#include <iostream>
#include <vector>
#include <stack>
#include <cctype>

using namespace std;

#define endl '\n'

vector<char> target;
void input();
void solve();

int main() {
	//ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	while (true) {
		char c = getchar();
		if (c == '\n') {
			break;
		}
		target.push_back(c);
	}
}

void solve() {
	stack<char> op;
	for (int i = 0; i < target.size(); i++) {
		if (isalpha(target[i])) {
			cout << target[i];
		}
		else {
			if (op.empty()) {
				op.push(target[i]);
			}
			else {
				if (target[i] == '(') {
					op.push(target[i]);
				}
				else if (target[i] == ')') {
					while (true) {
						if (op.top() == '(') {
							op.pop();
							break;
						}
						cout << op.top();
						op.pop();
					}
				}
				else if (target[i] == '+' || target[i] == '-') {
					 if (op.top() == '(') {
						op.push(target[i]);
					 }
					 else {
						cout << op.top();
						op.pop();
						if (!op.empty() && (op.top() == '+' || op.top() == '-')) {
							cout << op.top();
							op.pop();
						}
						op.push(target[i]);
					 }
				}
				else {
					if (op.top() == '(') {
						op.push(target[i]);
					} else if (op.top() == '+' || op.top() == '-') {
						op.push(target[i]);
					} else {
						cout << op.top();
						op.pop();
						op.push(target[i]);
					}
				}
			}
		}
	}
	while (!op.empty()) {
		cout << op.top();
		op.pop();
	}
}