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
int cnt=0;
bool notPeak[50];
int n;

bool isPeak(int a, int b, int c){
  if (a < b && b > c)
    return true;
  return false;
}

void findPeak(int arr[], int a, int b){
  if (a < 0 || b > n)
    return;
  if (a == b) return;
  int mid = (a + b) / 2;
  if (isPeak(arr[mid-1], arr[mid], arr[mid+1])){
    cout << arr[mid] << endl;
    cnt++;
  }
  findPeak(arr, a, mid ); findPeak(arr, mid+1, b );
}
//
// void findPeak(int arr[], int a, int b){
//   if (a < 0 || b > n)
//     return;
//   if (a == b) return;
//   int mid = (a + b) / 2;
//   if (notPeak[mid] == true)
//     return;
//   if (isPeak(arr[mid-1], arr[mid], arr[mid+1])){
//     notPeak[mid-1] = notPeak[mid+1] = true;
//     cnt++;
//   }
//   else
//     notPeak[mid] = true;
//   findPeak(arr, a, mid ); findPeak(arr, mid+1, b );
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    //  freopen("in.txt" , "r" , stdin);
    //  freopen("out.txt" , "w" , stdout);
    #endif
    cin >> n;
    int arr[50];
    REP(i,0,n)
      cin >> arr[i];
    n--;
    // arr[] = {1, 3, 4, 9, 6, 10, 7};
    findPeak(arr, 0, n);
    // cout << cnt << endl;
    // FOR(i,0,n)
    //   if (notPeak[i])
    //     cout << arr[i] << " ";
    return 0;
}
