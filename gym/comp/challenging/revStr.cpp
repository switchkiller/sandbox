/* Problem Description:
  Reversing the tokens pos
*/

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

string reverseString(string str, int start, int end){
  while(start < end){
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++, end--;
  }
}

string withOutDelimator(string str){
  int start = 0, end; string tmp = "";
  for (int i = 0; i < str.length(); ++i){
    tmp = "";
    if (str[i] == '.'){
      end = i-1;
      tmp = reverseString(str, start, end);
      for (int j = 0; j < tmp.length(); j++)
        str[j+start] = tmp[j];
      start = i+1;
    }
  }
  //corner case
  tmp = reverseString(str, start, end);
  for (int j = 0; j < tmp.length(); j++)
    str[j+start] = tmp[j];
  return str;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
      string str;
      cin >> str;
      str = withOutDelimator(str);
      cout << reverseString(str,0,str.length()-1) << endl;
    }

    return 0;
 }
