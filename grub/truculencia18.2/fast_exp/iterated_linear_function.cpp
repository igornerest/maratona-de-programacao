// https://codeforces.com/problemset/problem/678/D
#include <iostream>
#include <vector>

using namespace std; 

#define MOD 1000000007

typedef long long ll;
typedef vector< vector<ll> > matrix;

matrix operator* (matrix &a, matrix &b) {
	int i, j, k; 
	int lin = a.size(), col = b[0].size();
	matrix result; 

	result.resize(lin);
	for(i = 0; i < lin; i++) {	
		result[i].resize(col);
		for(j = 0; j < col; j++) {
			result[i][j] = 0;
			for(k = 0; k < lin; k++) 
				result[i][j] += (a[i][k] * b[k][j]) % MOD;
			result[i][j] %= MOD;
		}
	}

	return result;
}

matrix operator^ (matrix &a, ll exp) {
	if (exp == 1)
		return a;
	
	matrix result = a ^ exp/2;
	result = result * result; 

	if (exp % 2 == 1) 
		result = result * a; 

	return result;
}

ll linear_function(matrix &T, matrix &base, ll n) {
	T = T ^ n;
	T = T * base; 

	return T[0][0];
}

int main() {
	ll A, B, n, x;

	cin >> A >> B >> n >> x;

	matrix T = {{A, 0, B}, {0, 1, 1}, {0, 0, 1}};
	matrix base = {{x}, {x}, {1}};

	cout << linear_function(T, base, n) << endl;

	return 0;
}