#include <iostream>

using namespace std;

#define endl '\n'

int n;
int postorder[100001];
int inorder[100001];
int inorder_index[100001];

void input();
void solve();
void dfs(int start_index, int numbers);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
		inorder_index[inorder[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}
}

void solve() {
	dfs(0, n);
}

void dfs(int start_index, int numbers) {
	//cout << "start_index : " << start_index << " numbers : " << numbers << endl;
	
	if (numbers <= 0) {
		return;
	}

	if (numbers == 1) {
		//cout << "start_index : " << start_index << endl;
		cout << postorder[start_index] << " ";
		return;
	}
	/*
	for (int i = 0; i < numbers; i++) {
		cout << postorder[start_index + i] << " ";
	}
	cout << endl;
	*/

	int how_many = 0;
	while (numbers-2-how_many>=0) {
		if (inorder_index[postorder[start_index + numbers - 2 - how_many]] > inorder_index[postorder[start_index + numbers - 1]]) {
			how_many++;
		}
		else {
			break;
		}
	}

	dfs(start_index + numbers - 1, 1);

	dfs(start_index, numbers - how_many - 1);

	dfs(start_index + numbers - how_many - 1, how_many);
}