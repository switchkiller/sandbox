//Generic find with a listing
#include<iostream>
#include<cassert>
#include<list>
#include<algorithm>
#include<string.h>
#define all(x) x.begin(),x.end()

using namespace std;

template <typename Container>
Container make(const char s[]){
  return Container(&s[0],&s[strlen(s)]);
}

int main(){
  list<char> l = make< list<char> >("C++ is a better C");

  //Search
  list<char>::iterator where = find(all(l),'e');
  list<char>::iterator next = where;
  ++next;
  assert(*where == 'e' && *next == 't');
  cout << "Its all okay.";
  return 0;
}
