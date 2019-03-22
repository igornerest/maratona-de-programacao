//https://www.spoj.com/problems/SUBSUMS/
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

vi subarray(vi &seq, int ini, int end){
	int n = end - ini + 1;
	vi x(1<<n);

	for(int i=0; i<(1<<n); i++){
		int sum = 0;
		for(int j=0; j<n; j++)
			if(i & (1<<j))		
				sum += seq[ini + j];
		x[i] = sum;
	}	
	return x;
}

ll solve(vi &seq, int min, int max) {
	int mid = (seq.size() - 1)/2;
	vi x = subarray(seq, 0, mid);
	vi y = subarray(seq, mid+1, seq.size() - 1);
	
	sort(y.begin(), y.end());

	ll sum = 0;
	for(int i = 0; i < x.size(); i++){
		auto low = lower_bound(y.begin(), y.end(), min - x[i]);
		auto high = upper_bound(y.begin(), y.end(), max - x[i]);
		sum += high - low;	
	}

	return sum;
}

int main() {
	int n, min, max;
	vi seq;
	
	cin >> n >> min >> max;
	
	seq.resize(n);
	for(int i=0; i<n; i++)
		cin >> seq[i];

	cout << solve(seq, min, max) << endl;
	
	return 0;
}

