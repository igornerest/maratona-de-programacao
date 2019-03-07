// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4448
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
	UnionFind(int V, vector<int> pp) {
		id.resize(V + 1);
		rank.resize(V + 1);

		for(int i = 0; i < V + 1; i++) {
			id[i] = i;
			rank[i] = 1;
		}

		for(int i = 0; i < pp.size(); i++)
			id[pp[i]] = pp[0];
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

ll kruskal(edgeList E, int Vsize, vector<int> pp) {
	ll sum = 0, cost; 
	edge temp;	
	UnionFind uf(Vsize, pp); 

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
	int ntimes, Vsize, Esize, npp; 
	int i, j; 
	vector <int> pp; // powerplant
	edgeList E;

	cin >> ntimes;
	for(i = 0; i < ntimes; i++) {
		cin >> Vsize >> Esize >> npp;

		pp.resize(npp);
		for(j = 0; j < npp; j++)
			cin >> pp[j];
		
		E.resize(Esize);
		for(j = 0; j < Esize; j++) 
			cin >> E[j].second.first >> E[j].second.second >> E[j].first;

		cout << "Case #" << i + 1 << ": " << kruskal(E, Vsize, pp) << endl;
	}
	return 0; 
}