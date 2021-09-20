#include <iostream>

#define endl '\n'

using namespace std;

int N;
int parent[51];
int delete_index;
int root_index;
bool is_leaf_node[51];
int answer = 0;

void input();
void solve();

int union_parent[51];
int find(int target_index);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    if (temp == -1) {
      parent[i] = i;
      union_parent[i] = i;
      root_index = i;
    } else {
      parent[i] = temp;
      union_parent[i] = temp;
    }
  }
  cin >> delete_index;
}

void solve() {
  //먼저 두 개로 쪼개고 루트를 가리키고있는 노드들을 유니온파인드로 구별
  union_parent[delete_index] = delete_index;
  for (int i = 0; i < N; i++) {
    find(i);
  }
  /*
  for(int i=0;i<N;i++){
    cout << union_parent[i]<< " ";
  }
  cout << endl;
  */
  //루트를 가리키고 있는 노드들만을 parent[]를 통하여 is_leaf를 채워줌,
  //바꿀때마다 answer++

  for (int i = 0; i < N; i++) {
    if (union_parent[i] == delete_index) {
      is_leaf_node[i] = false;
    } else {
      is_leaf_node[i] = true;
    }
  }

  for (int i = 0; i < N; i++) {
    if (union_parent[i] == delete_index || i == root_index) {
      continue;
    }
    is_leaf_node[parent[i]] = false;
  }
  for (int i = 0; i < N; i++) {
    if (is_leaf_node[i]) {
      answer++;
    }
  }
  cout << answer;
}

int find(int target_index) {
  /*
  int temp=target_index;
  int parent_index=union_parent[temp];
  while(parent_index!=temp){
    temp=parent_index;
    parent_index=union_parent[temp];
  }
  union_parent[target_index]=temp;
  */
  int parent_index = union_parent[target_index];
  if (parent_index == target_index) {
    return parent_index;
  } else {
    return union_parent[target_index] = find(parent_index);
  }
}
