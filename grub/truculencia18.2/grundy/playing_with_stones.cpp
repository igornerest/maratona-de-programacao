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

ll mex(ll n) {
    return n % 2 == 1 ? mex(n/2) : n/2;
}

int main() {
    int t, n;
    cin >> t;

    while(t--) {
        ll ans = 0, stones;

        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> stones; ans ^= mex(stones);
        }
        
        if(ans == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;

    }
	return 0;
}

