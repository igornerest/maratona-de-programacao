#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f

typedef long long ll;
typedef vector<int> vi;

typedef struct node {
	int v;
	int l;
	int r;
} node;

node st[400010];

void build(vi &v, int i, int l, int r) {
	st[i].r = r;
	st[i].l = l;

	if(r == l) {
		st[i].v = v[l];
	}
	else {
		int mid = l + (r - l) /2;

		build(v, 2*i, l, mid);
		build(v, 2*i+1, mid+1, r);

		st[i].v = min(st[i*2].v, st[2*i+1].v);
	}
}

int query(int i, int ql, int qr) {
	if(qr < st[i].l || st[i].r < ql)
		return INF;

	if(st[i].l >= ql && st[i].r <= qr)
		return st[i].v;

	return min(query(i*2, ql, qr), query(2*i+1, ql, qr));
}

int main() {
	int t, n, q;
	int l, r;
	vi scores;

	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> n >> q;

		scores.resize(n + 1);

		for(int j = 1; j <= n; j++)
			cin >> scores[j];

		build(scores, 1, 1, n);
		
		cout << "Scenario #" << i + 1 << ":" << endl;
		for(int j = 0; j < q; j++) {
			cin >> l >> r;
			cout << query(1, l, r) << endl;
		}
	}


	return 0;
}