#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int D;
int dice[10000][6];

void input();
void solve();

//index��°�� �ݴ��� ��ġ�� �ֻ��� index ��ȯ
int reverse(int index);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}

void input() {
	cin >> D;
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> dice[i][j];
		}
	}
}

void solve() {
	int answer = 0;
	for (int i = 0; i < 6; i++) {
		//���� ������ ���� ���ִ� �ֻ��� ����
		int floor = dice[0][i];
		int top = dice[0][reverse(i)];

		//�� �Ʒ� ���鿡�� ���� ū ����
		int value = 0;
		for (int j = 0; j < 6; j++) {
			if (j != i && j != reverse(i) && value < dice[0][j]) {
				value = dice[0][j];
			}
		}
		//cout << value << endl;


		// 1������ D-1������ ū ���� ã��
		for (int j = 1; j < D; j++) {
			// �������̶� �ֻ��� �Ȱ��� �������
			for (int k = 0; k < 6; k++) {
				if (top == dice[j][k]) {
					floor = dice[j][k];
					top = dice[j][reverse(k)];
					break;
				}
			}
			int temp = 0;
			//���鿡 ���� ū ���� ã��
			for (int k = 0; k < 6; k++) {
				if (dice[j][k] != top && dice[j][k] != floor && temp < dice[j][k]) {
					temp = dice[j][k];
				}
			}
			value += temp;
			//cout << value << endl;
		}
		//cout << endl;
		if (value > answer) {
			answer = value;
		}
	}
	cout << answer;
}

int reverse(int index) {
	switch (index) {
	case 0:
		return 5;
	case 1:
		return 3;
	case 2:
		return 4;
	case 3:
		return 1;
	case 4:
		return 2;
	case 5:
		return 0;
	}
}