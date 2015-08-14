#include<iostream>
#include<stdio.h>
#include<stdlib.h>

void calculate(int price[],int n,int s[])
{
	s[0]=1;
	for ( int i=1; i<n; i++ )
	{
		s[i]=1;
		for ( int j=i-1; (j>=0) && (price[i]>=price[j]); j--)
			s[i]++;
	}
}

void printArray(int arr[], int n)
{
	for ( int i=0; i<n ; i++ )
		printf("%d",arr[i]);
}
 


int main()
{
	int price[]={10,4,5,90,120,80};
	int n=sizeof(price)/sizeof(int);
	int s[n];
	calculate(price,n,s);
	printArray(s,n);
	return 0;
}
