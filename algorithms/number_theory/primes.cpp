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

ll _sieve_size;
bitset<10000010> bs; //bitset mais rapido que vector<bool>
vi primes;

// crivo de eratosthenes
void sieve(ll upperbound) {	// cria lista de primos em [0..upperbound]
	_sieve_size = upperbound + 1;	// inclui o upperbound
	bs.set(); 	// seta todos os bits para 1
	bs[0] = bs[1] = 0;	// 0 e 1 nao sao primos
	for(ll i = 2; i <= _sieve_size; i++) if(bs[i]) { // para todo primo
		// excluir os multiplos de i comecando de i * i
		for(ll j = i * i; j <= _sieve_size; j += i)
			bs[j] = 0;
		primes.pb((int)i);
	}
}

// fatores primos
vi primesFactors(ll N) {
	vi factors;
	ll PF_index = 0, PF = primes[PF_index];

	while (PF * PF <= N) {
		while(N % PF == 0) {
			N /= PF;
			factors.pb(PF);
		}
		PF = primes[++PF_index];
	}

	if (N != 1) factors.pb(N);
	return factors;
}

// numero de fatores primos
ll numPF(ll N) {
	ll PF_index = 0, PF = primes[PF_index], ans = 0;
	while(PF * PF < N) {
		while(PF % N == 0) {
			N /= PF;
			ans++;
		}
		PF = primes[++PF_index];
	}
	if(N != 1) ans++;
	return ans;
}

// numero de divisores
// para a^i + b ^j + ... + c^k
// a formula eh (i+1) x (j+1) x .. (k + 1)
ll numDiv(ll N) {
	ll PF_index = 0, PF = primes[PF_index], ans = 1;
	while(PF * PF < N) {
		ll power = 0;
		while(PF % N == 0) {
			N /= PF;
			power++;
		}
		ans *= (power + 1);
	}
	if(N != 1) ans *= 2;	// ultimo fator tem pow = 1
	return ans;
}

// calcular o numero de inteiros menores que N que são coprimos com N
// seja N = a^i + b^j + ... + c^k
// temos que phi(n) = N * (1 - 1/i) ++ (1 - 1/k)
ll eulerPhi(ll N) {
	ll PF_index = 0, PF = prime[PF_index], ans = N; 
	while(PF * PF < N) {
		if(N % PF == 0) ans -= ans/PF;
		while(N % PF == 0) N /= PF;
		PF = primes[++PF_index];
	}
	if(N != 1) ans -= N;	// ultimo fator
	return ans;
}

int main() {
	sieve(1000000);

	vi r = primesFactors(214748364);	// primo
	for(vi::iterator i = r.begin(); i != r.end(); i++)
		cout << *i << endl;

	return 0;
}