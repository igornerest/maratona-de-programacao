//https://codeforces.com/gym/101908/problem/B
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

#define N 100

bitset <4*N> used;
int grundy[N + 10][N + 10];

void marbles(int n) {
    int i, j, k;

    memset(grundy, -1, sizeof(grundy));
    grundy[1][2] = 0;
    grundy[2][1] = 0;

    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++) if(i != j){
            used.set(); // seta tudo para 1
        
            for(k = j - 1; k >= 0; k--) // para esquerda
                if(grundy[i][k] > -1)
                    used[grundy[i][k]] = 0;

            for(k = i - 1; k >= 0; k--) // para baixo
                if(grundy[k][j] > -1)
                    used[grundy[k][j]] = 0;

            for(k = 1; k <= min(j, i); k++)
                if(grundy[i - k][j - k] > -1)
                    used[grundy[i - k][j - k]] = 0;
			
			for(k = 0; used[k] != 1; k++);
			grundy[i][j] = k;

        }
    }
}

int main() {
    int n, ans = 0, a, b;
    bool diag = false;

    cin >> n;

    marbles(100); 
    while(n--){
        cin >> a >> b;
        if(grundy[a][b] == -1) 
			diag = true;
		else
			ans ^= grundy[a][b];
    }
 
    cout << (ans != 0 || diag ? "Y" : "N") << endl;
	return 0;
}

