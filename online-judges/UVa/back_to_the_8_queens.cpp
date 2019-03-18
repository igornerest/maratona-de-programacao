//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2026
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

int row[8], ans[8], minimum;

bool place(int r, int c) {
	for(int i = 0; i < c; i++)
		if(ans[i] == r || abs(i - c) == abs(ans[i] - r)) return false;
	return true;
}

void compare(){
	int sum = 0;
	for(int i = 0; i < 8; i++)
		if(row[i] != ans[i])
			sum++;
	if(minimum > sum) minimum = sum;
	return;	
}

void backtracking(int c) {
	if(c == 8){ 
        compare(); 
        return;
    }	
	for(int i = 0; i < 8; i++){
		if(place(i, c)){
			ans[c] = i;
			backtracking(c + 1);
		}
	}
}

int main() {
	int count = 1;	
	while(cin >> row[0]){
		row[0]--;
		for(int i = 1; i < 8; i++){
			cin >> row[i];
			row[i]--;
		}
		minimum = 8;
		backtracking(0);
		cout << "Case " << count++ << ": " << minimum << endl;   
	}	
	return 0;
}

