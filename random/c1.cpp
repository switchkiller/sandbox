#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;

void  subsetOfSizek(int arr[],int start, int n, int k, bool test[], int currlength, int x,int *p,int MIN,int MAX)
{
    if(currlength==k)
    {
       for(int i=0;i<n;i++)
       {
         if(test[i]==true)
         {
            if(arr[i] > MAX)
                MAX=arr[i];
            if(arr[i] < MIN)
                MIN=arr[i];
          }
        }
    }
    if(abs(MAX-MIN)<=x)
    {
      (*p)++;
      return;
    }
    if(start==n-1)
        return ;
    test[start]=true;
    subsetOfSizek(arr,start+1,n,k,test,currlength+1,x,p,INT_MAX,INT_MIN);
    test[start]=false;
    subsetOfSizek(arr,start+1,n,k,test,currlength,x,p,INT_MAX,INT_MIN);
    return ;
}

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int x;
    cin>>x;
    int arr[n];
    int *count=0;
    bool test[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    subsetOfSizek(arr,0,n,k,test,0,x,count,INT_MAX,INT_MIN);

    cout<<*count;
    return 0;
}
