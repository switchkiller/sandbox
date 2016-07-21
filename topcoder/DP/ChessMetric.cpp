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

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
class ChessMetric{
    public:
        static const int MAX_SIZE = 101;
        static const int MAX_MOVES = 51;
        ll dp[MAX_SIZE][MAX_SIZE][MAX_MOVES];

        ll f(int x, int y, int size, int m){
            if (x < 0 || x > size || y < 0 || y > size)
                return 0;
            if (m < 0)
                return 0;
            if (dp[x][y][m] != -1)
                return dp[x][y][m];

            ll tmp = 0;

            FOR(dx,-1,1)
                FOR(dy,-1,1)
                    if (dx != 0 || dy != 0){
                        tmp += f(x+dx, y+dy, size, m-1);
                    }

            FOR(dx,-2,2)
                FOR(dy,-2,2){
                    if (abs(dx) + abs(dy) == 3){
                        tmp += f(x+dx, y+dy, size, m-1);
                    }
                }

            dp[x][y][m] = tmp;
            return tmp;
      }


        ll howMany(int size, vector< int > start, vector< int > end, int numMoves){
            int sx = start[0];
            int sy = start[1];
            int ex = end[0];
            int ey = end[1];
            memset(dp, -1, sizeof dp);
            dp[sx][sy][0] = 1;
            return f(ex, ey, size, numMoves);
        }
};
