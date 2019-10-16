#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, cnt =0;
	string str;
	char delimeter[] = " ";
	cin >> N;
	while (N--){
		cin >> str;
		
		vector<string> in;
		stringstream ss(str);
		string temp;

		while(getline(ss, temp, " ")){
			in.push_back(temp);
			cnt++;
		}

		for(vector<string>::iterator itr = in.rbegin(); itr != in.rend(); itr++){
			cout << *itr;
			if (cnt--) cout << " ";
		} 
	}
	return 0;
}