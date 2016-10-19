/* Problem Description:

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

priority_queue< int, std::vector<int>, std::greater<int> > low;
priority_queue<int> high;

void addNumber(int number) {
  if(low.size()==0 || number<low.top())
    low.push(number);
  else
    high.push(number);
}

void rebalance() {
    if (low.size() > high.size()){
      priority_queue< int, std::vector<int>, std::greater<int> > biggerHeap = low;
      priority_queue<int> smallerHeap = high;
      if(biggerHeap.size() - smallerHeap.size()>=2) {
          smallerHeap.push(biggerHeap.top());
          biggerHeap.pop();
      }
    }
    else{
      priority_queue<int> biggerHeap = high;
      priority_queue< int, std::vector<int>, std::greater<int> > smallerHeap = low;
      if(biggerHeap.size() - smallerHeap.size()>=2) {
          smallerHeap.push(biggerHeap.top());
          biggerHeap.pop();
      }
    }
    // if(biggerHeap.size() - smallerHeap.size()>=2) {
    //     smallerHeap.push(biggerHeap.top());
    //     biggerHeap.pop();
    // }
}

double getMedians(){
  if (low.size() > high.size()){
    priority_queue< int, std::vector<int>, std::greater<int> > biggerHeap = low;
    priority_queue<int> smallerHeap = high;
    if(biggerHeap.size()==smallerHeap.size()) {
        return (double) (biggerHeap.top() + smallerHeap.top())/2;
    } else {
        return biggerHeap.top();
    }

  }
  else{
    priority_queue<int> biggerHeap = high;
    priority_queue< int, std::vector<int>, std::greater<int> > smallerHeap = low;
    if(biggerHeap.size()==smallerHeap.size()) {
        return (double) (biggerHeap.top() + smallerHeap.top())/2;
    } else {
        return biggerHeap.top();
    }
  }
    //
    // if(biggerHeap.size()==smallerHeap.size()) {
    //     return (double) (biggerHeap.top() + smallerHeap.top())/2;
    // } else {
    //     return biggerHeap.top();
    // }

}

double getMedian(int number, int first, int pos, int win) {
    if(pos<win) {
        addNumber(number);
        rebalance();
        return (double) 0.0;
    } else if(pos>=win) {
        double median = getMedians();
        if(low.top()<first) {
          priority_queue<int> temp;
          while(high.top()!=first){
            int t=high.top();
            high.pop();
            temp.push(t);
          }
          high.pop();
          while(!temp.empty()){
            int t=temp.top();
            temp.pop();
            high.push(t);
          }
        } else {
          priority_queue<int> temp;
          while(low.top()!=first){
            int t=low.top();
            low.pop();
            temp.push(t);
          }
          low.pop();
          while(!temp.empty()){
            int t=temp.top();
            temp.pop();
            low.push(t);
          }
        }
        addNumber(number);
        rebalance();
        return median;
    }
    return (double) 0.0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif

    int n, d;
    cin >> n >> d;
    vector<int> ls;
    long count = 0;
    for(int i=0;i<n;i++) {
      int x;
      cin >> x;
      ls.push_back(x);
      int first = -1;
      if(i<d){
        first = -1;
      } else if(i>=d) {
        first = ls[0];
        ls.erase(ls.begin());
      }
      double median = getMedian(x,first,i,d);
      if(i<d) {
        continue;
      } else if(i>=d) {
        if(x>=2*median)
          count++;
      }
    }
    cout << count << endl;
    return 0;
 }
