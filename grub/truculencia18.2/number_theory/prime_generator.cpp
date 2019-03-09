//https://www.spoj.com/problems/PRIME1/

#include <iostream>

using namespace std;

void prime(int m, int n) {
	int i, j;
	bool temp;

	for(i = m; i <= n; i++) {
		temp = true;

		for(j = 2; j * j <= i && temp; j++)
			if(i % j == 0)
				temp = false;

		if(temp && i != 1)
			cout << i << endl;
	}
}

int main() {
	int t, m, n;

	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> m >> n;
		prime(m, n);
		cout << endl;
	}

	return 0;
}