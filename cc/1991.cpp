#include <iostream>

using namespace std;

#define endl '\n'

int N;
pair<int, int> Tree[26];

void input();
void solve();
char to_alphabet(int index);
int to_index(char alphabet);

void preorder(int now_index);
void inorder(int now_index);
void postorder(int now_index);

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
		char a, b, c;
		cin >> a >> b >> c;
		Tree[to_index(a)] = make_pair(to_index(b), to_index(c));
	}
}

void solve() {
	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);

}

char to_alphabet(int index) {
	return (char)(index + (int)'A');
}
int to_index(char alphabet) {
	return (int)alphabet - (int)'A';
}

void preorder(int now_index) {
	cout << to_alphabet(now_index);
	if (Tree[now_index].first != -19) {
		preorder(Tree[now_index].first);
	}
	if (Tree[now_index].second != -19) {
		preorder(Tree[now_index].second);
	}
}

void inorder(int now_index) {
	if (Tree[now_index].first != -19) {
		inorder(Tree[now_index].first);
	}
	cout << to_alphabet(now_index);
	if (Tree[now_index].second != -19) {
		inorder(Tree[now_index].second);
	}
}

void postorder(int now_index) {
	if (Tree[now_index].first != -19) {
		postorder(Tree[now_index].first);
	}
	if (Tree[now_index].second != -19) {
		postorder(Tree[now_index].second);
	}
	cout << to_alphabet(now_index);
}