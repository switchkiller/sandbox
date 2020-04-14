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
#include <unordered_map>

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

bool mycompare(pair<string, pair<string,unordered_map<string, vector<string> >::iterator> > i1, pair<string, pair<string,unordered_map<string, vector<string> >::iterator> > i2)
{   if (i1.first == i2.first){
      return i1.second.first < i2.second.first;
    }
    return (i1.first < i2.first);
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif

    int n;
    cin >> n;
    unordered_map<string, vector<string> > mp_with_words;
    unordered_map<string, vector<string> > mp_with_ints;
    for(int i = 0; i < n; i++){
      string alpha;
      cin >> alpha;
      string rest;
      cin >> rest;
      istringstream ss(rest);
      do{
        string word;
        ss >> word;
        if (isdigit(word[0])){
          mp_with_ints[alpha].push_back(word);
        } else{
          mp_with_words[alpha].push_back(word);
        }
      } while(ss);
    }

    vector<pair<string, pair<string,unordered_map<string, vector<string> >::iterator> > > vi;

    for (unordered_map<string, vector<string> >::iterator mpitr = mp_with_words.begin(); mpitr != mp_with_words.end(); mpitr++){
      string wordn = "";
      for (int i = 0; i < mpitr->second.size(); i++){
        wordn += mpitr->second[i];
      }
      pair<string,unordered_map<string, vector<string> >::iterator> p;
      pair<string, pair<string,unordered_map<string, vector<string> >::iterator> > pi;
      p.first = mpitr->first;
      p.second = mpitr;
      pi.first = wordn;
      pi.second = p;

      vi.push_back(pi);
    }
    sort(vi.begin(),vi.end(),mycompare);

    for (int i = 0; i < vi.size(); i++){
      cout << vi[i].second.second->first;

      for (vector<string>::iterator itr = vi[i].second.second->second.begin(); itr != vi[i].second.second->second.end(); itr++){
        cout << " ";
        cout << *itr;
      }
      cout << endl;
    }

    return 0;
 }
