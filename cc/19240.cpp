#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int T;
vector<int> Ns;
vector<int> Ms;
vector<vector<pair<int, int>>> rivals;
int pushed[300000];
int buffer[300000+1];

void input();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();

	return 0;
}

void input() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;
		Ns.push_back(N);
		Ms.push_back(M);
		vector<pair<int, int>> temp_rivals;
		for (int j = 0; j < M; j++) {
			int a, b;
			cin >> a >> b;
			temp_rivals.push_back(make_pair(a, b));
		}
		rivals.push_back(temp_rivals);
	}
}

void solve() {
	for (int t_i = 0; t_i < T; t_i++) {
		for (int i = 0; i < 300000; i++) {
			pushed[i] = 0;
			buffer[i] = 0;
		}
		bool is_answer = true;
		for (int i = 0; i < Ms[t_i]; i++) {
			/*
			cout << "rivals[t_i][i].first : " << rivals[t_i][i].first << endl;
			cout << "rivals[t_i][i].second : " << rivals[t_i][i].second << endl;
			cout << "pushed[rivals[t_i][i].first] : " << pushed[rivals[t_i][i].first] << endl;
			cout << "pushed[rivals[t_i][i].second] : " << pushed[rivals[t_i][i].second] << endl;
			*/
			if (pushed[rivals[t_i][i].first] == 0) {
				if (pushed[rivals[t_i][i].second] == 0) {
					//바로 넣지 말고 buffer를 확인해야한다.
					//그리고 쌍으로 넣기
					if (buffer[rivals[t_i][i].first] == 0 && buffer[rivals[t_i][i].second] == 0) {
						buffer[rivals[t_i][i].first] = rivals[t_i][i].second;
						buffer[rivals[t_i][i].second] = rivals[t_i][i].first;
					}
					else {
						if (buffer[rivals[t_i][i].first] != 0 && buffer[rivals[t_i][i].second] == 0) {
							pushed[rivals[t_i][i].first] = 1;
							pushed[buffer[rivals[t_i][i].first]] = 2;
							pushed[rivals[t_i][i].second] = 2;
							buffer[rivals[t_i][i].first] = 0;
						}
						else if (buffer[rivals[t_i][i].second] != 0 && buffer[rivals[t_i][i].first] == 0){
							pushed[rivals[t_i][i].second] = 1;
							pushed[buffer[rivals[t_i][i].second]] = 2;
							pushed[rivals[t_i][i].first] = 2;
							buffer[rivals[t_i][i].second] = 0;
						} else{
							pushed[rivals[t_i][i].first] = 1;
							pushed[rivals[t_i][i].second] = 2;
							pushed[buffer[rivals[t_i][i].first]] = 2;
							pushed[buffer[rivals[t_i][i].second]] = 1;
							buffer[rivals[t_i][i].first] = 0;
							buffer[rivals[t_i][i].second] = 0;
						}
					}
				}
				else if (pushed[rivals[t_i][i].second] == 1) {
					pushed[rivals[t_i][i].first] = 2;
					if (buffer[rivals[t_i][i].first] != 0) {
						pushed[buffer[rivals[t_i][i].first]] = 1;
						buffer[rivals[t_i][i].first] = 0;
					}
				}
				else {
					pushed[rivals[t_i][i].first] = 1;
					if (buffer[rivals[t_i][i].first] != 0) {
						pushed[buffer[rivals[t_i][i].first]] = 2;
						buffer[rivals[t_i][i].first] = 0;
					}
				}
			}
			else if (pushed[rivals[t_i][i].first] == 1) {
				if (pushed[rivals[t_i][i].second] == 0) {
					pushed[rivals[t_i][i].second] = 2;
					if (buffer[rivals[t_i][i].second] != 0) {
						pushed[buffer[rivals[t_i][i].second]] = 1;
						buffer[rivals[t_i][i].second] = 0;
					}
				}
				else if (pushed[rivals[t_i][i].second] == 1) {
					is_answer = false;
					break;
				}
				else {
					continue;
				}
			}
			else {
				if (pushed[rivals[t_i][i].second] == 0) {
					pushed[rivals[t_i][i].second] = 1;
					if (buffer[rivals[t_i][i].second] != 0) {
						pushed[buffer[rivals[t_i][i].second]] = 2;
						buffer[rivals[t_i][i].second] = 0;
					}
				}
				else if (pushed[rivals[t_i][i].second] == 1) {
					continue;
				}
				else {
					is_answer = false;
					break;
				}
			}
		}

		if (is_answer) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

}