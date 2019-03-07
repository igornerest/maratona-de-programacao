// https://br.spoj.com/problems/CACHE13/
#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef vector < vector<ll> > matrix;

ll modulo(ll num) {
	if(num > MOD)
		num %= MOD;

	return num;
}

matrix operator* (matrix &a, matrix &b) {
	int i, j, k;
	int lin = a.size(), col = b[0].size();
	matrix res;

	res.resize(lin);
	for (i = 0; i < lin; i++) {
		res[i].resize(col);
		for(j = 0; j < col; j++) {
			res[i][j] = 0;
			for(k = 0; k < lin; k++) 
				res[i][j] += (a[i][k] * b[k][j]) % MOD;
			res[i][j] = modulo(res[i][j]);
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

ll scarf(ll length) {
	if (length == 0) // Nao ha passos a fazer, mas sabemos o numero base
		return 12;

	// Fi(n) = 3Fi(n-1) + 2 Fd(n-1) #colunas com cores duas cores iguais
	// Fd(n) = 2Fi(n-1) + 2 Fd(n-1) #colunas com cores diferentes
	// F(n) = Fi(n) + Fd(n)
	matrix T = {{3,2},{2,2}};
	matrix base = {{6},{6}};
	
	matrix res = T ^ length;
	res = res * base;

	return modulo(res[0][0] + res[1][0]);
}


int main() {
	ll length; 

	cin >> length;

	cout << scarf(length - 1) << endl;

	return 0;
}