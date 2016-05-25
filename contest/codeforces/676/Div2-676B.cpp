#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); i++)
int main(){
	double w[11][11];
	int n,t,res=0,i,j;
	cin >> n >> t;
	w[1][1]=t;
	REP(i,1,n)
		REP(j,1,i)
			if(w[i][j]>=1){
				w[i+1][j]+=(w[i][j]-1)/2;
				w[i+1][j+1]+=(w[i][j]-1)/2;
				res++;
			}
	cout << res;
	return 0;
}