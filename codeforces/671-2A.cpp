#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define INF 1e18+5

typedef long long ll;

double distance(int x1, int x2, int y1, int y2){return sqrt((ll)(x1-x2)*(x1-x2)+(ll)(y1-y2)*(y1-y2));}

int main(){
    int ax, ay, bx, by, rx, ry, n;
    cin >> ax >> ay >> bx >> by >> rx >> ry >> n;
    int x, y;

    double p[n+10], q[n+10], r[n+10], all=0.0;
    REP(i,1,n+1){
        cin >> x >> y;
        double a = distance(rx,x,ry,y);
        all += a*2;
        p[i] = q[i] = distance(bx,x,by,y) - a;
        r[i] = distance(ax,x,ay,y) - a;
    }

    p[0] = q[n+1] = INF;
    REP(i,1,n+1) p[i] = min(p[i-1], p[i]);
    RREP(i,n,0) q[i] = min(q[i+1], q[i]);

    double ans = q[1] + all;

    REP(i,1,n+1)
        ans = min(ans, all + r[i] + min(0.0, min(p[i-1], q[i+1])));

    cout.precision(12);
    cout << ans;
    return 0;
}
