// Still not complete
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i=(a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i >= (b); i--)

int main(){
	int n, t;
	string s;
	cin >> n >> t >> s;
	int br[n]; 
	int flag = (s[0]=='a') ? 0 : 1, brs=0;
	memset(br, 0, sizeof br);
	REP(i,0,n){
	 	if (s[i] == 'a'){
	 		if (flag == 1){
	 			flag = 0;
	 			brs++;
	 		}
	 	}
	 	else if (s[i] == 'b'){
	 		if (flag == 0){
	 			flag = 1;
	 			brs++;
	 		}
	 	}
	 	br[brs]++;
	}

	REP(i,0,brs+1)
		cout << br[i];

	// int tmax, cmax = 0, temp=0;
	// REP(i, 1, brs){
	// 	int l = br[i-1], mid = br[i], r = br[i+1];

	// 	tmax = l +  
	// 	cmax = max(cmax, tmax);
	// }

	return 0;
}

/*
aaaa
bbbbb
bbabb
bbaabb
aaba
aabbaa

*/