#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a-1); i >= (b); i--)
#define MAX 100

int main(){
	freopen("in-large.txt" , "r" , stdin);
    freopen("out-large.txt" , "w" , stdout);
	
	int T, cntf;
	cin >> T;
	REP(i,0,T){
		char S[MAX]; 
		cntf = 0;
		cin >> S;
		RREP(j,strlen(S),0){ 
			if (S[j] == '+')
				continue;
			else{
				cntf++;
				if (S[0] == '+'){
					cntf++;
					int l = 0;
					while (S[l] == '+') l++;
					REP(k,0,l)
						S[k] = '-';
				}
			}
			int l = j + 1;
			REP(k,0,l/2){
				char temp = S[k];
				S[k] = S[l-k-1];
				S[l-k-1] = temp;
			}
			REP(k,0,j+1) S[k] = (S[k] == '+' )? '-' : '+'; 
		}
		cout << "Case #" << i+1 << ": " << cntf << endl;
	}
	return 0;
}
