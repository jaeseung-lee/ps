#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

char wheel[5][8];
int rolling_list[5] = { 0, };

int K;
vector<pair<int, int>> actions;

void input();
void solve();
void init_rolling_list();
void fill_list(int start);
void roll_all();
void roll_wheel(int wheel_number, int direction);
bool is_valid_wheel_index(int target);
void display_wheel(int target);
bool is_right_rolls(int wheel_number);
bool is_left_rolls(int wheel_number);

int main() {
	//ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	//roll_wheel(1, -1);
	//display_wheel(1);

	solve();

	return 0;
}

void input() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			wheel[i][j] = getchar();
			//cout << "wheel[" << i << "][" << j << "] : " << wheel[i][j] << endl;
		}
		getchar();
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int n, d;
		cin >> n >> d;
		actions.push_back(make_pair(n, d));
	}
}

void solve() {
	for (int i = 0; i < K; i++) {
		init_rolling_list();
		/*
		cout << "before :" << endl;
		display_wheel(1);
		display_wheel(2);
		display_wheel(3);
		display_wheel(4);
		*/
		int target_number = actions[i].first;
		int direction = actions[i].second;

		rolling_list[target_number] = direction;
		fill_list(target_number);
		roll_all();
		/*
		cout << "after :" << endl;
		display_wheel(1);
		display_wheel(2);
		display_wheel(3);
		display_wheel(4);
		cout << endl;
		*/
	}

	int answer = 0;
	int pow_2 = 1;
	for (int i = 1; i <= 4; i++) {
		//cout << "i : " << i << endl;
		if (wheel[i][0] == '1') {
			answer = answer + pow_2;
		}
		pow_2 = pow_2 * 2;
	}
	cout << answer;
}

void init_rolling_list() {
	for (int i = 1; i <= 4; i++) {
		rolling_list[i] = 0;
	}
}

void fill_list(int start){
	int right_index = start + 1;
	while (is_valid_wheel_index(right_index)) {
		if (is_right_rolls(right_index)) {
			rolling_list[right_index] = -rolling_list[right_index - 1];
			right_index++;
			continue;
		}
		break;
	}
	int left_index = start - 1;
	while (is_valid_wheel_index(left_index)) {
		if (is_left_rolls(left_index)) {
			rolling_list[left_index] = -rolling_list[left_index + 1];
			left_index--;
			continue;
		}
		break;
	}
	
	for (int i = 1; i <= 4; i++) {
		cout << rolling_list[i] << " ";
	}
	cout << endl;
	
}

void roll_all(){
	for (int i = 1; i <= 4; i++) {
		//cout << "rolling_list[" << i << "] : " << rolling_list[i] << endl;
		if (rolling_list[i] == -1) {
			roll_wheel(i, -1);
		}
		else if (rolling_list[i] == 1) {
			roll_wheel(i, 1);
		}
		else {
			continue;
		}
	}
}

void roll_wheel(int wheel_number, int direction) {
	if (direction == -1) {
		char temp = wheel[wheel_number][0];
		for (int i = 1; i <= 7; i++) {
			wheel[wheel_number][i - 1] = wheel[wheel_number][i];
		}
		wheel[wheel_number][7] = temp;
	}
	else {
		char temp = wheel[wheel_number][7];
		for (int i = 6; i >= 0; i--) {
			wheel[wheel_number][i + 1] = wheel[wheel_number][i];
		}
		wheel[wheel_number][0] = temp;
	}
}

bool is_left_rolls(int wheel_number){
	return wheel[wheel_number][2] != wheel[wheel_number + 1][6];
}

bool is_right_rolls(int wheel_number) {
	return wheel[wheel_number - 1][2] != wheel[wheel_number][6];
}

bool is_valid_wheel_index(int target) {
	return target >= 1 && target <= 4;
}

void display_wheel(int target) {
	for (int i = 0; i < 8; i++) {
		cout << wheel[target][i] << " ";
	}
	cout << endl;
}