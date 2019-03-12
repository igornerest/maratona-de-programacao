//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1480
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

#define MAX 1000000000000
#define SIEVE 1000000

vector<ll> primes;
bitset<1000010> bs;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= SIEVE; i++) if(bs[i]) {
		for(ll j = i * i; j <= SIEVE; j += i) {
			bs[j] = 0;
		}
	}
}

void almost_primes() {
	for(ll i = 2; i <= SIEVE; i++) if(bs[i]) {
		for(ll j = i * i; j < MAX; j *= i)
			primes.pb(j);
	}
}

int main() {
	int n;
	ll lo, hi;
	
	cin >> n;

	sieve();
	almost_primes();
	sort(primes.begin(), primes.end());
	
	for(int i = 0; i < n; i++) {
		cin >> lo >> hi;
		auto x = lower_bound(primes.begin(), primes.end(), lo);
		auto y = upper_bound(primes.begin(), primes.end(), hi);
		cout << y - x << endl;
	}

	return 0;
}