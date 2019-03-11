// Greatest Common Divisor e Least Common Multiple
// MDC e MMC
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

// ha uma funcao nativa de gcd -> __gdc(a, b)
int gcd(int a, int b) {
	if(a == 0) return b; 
	if(b == 0) return a;
	return gcd(b, a%b);
}

// lcm(a, b) = a * b/gdc(a, b)
int lcm(int a, int b) {
	return a * (b / gcd(a, b));
}

int main() {

	cout << (gcd(5, gcd(25, 30))) << endl;

	cout << __gcd(18, 9);
	return 0;
}