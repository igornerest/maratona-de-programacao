//https://www.spoj.com/problems/NWERC11C/
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

class fenwick_tree {
private:
    vi m;
    int n;

public:
    void build(int nMovies, int r) {
        n = nMovies + r;
        m.assign(n+1, 0);
        for(int i = 1; i<= nMovies; i++)
            add(i, 1);
    }

    int query(int idx){
        int ans = 0;
        while(idx){
            ans += m[idx];
            idx -= idx & -idx;
        }
        return ans;
    }

    void add(int idx, int val) {
        while(idx <= n) {
            m[idx] += val;
            idx += idx & -idx;
        }
    }
};

fenwick_tree fw;
vi collection; 

int main() {
    int t, n, r;
    cin >> t;
    while(t--) {
        cin >> n >> r;
    
        fw.build(n, r);
        collection.resize(n + 1);

        for(int i = 1; i <= n; i++)
            collection[i] = n + 1 - i;
        
        int abovePos = n + 1;
        for(int i = 0; i < r; i++) {
            int input;
            cin >> input;
            
            cout << n - fw.query(collection[input]) << endl;
            
            fw.add(collection[input], -1);
            collection[input] = abovePos++; 
            fw.add(collection[input], 1);
        }   
    }
	return 0;
}

