#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define endl '\n'

int T,N,M;

void input();
void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  for(int i=0;i<T;i++){
    solve();
  }

  return 0;
}

void input() {
  cin >> T;
}

void solve() {
  cin >> N;
  vector<int> A;
  int temp;
  for(int i=0;i<N;i++){
    cin >> temp;
    A.push_back(temp);
  }
  cin >> M;
  vector<int> B;
  for (int i = 0; i < M; i++) {
    cin >> temp;
    B.push_back(temp);
  }
  sort(A.begin(),A.end());
  for(int element : B){
    auto iter = lower_bound(A.begin(),A.end(),element);
    if(iter == A.end() || (*iter) !=element){
      cout << "0" << endl;
    } else {
      cout << "1" << endl;
    }
  }
}
