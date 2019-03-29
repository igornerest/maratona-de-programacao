//https://www.spoj.com/problems/MATSUM/
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

#define MAX 1050

int m[MAX][MAX], base[MAX][MAX], n;

int query(int lin, int col) {
    int ans = 0;

    for(int i = lin; i > 0; i -= i & -i)
        for(int j = col; j > 0; j -= j & -j)
            ans += m[i][j];
    
    return ans;
}

void add(int lin, int col, int val) {
    val -= base[lin][col];
    base[lin][col] += val;

    for(int i = lin; i <= n; i += i & -i)
        for(int j = col; j <= n; j += j & -j)
            m[i][j] += val;
}

int main() {
    int t;
    char cmd[4];

    scanf("%d", &t);
    while(t--){
        scanf("%d\n", &n);
        
        memset(m, 0, sizeof(m));
        memset(base, 0, sizeof(base));

        while(scanf("%s", cmd) && strcmp(cmd,"END")) {
           if(strcmp(cmd, "SET") == 0) {
                int x, y, val;
                scanf("%d %d %d", &x, &y, &val);
                add(x+1, y+1, val);
            } else {
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

                int ans = query(x2+1, y2+1) - query(x2+1, y1) - query(x1, y2+1) + query(x1, y1);
                printf("%d\n", ans);
            }
        }

    }
	return 0;
}

