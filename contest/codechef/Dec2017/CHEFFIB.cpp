#include<stdio.h>
#include<stdlib.h>

int* chefFib(int x);
int* fibList(int x);
int* subsetSum(int list[], int n,int x);

int main()
{
	int q;
	scanf("%d",&q);
	for(int i=0; i<q; i++)
	{
		int x,k;
		scanf("%d",&x);
		scanf("%d",&k);
		int* arr;
		arr=chefFib(x);
	/*	if(arr[1]==k)
		{
			printf("%d",arr[2]);
			printf("\n");
		}*/
		for(int j=0 ; j<=(x/2) ; j++)
		 if(arr[j]!=0)
		   printf("\n%d",arr[j]);

	}

return 0;
}

int* chefFib(int x)
{
	int* list = fibList(x);
//	int n = sizeof(list)/sizeof(list[0]);
//	int* sublist = subsetSum(list,n,x);
//	int arr[] = {1,2};
	return list;
}

int* fibList(int x)
{
	int *fib = (int *)malloc((sizeof(int))*2);
	int n=2;
	fib[0] = 1;
	fib[1] = 2;
	for(int i=2 ; i<=(x/2); i++)
	{
		if((fib[i-1]+fib[i-2])<=x)
		{
			n++;
			fib = realloc(fib,sizeof(int)*(n));
			fib[i]=(fib[i-1]+fib[i-2]);
			printf("fib %d",fib[i]);
		}
		else
			break;
	}
	printf("%d",n);
	//int arr[] = {1,2};
	return fib;
}

int* subsetSum(int* list, int n,int x)
{
	int arr[] = {1,2};
	return arr;
}
