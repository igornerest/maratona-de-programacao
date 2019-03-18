//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1517
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

int money[12], s, d, total;

bool deficit(int pos) {
    int sum = 0;
    for(int i = pos-5; i < pos; i++)
        sum += money[i];
    if(sum < 0) return true;
    return false;
}

void backtracking(int month){
    if(month > 4 && deficit(month)==false) return;
    if(month == 12){
        int sum = 0;
        for(int i = 0; i < 12; i++)
            sum += money[i];
        if(total < sum)
            total = sum;

        return;
    }
    money[month] = s;
    backtracking(month + 1);
    money[month] = d * -1;
    backtracking(month + 1);
}

int main() {
    while(cin >> s >> d) {
        total = -INF;
        backtracking(0);
        if(total < 0)
            cout << "Deficit" << endl;
        else
            cout << total << endl;
    }
	return 0;
}

