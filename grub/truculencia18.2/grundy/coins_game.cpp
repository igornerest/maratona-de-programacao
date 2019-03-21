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

int k, l;
bool state[1000010];

void game(){
    state[0] = false;
    for(int i = 1; i <= 1000000; i++) {
        state[i] = !state[i - 1];
        if(i >= l)
            state[i] |= !state[i - l];
        if(i >= k)
            state[i] |= !state[i - k];
    }
}

int main() {
    int n, input;
    cin >> k >> l >> n;
    
    game();

    for(int i = 0; i < n ; i++){
        cin >> input;
        if(state[input]) 
            cout << "A";
        else
            cout << "B";
    }
    cout << endl;
	
    return 0;
}

