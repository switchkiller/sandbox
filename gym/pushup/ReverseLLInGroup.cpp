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

const unsigned int MOD = 1000000007;
const int MAX = 1000000;
unsigned long long preprocess[MAX];
unsigned long long ump[MAX];
unsigned ll ans = 0;

struct LinkedList{
    int val;
    struct LinkedList *next;
};

void insertNode(LinkedList **head, int val){
  LinkedList *node = new LinkedList;
  node->val = val;
  node->next = *head;
  *head = node;
}

void printLinkedList(LinkedList *head){
  while(head){
    cout << head->val << " ";
    head = head->next;
  }
}
// Use recursion..iteration is getting messy.
void reverseLinkedListInGroup(LinkedList **head,int k){
  LinkedList *prev = NULL, *interchange_node = NULL, *curr = *head;
  int count = 0; *head = NULL;
  interchange_node = curr;
  while(curr){
    count++;
    LinkedList *next = curr->next;
    if (next)
      curr->next = prev;
    prev = curr;
    if (count == k){
      if (*head == NULL){
        *head = curr;
        cout << interchange_node->val << endl;
      }
      interchange_node->next = curr;
      prev = interchange_node;
      count = 0;
    }
        curr = next;
  }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
   //  freopen("in" , "r" , stdin);
   //  freopen("out" , "w" , stdout);
    #endif

    LinkedList *head = NULL;

    int n;
    cin >> n;
    while(n--){
      int x;
      cin >> x;
      insertNode(&head, x);
    }
    int k;
    cin >> k;

    printLinkedList(head);

    cout << endl;

    reverseLinkedListInGroup(&head,k);
    printLinkedList(head);

    return 0;
 }
