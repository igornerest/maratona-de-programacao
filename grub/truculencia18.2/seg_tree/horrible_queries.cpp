// https://www.spoj.com/problems/HORRIBLE/
// sempre tomar cuidado com estouro das variaveis!!
#include <iostream>
#include <vector>

using namespace std; 

typedef long long ll; 
typedef vector<ll> vi;

typedef struct node{
	ll v; 
	int l; 
	int r;
	ll d;	//delta
} node; 

node st[400010];

void build(int i, int l, int r) {
	st[i].r = r;
	st[i].l = l;
	st[i].d = 0;

	if(l == r)
		st[i].v = 0;
	else{
		int mid = l + (r - l)/2;
		build(i*2, l, mid);
		build(i*2+1, mid+1, r);

		st[i].v = 0;
	}
}

void prop(int i) {
	// propagacao
	st[2*i].d += st[i].d;
	st[2*i+1].d += st[i].d;
	st[i].d = 0;
}

void update(int i){
	st[i].v = st[i*2].v + st[i*2].d * (st[i*2].r - st[i*2].l + 1) + st[i*2+1].v + st[i*2+1].d * (st[i*2+1].r-st[i*2+1].l+1);
}

void increment(int i, int ql, int qr, int v) {
	if(qr < st[i].l || st[i].r < ql) // fora
		return;

	if(st[i].l >= ql && st[i].r <= qr){ // partial
		st[i].d += v;
		return;
	}

	prop(i);

	increment(i*2, ql, qr, v);
	increment(i*2+1, ql, qr, v); 
	
	update(i);
}

ll sum(int i, int ql, int qr) {
	if(qr < st[i].l || st[i].r < ql) // fora
		return 0;

	if(st[i].l >= ql && st[i].r <= qr) // partial
		return st[i].v + st[i].d * (st[i].r - st[i].l + 1);

	prop(i);

	ll res = sum(i*2, ql, qr) + sum(i*2+1, ql, qr);
	
	update(i);

	return res;
}

int main() {
	int t, n, c; 

	cin >> t; 

	for(int i = 0; i < t; i++) {
		cin >> n >> c;

		build(1, 1, n);

		for(int i = 0; i < c; i++) {
			int op, l, r, value;

			cin >> op >> l >> r;

			if(op == 0) {
				cin >> value;
				increment(1, l, r, value);
			} else {
				cout << sum(1, l, r) << endl;
			}
		}


	}
	return 0;
}