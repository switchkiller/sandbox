//Generic Find algorithm with a vector.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#define all(c) c.begin(), c.end()
using namespace std;
template <typename Container>
Container make(const char s[]){
  return Container(&s[0], &s[strlen(s)]);
}

int main(){
  vector<char> v = make < vector<char> > ("C++ is a better C");

  //Search.
  vector<char>::iterator where = find(all(v), 'e');
  asser(*where == 'e' && *(where + 1) == 't');
  cout<<"Its all okay.";
  return 0;
}
