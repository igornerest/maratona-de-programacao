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

#define MAX 10000010

int seq[MAX], n;

int query(int idx) {
    int ans = 0;
    while(idx > 0) {
        ans += seq[idx];
        idx -= idx & (-idx);
    }
    return ans;
}

void add(int idx, int val){
    while(idx <= n) {
        seq[idx] += val;
        idx += idx & (-idx);
    }
}

int main() {
    int t;

    cin >> t;
    while(t--) {
        int sup = 0, m;

        cin >> m;
        
        vi v(m);
        for(int i = 0; i < m; i++) {
            cin >> v[i];
            sup = max(sup, v[i]);
        }
            
        n = sup;
        memset(seq, 0, sizeof(seq));
        ll ans = 0;

        for(int i = m -1; i >= 0; i--) {
            ans += query(v[i] - 1);
            add(v[i], 1);
        }

        cout << ans << endl;
    }
	return 0;
}

