#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class test {
private:
	int start_vertex;
	int vertexs;
	vector<map<int, int>> graph;
	vector<int> best;
	vector<bool> is_closed;
	
public:
	test(int start_vertex, int vertexs, vector<map<int, int>> graph,vector<int> best,vector<bool> is_closed) {
		this->start_vertex = start_vertex;
		this->vertexs = vertexs;
		this->graph = graph;
		this->best = best;
		this->is_closed = is_closed;
	}
	void calculate_best();
	void fill_best(priority_queue<int, int, greater<int>> open_edge);
	void display_best();
};

int main() {
	int vertexs, edges;
	cin >> vertexs >> edges;

	vector<map<int, int>> graph;
	int INF = 200001;
	for (int i = 0; i < vertexs; i++) {
		map<int,int> temp;
		graph.push_back(temp);
	}

	vector<int> best;
	vector<bool> is_closed;
	for (int i = 0; i < vertexs + 0; i++) {
		best.push_back(INF);
		is_closed.push_back(false);
	}
	int start;
	cin >> start;
	best[start - 1] = 0;
	while (edges > 0) {
		int row, col, w;
		cin >> row >> col >> w;
		map<int, int>::iterator iter;
		iter = graph[row - 1].find(col);
		if (iter != graph[row - 1].end())
		{
			if (graph[row - 1][col - 1] > w)
				graph[row - 1][col - 1] = w;
		}
		else {
			graph[row - 1][col-1]= w;
		}
		edges--;
	}
	graph[start - 1][start - 1] = 0;
	test a(start - 1,vertexs, graph,best,is_closed);
	a.calculate_best();
	a.display_best();
}

void test::calculate_best() {
	int MAX = 300001;
	priority_queue<int,int,greater<int>> open_edge;
	open_edge.push(make_pair(0,start_vertex));
	is_closed[start_vertex] = true;
	fill_best(open_edge);
}

void test::fill_best(priority_queue<int, int, greater<int>> open_edge) {
	int MAX = 300001;
	while (!open_edge.empty()) {
		int cost = open_edge.top().first;
		int current_vertex = open_edge.top().second;
		for (auto element : graph[current_vertex])
		{
			if (element.second + best[open_vertex.front()] < best[element.first]) {
				best[element.first] = graph[open_vertex.front()][element.first] + best[open_vertex.front()];
			}
			if (!is_closed[element.first]) {
				open_vertex.push(element.first);
				is_closed[element.first] = true;
			}
		}
		open_vertex.pop();
	}
}

void test::display_best() {
	for (int i = 0; i < vertexs; i++) {
		if (best[i] == 200001)
			cout << "INF" << endl;
		else
			cout << best[i] << endl;
	}
}