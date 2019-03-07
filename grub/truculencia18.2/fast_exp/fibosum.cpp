//https://www.spoj.com/problems/FIBOSUM/
#include <iostream>
#include <vector>

using namespace std; 

#define MOD 1000000007

typedef long long ll;
typedef vector < vector<ll> > matrix;

matrix operator* (matrix &a, matrix &b) {
	matrix res; 
	int lin = a.size(), col = b[0].size(); 

	res.resize(lin);
	for (int i = 0; i < lin; i++) {
		res[i].resize(col);
		for(int j = 0; j < col; j++) {
			res[i][j] = 0; 
			for(int k = 0; k < lin; k++)  {
				res[i][j] += (a[i][k] * b[k][j]) % MOD;;
				res[i][j] %= MOD;
			}
		}
	}

	return res;
}

matrix operator^(matrix &a, int exp) {
	matrix result;

	if (exp == 1)
		return a; 

	result = a ^ exp/2;
	result = result * result; 

	if (exp % 2 == 1)
		result = result * a; 

	return result;
}

matrix T = {{1, 1}, {1, 0}};
matrix base = {{0}, {1}};

long long fib(int N) {
	if(N == 0)
		return 0;
	if(N == 1)
		return 1;

	matrix result = T ^ N;
	result = result * base;

	return result[0][0];
}

// F(n) + F(n-1) + F(n-2) + ... + F(M)
// F(n) + ... + F(0) = F(n+2) - 1;
long long fibosum(int M, int N) {
	return (fib(N + 2) - fib(M + 1) + MOD)%MOD;
}

int main() {
	int ntimes, min, max; 

	cin >> ntimes; 

	while(ntimes > 0) {
		cin >> min >> max; 

		cout << fibosum(min, max) << endl;

		ntimes--;
	}


	return 0; 
}