// Intuition - n = p ^ i => i <= log(n) Since p >= 2. So will find nth root using Netwon's formula. Will find if its integer..check prime or not (using rabin-miller)
// Tags - number theory
// Difficulty - Easy


#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define inf 0x3f3f3f3f

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

int main(){
    int t; long long n, x, val=1;
    cin >> t;
    while (t--){
        cin >> n;
        int flag = 0;
        while (n){
            val = 1;
            FOR(i,1,log2(n)){
                x = pow(n, 1.0/i);
                if (isint(x)){
                    if (Miller(x,5)){
                        long long tmp = pow(x,i);
                        val = max(val, tmp);
                        cout << x << " " << i << " " << val << endl;
                    }
                }
            }
            n -= val;
            flag = (flag + 1) % 2;
        }
        if (flag) cout << "Chef\n";
        else cout << "Misha\n";
    }
    return 0;
}
