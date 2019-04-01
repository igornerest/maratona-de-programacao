//https://www.spoj.com/problems/KOPC12A/
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

#define N 10010

int height[N], cost[N], n;

ll f(int h) {
    ll ans = 0;
    
    for(int i = 0; i < n; i++)
        ans +=  abs(height[i] - h) * cost[i];

    return ans;
}

ll ternary_search(int lo, int hi) {
    while(hi - lo > 1) {
        int mid = lo + (hi - lo)/2;
        if(f(mid) > f(mid+1))
            lo = mid;
        else 
            hi = mid;
    }
    return f(lo+1);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        
        int hmax = 0, hmin = INF;
        for(int i = 0; i < n; i++) {
            cin >> height[i];
            hmax = max(hmax, height[i]);
            hmin = min(hmin, height[i]);
        }

        for(int i = 0; i < n; i++)
            cin >> cost[i];
        
        cout << ternary_search(hmin-1, hmax+1) << endl;
    }
	return 0;
}

