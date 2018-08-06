#include <stdio.h>
#include <string.h>

int length;
char arr[60];
char brr[60];
void  permutation(int i,int vis[])
{
    int j;
    if(i==length)
    {
        for(j=0;j<length;j++)
        {
            printf("%c",brr[j]);
        }
        printf("\n");
        return ;
    }
    for(j=0;j<length;j++)
    {
        if(vis[j]==0)
        {
            vis[j]=1;
            brr[i]=arr[j];
            permutation(i+1,vis);
            vis[j]=0;
        }
    }
    return ; 
}

int main()
{
    int i;
    int vis[60];
    scanf("%s",arr);
    length=strlen(arr);
    for(i=0;i<length;i++)
    {
        vis[i]=0;
    }
    permutation(0,vis);
    return 0;
}
