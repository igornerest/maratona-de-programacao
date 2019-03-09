// https://br.spoj.com/status/
#include <iostream>

using namespace std;

// algoritmo de Euclides
int mdc(int a, int b) {
	if(b == 0)
		return a;
	if(a == 0)
		return b;
	return mdc(b, a % b);
}

int main() {
	int t, a, b, c, d;
	int res;

	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> a >> b >> c >> d;

		res = 1;
		if((c-a) != 0 || (d-b) != 0)
			res += mdc(abs(c-a), abs(d-b));

		cout << res << endl;
	}
}