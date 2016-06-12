// Intuition - n = p ^ i => i <= log(n) Since p >= 2. So will find nth root using Netwon's formula. Will find if its integer..check prime or not (using rabin-miller)
// Tags - number theory
// Difficulty - Easy


#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define inf 0x3f3f3f3f
#define all(X) X.begin(), X.end()

bool isint(int x){
    return (x == (int) x);
}

int modulo(int a,int b,int c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}

long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

bool Miller(long long p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
         while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}


vector<int> v;
map<int, bool> p;

void chefncoin(int n){
    if (n == 0 || n == 1)
        return ;
    else if (find(all(v), n) != v.end())
        return;
    v.push_back(n);
    chefncoin(n-1);
    long long tmp, x, rem;
    FOR(i,1,log2(n)){
        x = pow(n,1.0/i);
        if (isint(x) && Miller(x,5)){
            tmp = pow(x,i);
            rem = n - tmp;
            if (rem == 0)
                p[n] = true;
            chefncoin(rem);
        }
    }
    return;
}

int main(){
    int t; long long n, x, val=1;
    cin >> t;
    while (t--){
        cin >> n;
        v.clear();
        p.clear();
        chefncoin(n);
        sort(all(v));

        // REP(i,0,v.size())
        //     cout <<  v[i] << " ";
        //
        // for (map<int, bool>::iterator it = p.begin(); it != p.end(); it++)
        //     cout << it->first << " " << it->second << endl;

        map<int, int> mp;
        mp[0] = 0;
        mp[1] = 0;
        int x;
        REP(i,0,v.size()){
            if (p[v[i]]){
                mp[v[i]]=0;}
                // cout << v[i] <<" " << 0 << endl;}
            else{
                int tmp, rem;
                mp[v[i]] = 1;
                if (!p[v[i]-1]){
                    mp[v[i]] = v[i]-1;
                    continue;
                }
                FOR(j,1,log2(v[i])){
                    x = pow(v[i],1.0/j);
                    if (isint(x) && Miller(x,5)){
                        tmp = pow(x,j);
                        rem = v[i] - tmp;
                        if (!p[rem]){
                            mp[v[i]]=rem;
                            // cout << v[i] << " " << rem << endl;
                            // cout << rem << endl;
                            break;
                        }
                    }
                }
            }
        }

        // for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
        //     cout << it->first << " " << it->second << endl;

        int flag = 0;
        while (mp[n]){
            n = mp[n];
            flag++;
        }
        if (flag % 2) cout << "Misha\n";
        else cout << "Chef\n";
    }
    return 0;
}
