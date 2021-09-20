#include <iostream>

using namespace std;

#define endl '\n'
#define ll long long
#define mod 1000000007

ll N;

void input();
// (1 1) ^ n-1
// (1 0)

struct matrix {
	ll X1, X2;
	ll Y1, Y2;
};

matrix make_matrix(ll a, ll b, ll c, ll d) {
	matrix result;
	result.X1 = a%mod;
	result.X2 = b%mod;
	result.Y1 = c%mod;
	result.Y2 = d%mod;
	return result;
}

matrix make_square_matrix(matrix A) {
	ll a = A.X1;
	ll b = A.X2;
	ll c = A.Y1;
	ll d = A.Y2;
	matrix result;
	result.X1 = (a*a+b*c)%mod;
	result.X2 = (a*b+b*d)%mod;
	result.Y1 = (a*c+c*d)%mod;
	result.Y2 = (b*c+d*d)%mod;
	return result;
}

matrix make_plus_one_matrix(matrix A) {
	ll a = A.X1;
	ll b = A.X2;
	ll c = A.Y1;
	ll d = A.Y2;
	matrix result;
	result.X1 = (a+c) % mod;
	result.X2 = (b+d) % mod;
	result.Y1 = a;
	result.Y2 = b;
	return result;
}

void solve();
matrix cal(ll n);

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
}

void solve() {
	if (N != 0) {
		matrix result = cal(N - 1);
		cout << result.X1%mod << endl;
	}
	else {
		cout << 0 << endl;
	}
}

matrix cal(ll n) {
	if (n == 1) {
		return make_matrix(1, 1, 1, 0);
	}

	if (n == 0) {
		return make_matrix(1, 0, 0, 1);
	}

	if (n % 2 == 0) {
		matrix A = cal(n / 2);
		return make_square_matrix(A);
	}
	else {
		matrix A = cal(n / 2);
		A = make_square_matrix(A);
		return make_plus_one_matrix(A);
	}
}