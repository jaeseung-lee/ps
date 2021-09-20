#include <iostream>

using namespace std;

#define MAX 1000
#define endl '\n'

void input();
void solve();

char first[MAX+1];
char second[MAX+1];

int answer = 0;

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
	cin >> first;
	cin >> second;
}

void solve() {
	int first_index = 0;
	int second_index = 0;

	while (first[first_index] != '\0' && second[second_index] != '\0') {
		//cout << "first : " << first[first_index] << " second : " << second[second_index] << endl;
		if (first[first_index] == second[second_index]) {
			answer++;
			first_index++;
		}
		second_index++;
	}

	if (first[first_index] != '\0') {
		for (first_index; first[first_index] != '\0'; first_index++) {
			if (first[first_index] == second[second_index - 1]) {
				answer++;
				break;
			}
		}
	}
}
