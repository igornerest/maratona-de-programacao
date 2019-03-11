#include <bits/stdc++.h>

using namespace std;

typedef long long			ll;
typedef pair<int, int>		ii;
typedef vector<ii>			vii;
typedef vector<int>			vi;

#define	INF	0x3f3f3f3f
#define	pb	push_back
#define	mk	make_pair
#define	fi	first
#define	se	second
#define	eb	emplace_back

int x, y, d; 

// para uma equacao ax + by = 1
void extendedEuclid(int a, int b) {
	if(b == 0) {
		x = 1;
		y = 0;
		d = a;
		return;
	}
	extendedEuclid(b, a%b);
	int x1 = y; 
	int y1 = x - (a/b) * y; 
	x = x1;
	y = y1;
}

int main() {
	int a = 2, b = 18, c = 839;
	extendedEuclid(a, b);
	
	cout << "Para " << a << "x + " << b << "y = " << c <<  ", temos:" << endl;
	cout << "a = " << x * (c / __gcd(a, b)) << endl;
	cout << "b = " << y * (c / __gcd(a, b)) << endl;
	return 0;
}