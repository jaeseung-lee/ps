#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

enum Status { BLANK, STAR };
int N;
int k = 0;
// pair<Status,counts>
vector<pair<int, int>> stars[3 * 1024];
void input();
void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() { cin >> N; }

void solve() {
  int temp = 1;
  while (temp != N / 3) {
    temp = temp << 1;
    k++;
  }
  // init
  stars[0].push_back(make_pair(1, 1));
  stars[1].push_back(make_pair(1, 1));
  stars[1].push_back(make_pair(0, 1));
  stars[1].push_back(make_pair(1, 1));
  stars[2].push_back(make_pair(1, 5));

  int blank_count = 5;
  int start_index = 3;
  for (int i = 1; i <= k; i++) {
    int copy_index = 0;
    int temp_blank_count = blank_count;
    for (int j = 0; j < start_index; j++, copy_index++) {
      // cout << "j + start_index : " << j+start_index << endl;
      // cout << "temp_blank_count : " << temp_blank_count << endl;
      stars[j + start_index] = stars[copy_index];
      stars[j + start_index].push_back(make_pair(0, temp_blank_count));
      for (int k = 0; k < stars[copy_index].size(); k++) {
        stars[j + start_index].push_back(stars[copy_index][k]);
      }
      temp_blank_count -= 2;
    }
    start_index = start_index * 2;
    blank_count = blank_count * 2 + 1;
  }
  for (int i = 0; i < N; i++) {
    for (int b = 0; b < N - 1 - i; b++) {
      cout << " ";
    }
    for (int b = 0; b < stars[i].size(); b++) {
      int now_type = stars[i][b].first;
      int now_counts = stars[i][b].second;
      // cout << "now type : " << now_type << " now_counts : " << now_counts <<
      // endl;
      if (now_type == BLANK) {
        for (int j = 0; j < now_counts; j++) {
          cout << " ";
        }
      } else {
        for (int j = 0; j < now_counts; j++) {
          cout << "*";
        }
      }
    }
    for (int b = 0; b < N - 1 - i; b++) {
      cout << " ";
    }
    cout << endl;
  }
}
