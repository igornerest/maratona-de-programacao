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

bool isPrime(ll N) {
	if(N <= _sieve_size) return bs[N];	// se o valor primo ja foi calculado
	for(int i = 0; i < primes.size(); i++) 
		if(N % primes[i] == 0) return false;
	return true;
	// em geral, se o N for muito grande, o algoritmo demora mais
	// so funciona se N <= (ultimo primo calculado) ^ 2
	// mas nosso bitset possui um tamanho grande
}

int main() {
	sieve(10000000);
	cout << isPrime(2147483647) << endl;	// primo
	cout << isPrime(136117223861) << endl;	// nao primo
	return 0;
}