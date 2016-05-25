// Bruteforcing sucks

#include<bits/stdc++.h>

using namespace std;


#define REP(i,a,b) for (int i = (a); i < (b); i++)

int main(){
	int n,m;
	cin >> n >> m;
	int arr[n][m];
	
	REP(i,0,n)
		REP(j,0,m)
			cin >> arr[i][j];

	int ans[n][m], pos=0, distx, disty, dist;
	memset(ans, 0, sizeof ans);
	REP(l,0,n)
		REP(k,0,m)
			REP(i,0,n)
				REP(j,0,m){
					if (arr[i][j]){
						disty = abs(l-i); distx = abs(k-j); dist = distx+disty;
						cout << ans[l][k] << " " << dist <<  endl;
						ans[l][k] += 2*(dist+1)*arr[i][j];
						// cout << l <<" " <<  k << " " << ans[l][k] << endl;
					}
				}
	int minx=0, miny=0, minval=ans[0][0];
	// cout << minval;
	REP(i,0,n)
		REP(j,0,m){
			if (minval > ans[i][j]){
				minval = ans[i][j]; 
				minx = j;
				miny = i;
			}
		}

	cout << miny+1 << " " << minx+1 << " " << minval;
	return 0;
}