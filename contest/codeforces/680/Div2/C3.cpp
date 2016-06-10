// Bear and Tower of Cubes
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
inline ll sq(ll n)
{
    return n*n*n;
}
 pair<ll,ll> best;
void rec(ll m,ll steps,ll sum)
{
    if(m==0)
    {
       best=max(best,make_pair(steps,sum));
       return;
    }
    else
    { Hello World
        ll x=1;
        while(sq(x+1)<=m) x++;
        rec(m-sq(x),steps+1,sum+sq(x));
        if(x>=1)
        {
            rec(sq(x)-1-sq(x-1),steps+1,sum+=sq(x-1));
        }
    }
}
int main(){
    ll m;
    cin>>m;
    rec(m,0,0);
    cout<<best.first<<" "<<best.second<<endl;
	return 0;
}
