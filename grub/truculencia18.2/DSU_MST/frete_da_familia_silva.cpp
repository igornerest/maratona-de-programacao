// https://br.spoj.com/problems/FRETE08/#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> edge;
typedef vector<pair<int, edge>> edgeList;

class UnionFind {
private:
	vector<int> id, rank;

public:
	UnionFind(int V) {
		id.resize(V);
		rank.resize(V);
		for(int i = 0; i < V; i++) {
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


int kruskal(edgeList E, int Vsize) {
	int i, sum = 0, cost; 
	UnionFind uf(Vsize);

	sort(E.begin(), E.end());

	for (i = 0; i < E.size(); i++){
		edge temp = E[i].second;
		cost = E[i].first;

		if(uf.find(temp.first) != uf.find(temp.second)) {
			uf.join(temp.first, temp.second);
			sum += cost;
		}
	}
	return sum;
}

int main() {
	int Esize, Vsize; 
	edgeList E; 

	cin >> Vsize >> Esize; 

	E.resize(Esize);
	for (int i = 0; i < Esize; i++)
		cin >> E[i].second.first >> E[i].second.second >> E[i].first;

	cout << kruskal(E, Vsize) << endl;
	return 0;
}