/* Problem Description:

*/

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

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

#define MIN_SCORE 1

struct data{
  int value;
  int index;
};

struct mycompare{
  bool operator()(data x1, data x2){
    return (x1.value > x2.value);
  }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif

    int n;
    cin >> n;
    data ratings[n];
    int score[n];

    memset(score, 0, sizeof score);
    priority_queue<data, vector<data>, mycompare> pq;

    for (int i = 0; i < n; i++){
      data rating;
      cin >> rating.value;
      rating.index = i;
      ratings[i] = rating;
      pq.push(rating);
    }

    for (int i = 0; i < n; i++){
      data rating = pq.top();
      // cout << rating.index << endl;
      pq.pop();
      if (score[rating.index] == 0){
        //do something
        score[rating.index] = MIN_SCORE;
      } else{
        //do nothing
      }
      // update the adjacent
      if (rating.index > 0){
        if (ratings[rating.index-1].value > rating.value){
          if (score[rating.index] + 1 > score[rating.index-1])
            score[rating.index-1] = score[rating.index] + 1;
        }
      }
      if (rating.index < n-1){
        // cout << ratings[rating.index+1].value << " " << rating.value << endl;
        if (ratings[rating.index+1].value > rating.value){
          if (score[rating.index] + 1 > score[rating.index+1])
            score[rating.index+1] = score[rating.index] + 1;
        }
      }
    }
    int sum  = 0;
    for (int i = 0; i < n; i++){
      cout << score[i] << " " ;
      sum += score[i];
    }
    cout << sum << endl;
    return 0;
 }

 /*

// Leetcode submission->

 #define MIN_SCORE 1

struct Data{
  int value;
  int index;
};

struct mycompare{
  bool operator()(Data x1, Data x2){
    return (x1.value > x2.value);
  }
};

class Solution {
public:
    int candy(vector<int>& values) {
    int n = values.size();
 Data ratings[n];
    int score[n];

    memset(score, 0, sizeof score);
    priority_queue<Data, vector<Data>, mycompare> pq;

    for (int i = 0; i < n; i++){
      Data rating;
      rating.value = values[i];
      rating.index = i;
      ratings[i] = rating;
      pq.push(rating);
    }

    for (int i = 0; i < n; i++){
      Data rating = pq.top();
      pq.pop();
      if (score[rating.index] == 0){
        //do something
        score[rating.index] = MIN_SCORE;
      } else{
        //do nothing
      }
      // update the adjacent
      if (rating.index > 0){
        if (ratings[rating.index-1].value > rating.value){
            if (score[rating.index] + 1 > score[rating.index-1])
                score[rating.index-1] = score[rating.index] + 1;
        }
      }
      if (rating.index < n-1){
        if (ratings[rating.index+1].value > rating.value){
            if (score[rating.index] + 1 > score[rating.index+1])
                score[rating.index+1] = score[rating.index] + 1;
        }
      }
    }
    int sum  = 0;
    for (int i = 0; i < n; i++){
        //cout << score[i] << " ";
      sum += score[i];
    }
    return sum;
    }
};

 */
