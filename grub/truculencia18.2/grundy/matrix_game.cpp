//https://www.spoj.com/problems/MATGAME/
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

int b[60][60];
int n, m; 

int grundy(){
    int i, j, ans = 0;

    for(i = 0; i <  n; i++){
        for(j = m - 2; j >= 0; j--)
            if(b[i][j+1] >= b[i][j])
                b[i][j]--;
        ans ^= b[i][0];
    }
    
    return ans;
}

int main() {
    int t;
    
    cin >> t;
    while(t--){
        cin >> n >> m;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> b[i][j];
        
        cout << (grundy() == 0 ? "SECOND" : "FIRST") << endl;
    }

	return 0;
}
