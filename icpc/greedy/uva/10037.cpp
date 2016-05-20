// Pending

#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define all(X) X.rbegin(), X.rend()
int main(){
	int T, N;
	cin >> T;
	while (T--){
		cin >> N;
		vector<int> A(N), B(N);
		REP(i,0,N)
			cin >> A[i];
		sort(all(A));
		N--;
		while (N+1){
			B.push_back(A[N-1]);
			B.push_back(A[N]);
			N -= 2;
			A[N+1]
		}

	}

	return 0;
}