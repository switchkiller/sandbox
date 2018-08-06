#include <bits/stdc++.h>
#include<cmath>
#include<cstring>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int l,i,c1=0,c2=0;
		l=n*m;
		char arr[l+1];
		for (i=0;i<l;i++)
		      cin>>arr[i];
		if (m%2!=0){
			for (i=0;i<l;i++)
			{
				if (i%2==0 && arr[i]=='R')   c1=c1+5;
				if (i%2!=0 && arr[i]=='G')   c1=c1+3;
			}
			for (i=0;i<l;i++)
			{
				if (i%2!=0 && arr[i]=='R')   c2=c2+5;
				if (i%2==0 && arr[i]=='G')   c2=c2+3;
			}
		}
		else
		{
			for (i=0;i<l;i++)
			{
				if ( (i%2)/(i/m)==0 && arr[i]=='R')   c1=c1+5;
				if ( (i%2)/(i/m)!=0 && arr[i]=='G')   c1=c1+3;
			}
			for (i=0;i<l;i++)
			{
				if ( (i%2)/(i/m)!=0 && arr[i]=='R')   c2=c2+5;
				if ( (i%2)/(i/m)==0 && arr[i]=='G')   c2=c2+3;
			}
		}
		cout<<min(c1,c2)<<"\n";
	}
	return 0;
}
