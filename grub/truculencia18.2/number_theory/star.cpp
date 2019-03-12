// https://www.urionlinejudge.com.br/judge/pt/problems/view/1233
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


ll star(ll n) {
	ll ans = n;
	for(ll i = 2; i * i <= n; i++) if(n % i == 0) {
		ans -= ans/i;
		while(n % i == 0) n /= i;
	}
	if(n != 1) ans -= ans/n;
	return ans;
}

int main() {
	ll n;
	while (cin >> n) 
		cout << star(n) / 2 << endl;
	return 0;
}