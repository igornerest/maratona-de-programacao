//https://codeforces.com/problemset/problem/166/E
#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

typedef long long ll; 
typedef vector< vector<ll> > matrix;

matrix T = {{0,1, 1,1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}};

matrix operator* (matrix &a, matrix &b) {
	matrix result; 
	int i, j, k; 
	int lin = a.size(), col = b[0].size();

	result.resize(lin);
	for (i = 0; i < lin; i++) {
		result[i].resize(col);		
		for (j = 0; j < col; j++) {
			result[i][j] = 0;
			for (k = 0; k < lin; k++) {
				result[i][j] += (a[i][k] * b[k][j]) % MOD;
				result[i][j] %= MOD;
			}
		}
	}

	return result;
}

matrix operator^ (matrix &a, int exp) {
	if (exp == 1)
		return a; 

	matrix result = a ^ exp/2;
	result = result * result; 

	if (exp % 2 == 1) 
		result = result * a;

	return result;
}

ll tetrahedron(int length) {
	matrix result = T ^ length;

	return result[0][0];
}

int main() {
	int n; 

	cin >> n;

	cout << tetrahedron(n) << endl;

	return 0;
}