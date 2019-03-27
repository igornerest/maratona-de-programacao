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

#define MAX 200020

int p[MAX], v[MAX], n;

int sum(int idx) {
    int res = 0; 
    while(idx){
        res += p[idx];
        idx -= idx & (-idx);
    }
    return res;
}

void add(int idx, int val) {
    val -= v[idx];
    v[idx] += val;

    while(idx <= n) {
        p[idx] += val;
        idx += idx & (-idx);
    }
}

int main() {
    int  a, b, cnt = 1;
    string q;
     
    while(cin >> n && n){
        if(cnt > 1) 
            cout << endl;
        
        memset(p, 0, sizeof(p));
        memset(v, 0, sizeof(v));

        for(int i = 1; i <= n; i++){
            cin >> a;
            add(i, a);
        }
       
        cout << "Case " << cnt++ << ":\n";

        while(cin >> q && q != "END") {
            cin >> a >> b;
            if(q == "S")
                add(a, b);
            else
                cout << sum(b) - sum(a - 1) << endl;
        }
	}

    return 0;
}

