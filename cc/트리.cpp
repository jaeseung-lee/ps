#include <iostream>
#include <stack>
#include <vector>

#define endl '\n'

using namespace std;

int parent[200000 + 1];
int now_parent[200000 + 1];

struct operations {
  bool is_question;
  int first;
  int second;
};
int N;
int Q;
vector<operations> ops;

operations make_op(int fst);
operations make_op(int fst, int snd);

void input();
void solve();
int find(int target_index);
void Union(int first_index);
bool answer_question(int first_index, int second_index);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

operations make_op(int fst) {
  operations result;
  result.is_question = false;
  result.first = fst;
  result.second = -1;
  return result;
}

operations make_op(int fst, int snd) {
  operations result;
  result.is_question = true;
  result.first = fst;
  result.second = snd;
  return result;
}

void input() {
  cin >> N >> Q;
  for (int i = 2; i <= N; i++) {
    int temp;
    cin >> temp;
    parent[i] = temp;
    now_parent[i] = i;
  }
  for (int i = 0; i < N + Q - 1; i++) {
    bool is_question;
    cin >> is_question;
    if (is_question) {
      int fst, snd;
      cin >> fst >> snd;
      ops.push_back(make_op(fst, snd));
    } else {
      int fst;
      cin >> fst;
      ops.push_back(make_op(fst));
    }
  }
}

void solve() {
  parent[1] = 1;
  now_parent[1] = 1;
  stack<bool> answers;
  for (int i = N + Q - 1 - 1; i >= 0; i--) {
    if (ops[i].is_question) {
      answers.push(answer_question(ops[i].first, ops[i].second));
    } else {
      Union(ops[i].first);
    }
  }

  while (!answers.empty()) {
    if (answers.top()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    answers.pop();
  }
}

int find(int target_index) {
  int parent_index = now_parent[target_index];
  if (parent_index == target_index) {
    return parent_index;
  } else {
    return now_parent[target_index] = find(parent_index);
  }
}

bool answer_question(int first_index, int second_index) {
  int first_root = find(first_index);
  int second_root = find(second_index);
  // cout << first_root << " = find(" << first_index << "), " << second_root <<
  // " = find(" << second_index << ")" << endl;
  return first_root == second_root;
}

void Union(int first_index) {
  int root = find(parent[first_index]);
  now_parent[first_index] = root;
}
