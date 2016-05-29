#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i=(a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i >= (b); i--)
#define MIN 10000000
#define MAX -10000000

int w[500000], t, mn=MIN, mx=MAX, mxpos, mnpos;
long k;

int fmnmx(){
	REP(i,0,t){
		if (w[i] > mx){
			mx = w[i];
			mxpos = i; }
		if (w[i] < mn){
			mn = w[i];
			mnpos = i; }
	}
}

int main(){
	cin >> t >> k;
	REP(i,0,t)
		cin >> w[i];
	while (k){
		fmnmx();
		w[mxpos]--;
		if (w[mxpos] > w[mnpos]){
			w[mnpos]++; }
		else{
			w[mxpos]++;
			break; }
		k--;
		mx=MAX, mn=MIN;
	}
	fmnmx();
	cout << w[mxpos] - w[mnpos] << endl;	
	return 0;
}
