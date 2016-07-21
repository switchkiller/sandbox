
#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
#define scan(x) scanf("%d",x)
#define LL long long
#define MP make_pair
#define sqr(x) ((x)*(x))

int n, x;
priority_queue<int, vector<int>, greater<int> > pq;
char s[20];
vector< pair<int, int> > ans;
char la[3][20]={"insert","getMin","removeMin"};


int main(){
    scan(&n);
    REP(i,0,n){
        scanf(" ");
        scanf("%s", s);
        if (s[0] == 'i'){
            scan(&x);
            pq.push(x);
            ans.push_back(MP(0,x));
        }
        else if (s[0] == 'r'){
            if (pq.empty()){
                pq.push(0);
                ans.push_back(MP(0,x));
            }
            pq.pop(); ans.push_back(MP(2,0));
        }
        else{
            scan(&x);
            while(!pq.empty()){
                int temp = pq.top();
                if (temp < x){
                    pq.pop();
                    ans.push_back(MP(2,temp));
                }
                else break;
            }
            if (pq.empty() || pq.top() > x){
                pq.push(x);
                ans.push_back(MP(0,x));
            }
            ans.push_back(MP(1,x));
        }
    }

    cout << ans.size() << endl;

    REP(i,0,ans.size()){
        printf("%s", la[ans[i].first]);
        if (ans[i].first != 2) printf(" %d\n", ans[i].second);
        else printf("\n");
    }
    return 0;
}
