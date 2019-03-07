// https://br.spoj.com/problems/REDOTICA/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

typedef pair<int, int> edge;  
typedef vector< pair<long long, edge> > edgeList; 
typedef vector <int> v;

class UnionFind {
private: 
	v id, rank; 

public:
	UnionFind(int V) {
		id.resize(V + 1);
		rank.resize(V + 1);

		for(int i = 1; i < V + 1; i++) {
			id[i] = i;
			rank[i] = 1;
		}
	}

	int find(int p) {
		if (p == id[p])
			return p; 
		return id[p] = find(id[p]);
	}

	void join(int p, int q) {
		p = find(p);
		q = find(q);

		if(find(p) == find(q))
			return;

		if(rank[p] > rank[q])
			swap(p, q); 

		id[p] = id[q];
		rank[p] += rank[q];
	}
};

vector <edge> kruskal(edgeList E, int Vsize) {
	vector<edge> ans; 
	pair<long long, edge> temp;
	UnionFind uf(Vsize);

	sort(E.begin(), E.end());	// sort para algoritmo guloso

	for(int i = 0; i < E.size(); i++) {
		temp = E[i];

		if(uf.find(temp.second.first) != uf.find(temp.second.second)) {
			uf.join(temp.second.first, temp.second.second);
			ans.push_back(temp.second);
		}
	}

	sort(ans.begin(), ans.end()); // sort para cout

	return ans;
}

int main() {
	int N, M, i, count = 1; 
	edgeList E; 
	vector<edge> res;
	
	cin >> N >> M; 

	while(N + M > 0) {
		E.resize(M); 
		
		for(i = 0; i < M; i++) {
			int a, b; 
			cin >> a >> b >> E[i].first;
			
			if(a > b)
				swap(a, b);
			E[i].second = make_pair(a, b);
		}

		res = kruskal(E, N);

		cout << "Teste " << count << endl;
		for(edge e : res) 
			cout << e.first << " " << e.second << endl;
		cout << endl;

		cin >> N >> M;
		count++;
	}
}