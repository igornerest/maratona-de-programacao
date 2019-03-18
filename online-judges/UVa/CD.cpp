// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=565
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

int N, T, ans, bitmask; 
vi cd;

void backtracking(int i, int cur, int bm) {
    if(i == T) {
        if(cur > ans){
            ans = cur;
            bitmask = bm;
        }
        return;
    }
    backtracking(i + 1, cur, bm);
    if(cd[i] + cur <= N) backtracking(i + 1, cur + cd[i], bm |= (1 << i));
}


int main() {
	while(cin >> N >> T) {
		cd.resize(T);
		for(int i = 0; i < T; i++)
			cin >> cd[i];
        
        ans = 0;
        backtracking(0, 0, 0);
        for(int i = 0; i < T; i++) {
            if(bitmask & (1 << i))
                cout << cd[i] << " ";
        }
        cout << "sum:" << ans << endl;
    }    
	return 0;
}

