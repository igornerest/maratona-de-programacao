// exercise from https://www.spoj.com/problems/MPOW/
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
	for (i = 0; i < lin; i++) {	
		result[i].resize(col);
		for (j = 0; j < col; j++) {
			result[i][j] = 0;
			for (k = 0; k < lin; k++)  {
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

	matrix ans = a ^ exp/2;
	ans = ans * ans;

	if (exp % 2 == 1) 
		ans = ans * a;

	return ans;
}

matrix createMatrix(int size) {
	int i, j; 
	matrix res;

	res.resize(size);
	for(i = 0; i < size; i++) { 
		
		res[i].resize(size);
		for(j = 0; j < size; j++)
			cin >> res[i][j];
	}

	return res;
}

void printMatrix(matrix a) {
	int i, j; 
	int size = a.size();

	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

int main() {
	int T, M, N; 

	cin >> T;
	while(T > 0) {
		cin >> M >> N;
		
		matrix a = createMatrix(M);
		a = a ^ N;
		printMatrix(a);

		T--;
	}

	return 0;
}