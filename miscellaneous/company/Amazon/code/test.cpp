#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define TRvi(it, c) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define inf 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
#define scan(x) scanf("%d",x)
#define ll long long
#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define LSOne(x) x&(-x)
#define debug(x) cout << #x << " " << x << endl;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int partition(int arr[], int low, int high){
  int p = high;
  int pIndex = low;
  for (int i = low; i < high; i++)
    if (arr[i] < arr[p]){
      swap(&arr[i], &arr[pIndex]);
      pIndex++;
  }
  swap(&arr[p], &arr[pIndex]);
  return pIndex;
}

void quicksort(int arr[],int low, int high){
  if (low < high){
    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot-1);
    quicksort(arr, pivot+1, high);
  }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif

    int arr[] = {8, 2, 4, 10, 7};
    quicksort(arr, 0, 5);
    for (int x = 0; x < 5; x++)
    printf("%d ",arr[x]);

    return 0;
}
