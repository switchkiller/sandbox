#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a-1); i >= (b); i--)
#define MAX 100

int main(){
	freopen("in-large.txt" , "r" , stdin);
    freopen("out-large.txt" , "w" , stdout);
	int T, K, C, S;
	cin >> T;
	REP(i,0,T){
		cin >> K >> C >> S;
		int s = (C == 1 || K == 1) ? K : K - 1;
		if (S < s)
			cout << "Case #" << i+1 << ": IMPOSSIBLE" << endl;
		else{
			int st = (C == 1 || K == 1) ? 1 : 2;
			int en = K;
			string tmp = "";
			REP(j,st,en+1){
				tmp += std::to_string(j) + " "; // Use C++ 11 'g++ -std=c++0x' and compile
			}
			tmp = tmp.substr(0,tmp.size()-1);
			cout << "Case #" << i+1 << ": " << tmp << endl;
		}
	}
	return 0;
}