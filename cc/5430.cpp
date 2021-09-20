#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define endl '\n'

int T;
vector<deque<string>> X;
vector<vector<char>> P;

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
	cin >> T;
	getchar();
	for (int i = 0; i < T; i++) {
		vector<char> P_t;
		while (true) {
			char p = getchar();
			if (p != '\n') {
				P_t.push_back(p);
			}
			else {
				break;
			}
		}
		P.push_back(P_t);

		int n;
		cin >> n;
		getchar(); // \n
		getchar(); // [
		
		deque<string> X_t;
		for (int j = 0; j < n - 1; j++) {
			string temp;
			getline(cin, temp, ',');
			X_t.push_back(temp);
		}
		string temp;
		getline(cin, temp, ']');
		if (n > 0) {
			X_t.push_back(temp);
		}
		else {
			X_t.push_back("0");
		}

		getchar(); //getline buffer flush
		X.push_back(X_t);
	}
}

void solve() {
	for (int i = 0; i < T; i++) {
		int status = 1;
		int left = X[i].size();
		//cout << "left :" << left << endl;
		bool is_error = false;
		if (left == 1 && X[i][0] == "0") {
			X[i].pop_front();
			left--;
		}
		for (int j = 0; j < P[i].size(); j++) {
			if (P[i][j] == 'R') {
				status = -status;
			}
			else {
				left--;
				if (left < 0) {
					is_error = true;
					break;
				}
				else {
					if (status == 1) {
						X[i].pop_front();
					}
					else {
						X[i].pop_back();
					}
				}
			}
		}

		//출력
		if (is_error) {
			cout << "error" << endl;
		}
		else if (X[i].size()==0) {
			cout << "[]" << endl;
		} else {
			cout << "[";
			if (status == 1) {
				//앞에서부터 출력
				int j;
				for (j = 0; j < X[i].size() - 1; j++) {
					cout << X[i][j] << ",";
				}
				cout << X[i][j];
			}
			else {
				//뒤에서부터 출력
				int j;
				for (j = X[i].size() - 1; j > 0; j--) {
					cout << X[i][j] << ",";
				}
				cout << X[i][j];
			}
			cout << "]" << endl;
		}
	}
}
