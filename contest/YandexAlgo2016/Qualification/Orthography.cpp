// XXX incomplete

#include<bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	vector<string> str(N);
	for (int i = 0; i < N; i++){
		cin >> str[i];
	}

	int len = str[0].size();
	map<string, map<int, int> > mp[len][N];
	// Naive Solution
	int val =0;
	for (int i = 0; i < len; i++){
		char ch = str[i][val++];
		for (int j = 0; j < N; j++){
			mp[ch][j] = mp[ch][j-1] 

		}
	}

	return 0;
}