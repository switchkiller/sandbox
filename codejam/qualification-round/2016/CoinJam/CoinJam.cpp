#include<bits/stdc++.h>
using namespace std;
#define LREP(i,a,b) for (long long i = (a); i < (b); i++)
#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define MAX 11
long val[MAX];
int J, N;
long NTD(long n){
	for (long i = 2; i <= sqrt(n+1); i++){ //Trivial we know n is not prime
		if (n % i == 0)
			return i;
	}
	return -1;
}
int getval(int i){
	string bin = bitset<32>(i).to_string();
	REP(base,2,11){
		// cout << J;
		long sum = 0;
		for (int i = bin.size()-1, j = 0; i >=0; i--,j++){
			if (bin[i] == '1')
				sum += pow(base,j);
		}
		long v = NTD(sum);
		//if (base == 10) cout << J;
		val[base] = v;
		//if (base == 10) cout << J;
		if (v == -1) return 0;
		//cout << "Base=" << base << J;
	}
	return 1;
}
int main(){
	//freopen("in-large.txt" , "r" , stdin);
    //freopen("out-large.txt" , "w" , stdout);
	int T;
	cin >> T;
	REP(i,0,T){
		cin >> N >> J;
		long long start = (1 << (N-1)) + 1;
		cout << start;
		long long end = 1 << N;
		cout << end;
		int s, flag = 0;
		cout << "Case #" << T << ": " << endl;
		LREP(j,start,end){
			// Trivial
			if (j % 2 == 0)
				continue;
			s = getval(j);
		//	cout << "J = " << J;
			if (s == 1){
				cout << bitset<32>(j).to_string();
				REP(base,2,10+1)
					cout << " " << val[base];
				cout << endl;
				flag++;
				//cout << "FLAG =" << flag<< "J= " << J <<endl; 
				if (flag == J)
					break;
			}
		}
	}
	return 0;
}