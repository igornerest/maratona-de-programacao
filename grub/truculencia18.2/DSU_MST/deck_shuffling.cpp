// https://codeforces.com/gym/100187/problem/J
#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
	vector<int> id, rank;

public:
	UnionFind(int Vsize) {
		id.resize(Vsize);
		rank.resize(Vsize);
		for(int i = 0; i < Vsize; i++) {
			id[i] = i; 
			rank[i] = 1;
		}
	}

	int find(int p) {
		if(p == id[p])
			return p;

		return id[p] = find(id[p]);
	}

	void join(int p, int q) {
		p = find(p);
		q = find(q);

		if(p == q)
			return;

		if(rank[p] > rank[q])
			swap(p, q);

		id[p] = id[q];
		rank[p] += rank[q];
	}
};

int main() {
	int n, k;
	int i, j, temp;
	vector<int> order;

	cin >> n;
	
	order.resize(n);
	UnionFind uf(n);

	for(i = 0; i < n; i++) {
		cin >> temp;
		order[temp - 1] = i;
	}

	cin >> k;

	for(i = 0; i < k; i++) {
		for(j = 0; j < n; j++) {
			cin >> temp;

			uf.join(j, temp - 1);
		}	
	}

	cin >> temp;

	if(uf.find(order[temp - 1]) == uf.find(0))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
