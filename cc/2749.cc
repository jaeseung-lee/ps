#include <iostream>

using namespace std;

#define endl '\n'
#define mod 1000000
#define ll long long

ll N;

struct mat {
  ll x1, x2, y1, y2;
};

void input();
void solve();
mat dq(ll n);
mat make_mat(ll x1, ll x2, ll y1, ll y2);
mat mul_mat(const mat& A, const mat& B);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();

  return 0;
}

void input() { cin >> N; }

void solve() {
  if (N == 0) {
    cout << "0" << endl;
  } else {
    mat ans = dq(N - 1);
    cout << ans.x1 % mod << endl;
  }
}

mat dq(ll n) {
  if (n == 0) {
    return make_mat(1, 0, 0, 1);
  }
  if (n == 1) {
    return make_mat(1, 1, 1, 0);
  }
  mat temp = dq(n / 2);
  if (n % 2 == 0) {
    return mul_mat(temp, temp);
  } else {
    return mul_mat(mul_mat(temp, temp), make_mat(1, 1, 1, 0));
  }
}

mat make_mat(ll x1, ll x2, ll y1, ll y2) {
  mat result;
  result.x1 = x1;
  result.x2 = x2;
  result.y1 = y1;
  result.y2 = y2;
  return result;
}

mat mul_mat(const mat& A, const mat& B) {
  mat result;
  result.x1 = (A.x1 * B.x1 + A.x2 * B.y1) % mod;
  result.x2 = (A.x1 * B.x2 + A.x2 * B.y2) % mod;
  result.y1 = (A.y1 * B.x1 + A.y2 * B.y1) % mod;
  result.y2 = (A.y1 * B.x2 + A.y2 * B.y2) % mod;
  return result;
}
