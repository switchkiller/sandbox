#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)

int main(){
	int n;
	string s;
	cin >> s >> n;
	int sz = s.size();
	map<char, int> mp;
	REP(i,0,sz)
		mp[s[i]] = i;

	string str;

	REP(i,0,n){
		int correct=0, incorrect=0;
		cin >> str;
		REP(i,0,sz){
			if (mp.find(str[i]) != mp.end()){
				if (i == mp[str[i]])
					correct++;
				else
					incorrect++;
			}
		}

		cout << correct << " " << incorrect << endl; 
	}

	return 0;
}