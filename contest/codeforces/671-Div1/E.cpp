// Pending to solve 
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i=(a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i >= (b); i--)

int n, k;

int main(){
	cin >> n >> k;
	int w[n-1];
	int g[n];
	REP(i,0,n-1)
		cin >> w[i];
	REP(i,0,n)
		cin >> g[i];

	int op[n]; memset(op, 0, sizeof op);

	REP(i,0,n-1){
		if (w[i] > g[i]){
			if (w[i] - g[i] <= k){
				k = w[i] - g[i];
				g[i] = w[i];
			}
		}

	}

	return 0;
}
