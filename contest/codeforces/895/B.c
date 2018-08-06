#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map < pair<ll,ll> , ll > mp;
ll fun(ll a[],ll i,ll j,ll k,ll x){
	if(i>j){
		return 0;
	}
	mp[make_pair(a[i],a[j])]++;
	ll val=0,ans=0;
	if(a[i]%x==0){
		val=1;
	}
	if((val+(a[j]-a[i])/x)>k){
		return fun(a,i+1,j,k,x)+fun(a,i,j-1,k,x);
	}else if((val+(a[j]-a[i])/x)==k){
		auto it=mp.find(make_pair(a[i],a[j]));
		if(it->second==1){
			ans=1;
		}
		return ans+fun(a,i+1,j,k,x)+fun(a,i,j-1,k,x);
	}else{
		return 0;
	}
}
int main(){
	ll n,x,k;
	scanf("%ld%ld%ld",&n,&x,&k);
	ll a[n];
	for(ll i=0;i<n;i++){
		scanf("%ld",&a[i]);
	}
	sort(a,a+n);
	printf("%ld\n",fun(a,0,n-1,k,x));
	return 0;
}
