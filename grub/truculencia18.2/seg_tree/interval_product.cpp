#include <iostream>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f

typedef long long ll;
typedef vector<ll> vi;

typedef struct node{
	ll v; 
	int l; 
	int r;
} node; 

node st[400010];

void build(vi &v, int i, int l, int r) {
	st[i].r = r;
	st[i].l = l;

	if(l == r)
		st[i].v = v[l];
	else{
		int mid = l + (r - l)/2;
		build(v, i*2, l, mid);
		build(v, i*2+1, mid+1, r);
		st[i].v = st[i*2].v * st[i*2+1].v;
		
		if(st[i].v > 0)
			st[i].v = 1;
		else if(st[i].v < 0){
			st[i].v = -1;
		}
	}
}

ll multi(int i, int ql, int qr) {
	if(qr < st[i].l || st[i].r < ql)
		return 1;

	if(ql <= st[i].l && st[i].r <= qr) // fully
		return st[i].v;

	ll res = multi(i*2, ql, qr) * multi(i*2+1, ql, qr);
	return res;
}

void add(int i, int pos, ll v) {
	if(pos < st[i].l || st[i].r < pos)
		return;

	if(pos == st[i].l && pos ==st[i].r) {
		st[i].v = v;
		return;
	}

	add(i*2, pos, v);
	add(i*2+1, pos, v);
	
	st[i].v = st[i*2].v * st[i*2+1].v;
}


int main() {
	ll n, k, a, b, res;
	char cmd;
	vi seq;

	while(cin >> n >> k) {
		seq.resize(n+1);
		for(int i=1; i<=n; i++)
			cin >> seq[i];

		build(seq, 1, 1, n);

		for(int i=0; i<k; i++) {
			cin >> cmd >> a >> b;

			if(cmd == 'C') {
				add(1, a, b);
			} else if(cmd == 'P') {
				res = multi(1, a, b);
				if(res > 0)
					cout << "+";
				else if(res < 0)
					cout << "-";
				else 
					cout << "0";
			}
		}

		cout << endl;
	}

	return 0;
}