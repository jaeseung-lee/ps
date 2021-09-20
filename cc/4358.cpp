#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

#define endl '\n'

unordered_map<string, int> UnorderedMap;
map<string, int> Map;
void input();
void solve();
int cnt = 0;

int main() {
	//ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	string buffer;
	while (getline(cin,buffer)) {
		//getline(cin, buffer);
		map<string, int>::iterator it = Map.find(buffer);
		if (it == Map.end()) {
			Map.insert({ buffer,1 });
		}
		else {
			Map[buffer]++;
		}
		cnt++;
		//cout << cnt << endl;
	}
	//cout << cnt << endl;
}
void solve() {
	cout.setf(ios::fixed);
	cout.precision(4);
	map<string, int>::iterator it = Map.begin();
	for (it; it != Map.end(); ++it) {
		cout << (*it).first << " " << (*it).second*(double)100 /cnt << endl;
	}
}

