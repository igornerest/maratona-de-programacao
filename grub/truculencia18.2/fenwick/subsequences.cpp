//https://codeforces.com/contest/597/problem/C
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long  ull;
typedef long long           ll;
typedef pair<int, int>      ii;
typedef vector<ii>          vii;
typedef vector<int>         vi;

#define	INF	0x3f3f3f3f
#define	pb	push_back
#define	mk	make_pair
#define	fi	first
#define	se	second
#define	eb	emplace_back

#define N (int)1e5+10
#define K 15

ull m[K][N];
int n, k;

ull query(int k,int idx) {
    ull ans = 0;
    while(idx) {
        ans += m[k][idx];
        idx -= idx & -idx;
    }
    return ans;
}

void add(int k, int idx, ull val) {
    while(idx <= n) {
        m[k][idx] += val;
        idx += idx & -idx;
    }
}

int main() {
    cin >> n >> k;
    k++; // k + 1 elements
    vi a(n);

    memset(m, 0, sizeof(m));

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        add(1, a[i], 1);
        for(int j = 2; j <= k; j++) 
            add(j, a[i], query(j -1, a[i] - 1));
    }

    cout << query(k, n) << endl;

    return 0;
}

