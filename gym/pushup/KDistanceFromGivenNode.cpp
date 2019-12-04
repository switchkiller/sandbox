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
struct Node
{
    int data;
    struct Node *left, *right;
};


void printkdistanceNodeDown(Node *root, int k){
  if (root == NULL || k < 0) return;

  if (k == 0) {
    cout << root->data << endl;
    return;
  }

  printkdistanceNodeDown(root->left, k-1);
  printkdistanceNodeDown(root->right, k-1);
}

int printkdistanceNode(Node *root, Node* target, int k){
  if (root == NULL) return -1;

  if (root == target){
    // do something
    // traverse the bottom of the tree and print nodes at k distance from target
    printkdistanceNodeDown(root,k);

    return 0;
  }

  int dl = printkdistanceNode(root->left, target,k);

  if (dl != -1){
    // it means that we have found the target somewhere in left subtree.

    if (dl+1 == k)
      cout << root->data << endl;
    else
      printkdistanceNodeDown(root->right,k-(dl+2));

    return dl+1;
  }

  int dr = printkdistanceNode(root->right,target,k);

  if (dr != -1){
    if (dr+1 == k)
      cout << root->data << endl;
    else
      printkdistanceNodeDown(root->left, k-(dr+2));

    return dr+1;
  }

  return -1;
}


// A utility function to create a new binary tree node
Node *newnode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    Node * root = newnode(20);
    root->left = newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    Node * target = root->left->right;
    printkdistanceNode(root, target, 2);
    return 0;
}
