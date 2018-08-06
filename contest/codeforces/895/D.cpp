#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;
#define m 1000000007
void swap(char *a,char *b)
{
    if( *a == *b )
        return;
    *a^=*b;
    *b^=*a;
    *a^=*b;
}
void rev(string& s,int l,int r)
{
    while(l<r)
        swap(&s[l++],&s[r--]);
}

int bsearch (string& s,int l,int r,int key)
{
    int index = -1;
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(s[mid]<=key)
            r=mid-1;
        else
        {
            l=mid+1;
            if(index = -1 || s[index]>=s[mid])
                index = mid;
        }
    }
return index;
}

bool nextpermutation(string& s)
{
    int len = s.length(), i=len-2;
    while(i>=0 && s[i]>=s[i+1])
       --i;
    if(i<0)
        return false;
    else
    {
        int index=bsearch(s,i+1,len-1,s[i]);
        swap(&s[i],&s[index]);
        rev(s,i+1,len-1);
        return true;
    }
}
int main()
{
	long long int i,j,k,c=0,n,d;
    string s,f;
    cin>>s>>f;
    for(i=0;;i++)
    {
	bool val = nextpermutation(s);
	if (val == false)
	{
		cout<<c%m;
		break;
	}
	else
	{
		bool e=lexicographical_compare(s.begin(),s.end(),f.begin(),f.end());
		if(e==false)
		{
			d++;
			cout<<c%m;
			break;
		}
		else
			c++;
	}
	if(d>0)
		break;
    }
    return 0;
}
