// https://codeforces.com/gym/101879/problem/G
// se implementar as queries separadamente, o tempo de execucao diminui
#include <iostream>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f

typedef vector<pair<int, int >> vii;

typedef struct node{
	int min;
	int max; 
	int l; 
	int r;
} node;

node str[800010]; // segtree

void update(int i) {
	str[i].min = max(str[i*2].min, str[i*2+1].min);
	str[i].max = min(str[i*2].max, str[i*2+1].max);
}

void build(vii &v, int i, int l, int r) {
	str[i].r = r;
	str[i].l = l;

	if(l == r) {
		str[i].min = v[l].first;
		str[i].max = v[l].second;
	} else {
		int mid = l + (r - l)/2;
		build(v, i*2, l, mid);
		build(v, i*2+1, mid+1, r);
		
		update(i);	
	}
} 

void change(int i, int id, int min, int max) {
	if(str[i].l > id || str[i].r < id)
		return;

	if(str[i].l == id && str[i].r == id){
		str[i].min = min;
		str[i].max = max;
		return;
	}

	change(i*2, id, min, max);
	change(i*2+1, id, min, max);

	update(i);
}

pair<int, int> query(int i, int ql, int qr) {
	if(str[i].l > qr || str[i].r < ql)
		return make_pair(-INF, INF);

	if(str[i].l >= ql && str[i].r <= qr)
		return make_pair(str[i].min, str[i].max);


	pair<int, int> a = query(i*2, ql, qr);
	pair<int, int> b = query(i*2+1, ql, qr);

	return make_pair(max(a.first, b.first), min(a.second, b.second));
}

int main() {
	int n, q; 
	vii guards;

	cin >> n >> q;
	guards.resize(n + 1);
	
	for(int i = 1; i <= n; i++) 
		cin >> guards[i].first >> guards[i].second;	

	build(guards, 1, 1, n);

	for(int i = 0; i < q; i++) {
		char cmd;
		int ql, qr, id;
		cin >> cmd;

		if(cmd == '?') {
			pair<int, int> interval;
			cin >> ql >> qr;

			interval = query(1, ql, qr);
			cout << max(interval.second - interval.first + 1, 0) <<  endl;
		} else {
			cin >> id >> ql >> qr;
			change(1, id, ql, qr);
		}
	}

	return 0;
}