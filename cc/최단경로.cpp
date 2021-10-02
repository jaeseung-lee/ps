/*
1. 자료구조 중에서 map은 느리다. 맵 보다는 vector<std::pair>로
2.
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  은 입출력 속도를 높히는 코드다. 꼭 쓸 것!
3. 클래스화를 하지말고 전역변수 쓰자. *코테에서만* 좀 거슬리긴 하더라도
4. 모듈화는 그대로 도입하자.
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 200001
#define MAX 30000

int V, E, start_vertex;
vector<pair<int, int>> edges[MAX];

void input() {
  cin >> V >> E >> start_vertex;
  for (int i = 0; i < E; i++) {
    int s, d, w; // source,destination,weight
    cin >> s >> d >> w;
    edges[s].push_back(make_pair(w, d));
  }
}

void dijkstra(int vertex_number, int start_index) {
  priority_queue<pair<int, int>> pq; // first==weight, second = index
  pq.push(make_pair(0, start_index));
  vector<int> best(vertex_number + 1, INF);
  best[start_index] = 0;

  while (!pq.empty()) {
    int cost = -pq.top().first;
    int here = pq.top().second;
    pq.pop();

    //현재 꺼낸 비용이 best의 비용보다 크다면, 그냥 뺴고 버림
    if (cost > best[here]) {
      continue;
    }

    for (int i = 0; i < edges[here].size(); i++) {
      int next_vertex = edges[here][i].second;
      int new_distance = cost + edges[here][i].first;
      //현재 노드로부터 나가는 모든 edge들을 큐에 넣음
      if (new_distance <
          best[edges[here][i].second]) { // best와 비교해서 더 작으면 넣자
        best[edges[here][i].second] = new_distance;
        pq.push(make_pair(-new_distance, edges[here][i].second));
      }
    }
  }

  // display
  for (int i = 1; i <= V; i++) {
    if (best[i] == INF)
      cout << "INF" << endl;
    else {
      cout << best[i] << endl;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  dijkstra(V, start_vertex);

  return 0;
}
