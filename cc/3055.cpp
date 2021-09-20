#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define INF 987654321

int R, C;
char board[51][51];
int obj_board[50][50];
int water_board[50][50];
bool main_board[50][50];
vector<pair<int, int>> water_spots;

bool visited[50][50];

int dir_y[4] = { 1,-1,0,0 };
int dir_x[4] = { 0,0,1,-1 };

//고슴도치 첫 위치
int s_y;
int s_x;

struct node {
	int y;
	int x;
	int now;
};

void input();
void solve();
void fill_obj_board();
void fill_water_board();
void fill_main_board();
void init_visited();
node make_node(int new_y, int new_x, int new_now);
bool is_valid_index(int y, int x);
bool is_four_direction_water(int y, int x);
bool is_water(int y, int x);

void display_obj();
void display_water();

int main() {
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
	return 0;
}

void input() {
	cin >> R >> C;
	getchar();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			board[i][j] = getchar();
			if (board[i][j] == 'S') {
				s_y = i;
				s_x = j;
			}
			else if (board[i][j] == '*') {
				water_spots.push_back(make_pair(i, j));
			}
			//cout << "board[" << i << "][" << j << "] : " << board[i][j] << endl;
		}
		getchar();
	}
}

void solve() {
	//파랑찾고
	fill_obj_board();
	//display_obj();

	//빨강찾고
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			water_board[i][j] = INF;
		}
	}
	if (!water_spots.empty()) {
	fill_water_board();
	//display_water();
	}

	//판만들고
	fill_main_board();

	//최단경로 탐색
	init_visited();
	queue<node> q;
	visited[s_y][s_x] = true;
	q.push(make_node(s_y,s_x,0));

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int now = q.front().now;
		
		if (board[y][x] == 'D') {
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (is_valid_index(y + dir_y[i], x + dir_x[i]) && !visited[y + dir_y[i]][x + dir_x[i]] && main_board[y + dir_y[i]][x + dir_x[i]]){
				q.push(make_node(y + dir_y[i], x + dir_x[i], now + 1));
				visited[y + dir_y[i]][x + dir_x[i]] = true;
			}
		}
	}

	if (q.empty()) {
		cout << "KAKTUS";
	}
	else {
		cout << q.front().now;
	}
} 


bool is_valid_index(int y, int x) {
	return y >= 0 && y < R && x >= 0 && x < C;
}

bool is_four_direction_water(int y, int x) {
	for (int i = 0; i < 4; i++) {
		if (is_valid_index(y + dir_y[i], x + dir_x[i]) && is_water(y + dir_y[i], x + dir_x[i])) {
			return true;
		}
	}
	return false;
}

node make_node(int new_y, int new_x, int new_now) {
	node output;
	output.x = new_x;
	output.y = new_y;
	output.now = new_now;
	return output;
}

bool is_water(int y, int x) {
	return board[y][x] == '*';
}

void init_visited() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			visited[i][j] = false;
		}
	}
}

void fill_obj_board(){
	init_visited();
	queue<node> q;
	visited[s_y][s_x] = true;
	q.push(make_node(s_y, s_x, 0));

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int now = q.front().now;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (is_valid_index(y + dir_y[i], x + dir_x[i]) && !visited[y + dir_y[i]][x + dir_x[i]] && (board[y + dir_y[i]][x + dir_x[i]]=='.' || board[y + dir_y[i]][x + dir_x[i]] == 'D')) {
				obj_board[y + dir_y[i]][x + dir_x[i]] = now + 1;
				q.push(make_node(y + dir_y[i], x + dir_x[i], now + 1));
				visited[y + dir_y[i]][x + dir_x[i]] = true;
			}
		}
	}
}

void fill_water_board(){
	init_visited();

	queue<node> q;
	for (int i = 0; i < water_spots.size(); i++) {
		visited[water_spots[i].first][water_spots[i].second] = true;
		water_board[water_spots[i].first][water_spots[i].second] = 0;
		q.push(make_node(water_spots[i].first, water_spots[i].second, 0));
	}

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int now = q.front().now;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (is_valid_index(y + dir_y[i], x + dir_x[i]) && !visited[y + dir_y[i]][x + dir_x[i]] && board[y + dir_y[i]][x + dir_x[i]] == '.' ) {
				water_board[y + dir_y[i]][x + dir_x[i]] = now + 1;
				q.push(make_node(y + dir_y[i], x + dir_x[i], now + 1));
				visited[y + dir_y[i]][x + dir_x[i]] = true;
			}
		}
	}
}
void fill_main_board(){
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'X') {
				main_board[i][j] = false;
			}
			else if (board[i][j] == 'D') {
				main_board[i][j] = true;
			} else if (obj_board[i][j] < water_board[i][j]) {
				main_board[i][j] = true;
			}
			else {
				main_board[i][j] = false;
			}
		}
	}
	
	/*
	cout << "main board : " << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (main_board[i][j]) {
				cout << "1" << " ";
			}
			else {
				cout << "0 ";
			}
		}
		cout << endl;
	}
	*/
}

void display_obj() {
	cout << "obj_board : " << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << obj_board[i][j] << " ";
		}
		cout << endl;
	}
} 

void display_water() {
	cout << "water_board : " << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << water_board[i][j] << " ";
		}
		cout << endl;
	}
}