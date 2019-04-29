#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	char c[n][n];
	for(int i=0;i<=n-1;++i)
	{
		for(int j=0;j<=n-1;++j)
		{
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=n-2;++i)
	{
		for(int j=1;j<=n-2;++j)
		{
			if(c[i][j]=='.')
			{
				if(c[i+1][j]=='.'&&c[i-1][j]=='.'&&c[i][j+1]=='.'&&c[i][j-1]=='.')
				{
					c[i+1][j]=='#';
					c[i-1][j]=='#';
					c[i][j+1]=='#';
					c[i][j-1]=='#';
					c[i][j]=='#';
				}
			}
		}
	}
	for(int i=0;i<=n-1;++i)
	{
		for(int j=0;j<=n-1;++j)
		{
			if(c[i][j]=='.')
			{
				cout<<"NO";
				return 0;
			}
		}
		cout<<endl;
	}
	cout<<"YES";
	return 0;
}
