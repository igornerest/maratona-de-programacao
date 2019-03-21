//https://codeforces.com/problemset/problem/603/C
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

int sol[5] = {0, 1, 0, 1, 2};

int grundy(int n, int k) {
    if(k%2 == 1){ // impar
        if(n < 5) return sol[n];
        if(n%2 == 1) return 0;
        return (grundy(n/2, k) == 1 ? 2 : 1);
    } else{ // par
        if(n <= 2) return n;
        return (n+1)%2;
    }
}

int main() {
    int n, k, ans = 0, input;

    cin >> n >> k;
    while(n--){
        cin >> input;
        ans ^= grundy(input, k);
    }
    cout << (ans ? "Kevin" : "Nicky") << endl;
	
    return 0;
}

