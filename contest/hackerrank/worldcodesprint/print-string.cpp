// Concept - suffix tree
#include<bits/stdc++.h>
using namespace std;
#define REP(a,b,i) for (int i = (a); i < (b); i++)
typedef map<char, int> mp;
struct trie_node_t {
    typedef map<char, trie_node_t *> child_node_t;
    child_node_t m_childMap;
    trie_node_t() : m_childMap(map<char, trie_node_t*>()) {}

    void insert( string& word ) {
        trie_node_t *pNode = this;
        for ( string::const_iterator itr = word.begin(); itr != word.end(); ++itr) {
            char letter = *itr;
            if ( pNode->m_childMap.find(letter) == pNode->m_childMap.end()){
                pNode->m_childMap[letter] = new trie_node_t();
            }
            pNode = pNode->m_childMap[letter];
        }
    }


    void print() {
    }
};

int MaxCost(string str, int N, int A, int B)
{ string temp='';
  REP(0, str.size()){
    temp += str[i];
    trie_node_t trie;
    trie.insert(string(temp));
    trie.print();
  }


}
int main(){
  string str = "";
  int t, N, A, B;
  cin >> t;
  while (t--){
    cin >> N >> A >> B;
    cin >> str;
    cout << MaxCost(str, N, A, B) << endl;
  }
  return 0;
}
