#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class cal {
private:
	int size;
	vector<int> col;

public :
	cal(int newsize) {
		size = newsize + 1;
		answer = 0;
		col = vector<int>(size);
	}
	bool promising(int index);
	void test();
	void queen(int index);
	int answer;
};

int main() {
	int size;
	cin >> size;
	cal test(size);
	test.test();
	cout << test.answer << endl;

	return 0;
}

void cal::test() {
	if (size == 2){
		answer = 1;
		return;
	}
	for (int index = 1; index < size; index++) {
		col[1] = index;
		queen(2);
	}

}

void cal::queen(int index) {
	for (int i = 1; i < size; i++) {
		col[index] = i;
		if (!promising(index)) { continue; }

		if (index == size - 1) {
			answer++;
			return;
		}
		queen(index + 1);
	}
}

bool cal::promising(int index) {
	for (int i = 1; i < index; i++) {
		if (col[i] == col[index] || abs(index - i) == abs(col[index] - col[i])) {
			return false;
		}
	}
	return true;
}