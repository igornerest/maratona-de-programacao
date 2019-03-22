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

#define N 12

int solve(vi &c, int tot){
    int ans = 0;
    for(int i=0; i<(1<<c.size()); i++){
        int smaller = 0, sum = 0, qtd = 0;
        for(int j=0; j<c.size(); j++){
            if(i & (1<<j)) {
                if(smaller == 0)
                    smaller = c[j];
                sum += c[j];
                qtd++;
            }
        }
        if(sum >= tot && sum - smaller < tot && ans < qtd)
            ans = qtd;
    }

    return ans;
}

int main() {
    int t, n, total;
    cin >> t;

    while(t--){
        cin >> n >> total;
        vi coin(n);
        
        for(int i=0; i<n; i++)
            cin >> coin[i];
        
        sort(coin.begin(), coin.end());
        cout << solve(coin, total) << endl;
    }
	return 0;
}

