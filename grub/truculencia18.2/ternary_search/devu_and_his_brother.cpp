//https://codeforces.com/problemset/problem/439/D
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

#define N 100010

int a[N], b[N], n, m;

ll f(int k) {
    ll cost = 0;

    for(int i = 0; i < n; i++) if(a[i] < k)
        cost += abs(a[i] - k);
    for(int i = 0; i < m; i++) if(b[i] > k)
        cost += abs(b[i] - k);

    return cost;

}

ll ternary_search(int lo, int hi) {
    lo--; hi++;
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
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    
    sort(a, a+n);
    sort(b, b+m);
    cout << ternary_search(a[0], b[m-1]) << endl;

	return 0;
}

