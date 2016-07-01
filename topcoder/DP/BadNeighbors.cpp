#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define inf 0x3f3f3f3f
#define ll long long
#define mp make_pair
#define pb push_back
#define LSOne(x) x&(-x)
#define debug(x) cout << #x << " " << x << endl;
#define N 40

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class BadNeighbors{
  public:
      int maxDonations(vector <int> donations){
          n = donations.size();
          int dp[N] = {0};
          bool zero[N], idx[N];
          dp[0] = a[0];
          idx[0] = zero[0] = true;

          if (a[1] > dp[0]){
              dp[1] = a[1];
              idx[0] = true;
          }
          else{
              dp[1] = dp[0];
              zero[1] = true;
          }
          // Note that dp[i-2] is sum before a[i-1] actually occured. This plays an important role.
          REP(i,2,n){
              if (dp[i-2] + a[i] > dp[i-1]){
                  dp[i] = dp[i-2] + a[i];
                  idx[i] = true;
                  zero[i] = zero[i-2];
              }
              else{
                  dp[i] = dp[i-1];
                  zero[i] = zero[i-1];
              }
          }
          // If first and last are both contributing, take maximum of who contributed.
          if (zero[n-1] && idx[n-1])
              cout << max(dp[n-2], max(dp[n-1]-a[n-1], dp[n-1]-a[0]));
          else   cout << dp[n-1];


      }

};
