#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b,c,d;
	long long cnt=0;
	cin >> n >> a >> b >> c >> d;

	// Quite Naive - TLE
	/*	for (int j = 1; j <= n; j++){
		for (int k = 1; k <= n; k++){
			int sum = a+b+j+k;
			if ((sum - (a+c+k) <= n) && (sum - (b+d+k) <= n) && (sum - (c+d+k) <= n) && (sum - (a+c+k) > 0) && (sum - (b+d+k) > 0 ) && (sum - (c+d+k) > 0))
				cnt++;
			// cout << j << " " << k << endl;
		}
	}*/

	// Linear Time solution O(N) very easy 
	for (int x = 1; x <= n; x++){
		int p = x+b-c;
		int q = x+a-d;
		int r = q+b-c;

		if (1 <= p && p <= n && 1 <= q && q <= n && 1 <= r && r <= n)
			cnt++;
	}
	cnt *= n;
	cout << cnt << endl;
	return 0;
}

/*
xap
byc
qdr
*/