/*
그 집합에 몇 명이 들어있는지 셀 떄는 새로운 배열을 통해서 merge할 때 개수를
더해준다.
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define endl '\n'

using namespace std;

int T;
vector<vector<pair<string, string>>> testcases;
vector<int> parent;
vector<int> cnt;

void input();
void solve();

// union-find
int find(int target_index);
void merge(int first_index, int second_index);

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
    int edges;
    cin >> edges;
    vector<pair<string, string>> temp;
    for (int j = 0; j < edges; j++) {
      string a, b;
      cin >> a >> b;
      temp.push_back(make_pair(a, b));
    }
    testcases.push_back(temp);
  }
}

void solve() {
  for (int testcase_index = 0; testcase_index < T; testcase_index++) {
    parent.clear();
    cnt.clear();
    map<string, int> id_map;
    int id_number = 0;
    for (int edges_index = 0; edges_index < testcases[testcase_index].size();
         edges_index++) {
      string left_name = testcases[testcase_index][edges_index].first;
      string right_name = testcases[testcase_index][edges_index].second;
      int left_index;
      int right_index;
      auto search = id_map.find(left_name);
      if (search == id_map.end()) {
        id_map.insert({left_name, id_number});
        left_index = id_number;
        parent.push_back(id_number);
        cnt.push_back(1);
        id_number++;
      } else {
        left_index = (*search).second;
      }
      auto search2 = id_map.find(right_name);
      if (search2 == id_map.end()) {
        id_map.insert({right_name, id_number});
        right_index = id_number;
        parent.push_back(id_number);
        cnt.push_back(1);
        id_number++;
      } else {
        right_index = (*search2).second;
      }

      merge(left_index, right_index);
      // cout << "left_index, right_index : " << left_index << " " <<
      // right_index << endl;
      int target_root = find(left_index);
      cout << cnt[target_root] << endl;
      // cout << "map size : " << id_map.size() << endl;
    }
  }
}

int find(int target_index) {
  int parent_value = parent[target_index];
  if (parent_value == target_index) {
    return parent_value;
  } else {
    return parent[target_index] = find(parent_value);
  }
}
void merge(int first_index, int second_index) {
  int first_root = find(first_index);
  int second_root = find(second_index);
  if (first_root != second_root) {
    parent[first_root] = second_root;
    cnt[second_root] += cnt[first_root];
  }
}
