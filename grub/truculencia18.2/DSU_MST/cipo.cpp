// https://br.spoj.com/problems/CIPO/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> edge;
typedef vector< pair<ll, edge> > edgeList; 

class UnionFind{
private:
	vector<int> id, rank;

public:
	UnionFind(int V) {
		id.resize(V + 1);
		rank.resize(V + 1);

		for(int i = 0; i < V + 1; i++) {
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

ll kruskal(edgeList E, int Vsize) {
	ll sum = 0, cost; 
	edge temp;	
	UnionFind uf(Vsize); 

	sort(E.begin(), E.end());

	for(int i = 0; i < E.size(); i++) {
		temp = E[i].second;
		cost = E[i].first;

		if(uf.find(temp.first) != uf.find(temp.second)) {
			uf.join(temp.first, temp.second);
			sum += cost; 
		}
	}

	return sum;
}

int main() {
	int Vsize, Esize, count = 1; 
	edgeList E; 

	while(cin >> Vsize >> Esize) {
		E.resize(Esize);

		for(int i = 0; i < Esize; i++)
			cin >> E[i].second.first >> E[i].second.second >> E[i].first; 

		cout << "Instancia " << count << endl << kruskal(E, Vsize) << endl;
		count++;
	}

	return 0;
}