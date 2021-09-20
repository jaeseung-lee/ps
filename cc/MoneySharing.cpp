#include <algorithm>
#include <iostream>
#include <vector>

#define endl '\n'
#define ll long long

using namespace std;

int n, m;
vector<ll> money_list;

struct minus_element {
  ll value;
  int index;
  bool is_approved;
};

bool comparator_value(minus_element a, minus_element b) {
  return a.value > b.value;
}

bool comparator_index(minus_element a, minus_element b) {
  return a.index < b.index;
}

void input();
void solve();
minus_element make_minus_element(ll _value, int _index, bool _is_approved);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() {
  cin >> n >> m;
  for (int i = 0; i < n + m; i++) {
    ll value;
    cin >> value;
    money_list.push_back(value);
  }
}

void solve() {
  vector<minus_element> minus_list;
  ll money = 0;
  for (int i = 0; i < n + m; i++) {
    if (money_list[i] > 0) {
      //일단 Minus_list sort
      sort(minus_list.begin(), minus_list.end(), comparator_value);
      for (int minus_list_index = 0; minus_list_index < minus_list.size();
           minus_list_index++) {
        if (money + (ll)minus_list[minus_list_index].value >= 0) {
          money = money + (ll)minus_list[minus_list_index].value;
          minus_list[minus_list_index].is_approved = true;
          // cout << "now money : " << money <<endl;
        } else {
          break;
        }
      }
      sort(minus_list.begin(), minus_list.end(), comparator_index);
      // minus_list보고 approved declined출력
      for (int j = 0; j < minus_list.size(); j++) {
        if (minus_list[j].is_approved) {
          cout << "approved" << endl;
        } else {
          cout << "declined" << endl;
        }
      }
      money += money_list[i];
      cout << "resupplied" << endl;
      minus_list.clear();
    } else {
      minus_list.push_back(make_minus_element(money_list[i], i, false));
    }
  }

  // cout << "here" << endl;
  sort(minus_list.begin(), minus_list.end(), comparator_value);
  for (int minus_list_index = 0; minus_list_index < minus_list.size();
       minus_list_index++) {
    if (money + (ll)minus_list[minus_list_index].value >= 0) {
      money = money + (ll)minus_list[minus_list_index].value;
      minus_list[minus_list_index].is_approved = true;
      // cout << "now money : " << money <<endl;
    } else {
      break;
    }
  }
  sort(minus_list.begin(), minus_list.end(), comparator_index);
  // minus_list보고 approved declined출력
  for (int i = 0; i < minus_list.size(); i++) {
    if (minus_list[i].is_approved) {
      cout << "approved" << endl;
    } else {
      cout << "declined" << endl;
    }
  }
}

minus_element make_minus_element(ll _value, int _index, bool _is_approved) {
  minus_element result;
  result.index = _index;
  result.value = _value;
  result.is_approved = _is_approved;
  return result;
}
