#include <iostream>
#include <string>
#include <vector>

#define endl '\n'

using namespace std;

int N, K;
string words[50];
bool visited[26] = {
    false,
};
int answer = 0;
vector<unsigned int> words_to_bits;

void input();
void solve();
void search(int now_index, int visited_num);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> words[i];
  }
}

void solve() {
  for (int word_index = 0; word_index < N; word_index++) {
    unsigned int bits = 0b00000010000010000100000101; // a,n,t,i,c는 true
    string word = words[word_index].substr(4, words[word_index].length() - 8);
    // cout << "word : " << word << endl;
    for (int i = 0; i < word.length(); i++) {
      int index = (int)word.at(i);
      index = index - 97;
      // cout << "index : " << index << endl;
      bits = bits | (1 << index);
    }
    words_to_bits.push_back(bits);
  }

  visited[0] = true;
  visited[2] = true;
  visited[8] = true;
  visited[13] = true;
  visited[19] = true;

  search(0, 5);
  cout << answer;
}

void search(int now_index, int visited_num) {
  if (visited[now_index]) {
    search(now_index + 1, visited_num);
    return;
  }

  if (visited_num == K) {
    // cout << "now_index : " << now_index << endl;
    int best = 0;
    bool is_target = true;
    /*
    cout << "available letters : ";
    for(int i=0;i<26;i++){
      if(visited[i]){
        char a = (char)(i+97);
        cout << a << " ";
      }
    }
    cout << endl;
    */

    for (int i = 0; i < N; i++) {
      // cout << "now word : " << words[i] << endl;
      for (int j = 0; j < 26; j++) {
        if ((words_to_bits[i] & (1 << j))) {
          if (visited[j]) {
            continue;
          } else {
            is_target = false;
            // cout << (char)(j+97) << " is not contained." <<endl;
            break;
          }
        }
      }
      /*
      if(!is_target){
        cout << "not target" << endl;
      } else {
        cout << "target" << endl;
      }
      */
      if (is_target) {
        best++;
      }
      is_target = true;
    }

    // cout << "best : " << best << endl;
    if (best > answer) {
      answer = best;
    }
    return;
  }

  if (now_index == 26) {
    return;
  }

  visited[now_index] = true;
  search(now_index + 1, visited_num + 1);
  visited[now_index] = false;
  search(now_index + 1, visited_num);
}
