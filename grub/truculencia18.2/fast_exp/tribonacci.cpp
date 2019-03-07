//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3914
#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000009

typedef long long ll;
typedef vector< vector<ll> > matrix;

void modulo (ll &number, ll mod) {
	while(number > MOD)
		number %= mod;
}

matrix operator* (matrix &a, matrix &b) {
	int i, j, k; 
	matrix res;

	int lin = a[0].size(), col = b[0].size(); 
	
	res.resize(lin); 
	for (i = 0; i < lin; i++) {
		res[i].resize(col);
		for (j = 0; j < col; j++) {
			res[i][j] = 0;
			for(k = 0; k < lin; k++)
				res[i][j] += (a[i][k] * b[k][j]) % MOD;

			modulo(res[i][j], MOD);
		}
	}

	return res; 
}

matrix operator^ (matrix &a, ll exp) {
	if (exp == 1)
		return a;

	matrix res = a ^ exp/2;
	res = res * res;

	if (exp % 2 == 1)
		res = res * a;

	return res; 
}

ll tribonacci (ll n) {
	if(n <= 3)
		return n -1 ;

	matrix T = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
	matrix base = {{2}, {1}, {0}};
	
	matrix result = T ^ (n - 3);
	result = result * base; 

	return result[0][0];
}

int main() {
	ll number; 

	cin >> number;

	while(number > 0){
		cout << tribonacci(number) << endl;
		cin >> number;
	}

	return 0;
}