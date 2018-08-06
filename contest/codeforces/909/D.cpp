#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin>>s;
	int n=s.size();
	int j=0;
	int a[1500000];
	char sim[1500000];
	for(int i=0;i<n;i++){
		sim[j]=s[i];
		a[j]=1;
		while(s[i]==s[i+1]&&i<n-1){
			a[j]++;
			i++;
		}
		j++;
	}
	int k=0;
	while(j!=1){
		int min = 1500000;
		if(min>a[0]){
			min=a[0];
		}
		if(min>a[j-1]){
			min=a[j-1];
		}
		for(int i=1;i<j-1;i++){
			if((a[i]+1)/2<min){
				min=a[i];
			}
		}
		a[0]-min;
		a[j-1]-min;
		for(int i=1;i<j-1;i++){
			a[i]-min;
		}
		k+=min;
	//	cout<<min<<endl;
		int g=0;
		for(int i=0;i<j;j++){
			if(a[i]>0){
				a[g]=a[i];
				sim[g]=sim[i];
				g++;
			}
		}
		j=g;
		g=0;
		for(int i=0;i<j;i++){
			a[g]=a[i];
			sim[g]=sim[i];
			while(sim[i]==sim[i+1]&&i<n-1){
				a[g]+=a[i+1];
				i++;
			}
			g++;
		}
		j=g;
	}
	cout<<k;
	return 0;
}
