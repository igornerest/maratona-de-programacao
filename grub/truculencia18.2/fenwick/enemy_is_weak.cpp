//https://codeforces.com/problemset/problem/61/E
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

#define MAX 1000010

ll m[MAX];
int n;

ll query(int idx) {
    ll ans = 0;
    while(idx) {
        ans += m[idx];
        idx -= idx & -idx;
    }
    return ans;
}

void add(int idx, int val) {
    while(idx <= n){
        m[idx] += val;
        idx += idx & -idx;
    }
}

int main() {    
    cin >> n;

    vi v(n), temp(n);
    memset(m, 0, sizeof(m));
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        temp[i] = v[i];
    }

    // compressao de coordenadas
    sort(temp.begin(), temp.end());
    temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
    
    map<int, int> id;
    for(int i = 0; i < temp.size(); i++)
        id[temp[i]] = i + 1;

    vector<ll> lsum(n);
    for(int i = n-1; i >= 0; i--) {
        lsum[i] = query(id[v[i]]-1);
        add(id[v[i]], 1);
    }
    
    memset(m, 0, sizeof(m));
    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += lsum[i] * (query(n) - query(id[v[i]]));
        add(id[v[i]], 1);
    }
    cout << ans << endl;

	return 0;
}

