#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int n, m;

struct operation {
	bool op;
	int a;
	int b;
};

vector<operation> ops;
int A[1000001];

void input();
void solve();
operation make_op(bool _op, int _a, int _b);
int find_root(int index);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		bool _op;
		int _a;
		int _b;
		cin >> _op >> _a >> _b;
		ops.push_back(make_op(_op, _a, _b));
	}

	//init A
	for (int i = 0; i <= n; i++) {
		A[i] = i;
	}
}

void solve() {
	for (int i = 0; i < m; i++) {
		bool now_op = ops[i].op;
		int now_a = ops[i].a;
		int now_b = ops[i].b;

		// 교집합
		if (now_op) {
			if (find_root(now_a) == find_root(now_b)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		} // 합집합
		else {
			int root_a = find_root(now_a);
			int root_b = find_root(now_b);

			if (root_a > root_b) {
				A[root_b] = root_a;
			}
			else {
				A[root_a] = root_b;
			}
		}
	}
}

operation make_op(bool _op, int _a, int _b) {
	operation result;
	result.op = _op;
	result.a = _a;
	result.b = _b;
	return result;
}

int find_root(int index) {
	if (A[index] == index) {
		return index;
	}
	else {
		return A[index] = find_root(A[index]);
	}
}
