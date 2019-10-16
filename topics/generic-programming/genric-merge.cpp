//Generic Merge with an array, list and a deque.
#include<iostream>
#include<cassert>
#include<list>
#include<deque>
#include<algorithm>
#include<string.h>

#define all(X) X.begin(), X.end();

using namespace std;

template <typename Container>
Container make(const char s[]){
  return Container(&s[0], &s[strlen(s)]);
}

int main(){
  char s[] = "aeiou";
  int len = strlen(s);
  list<char> l = make< list<char> >("bcdefghijklmnopqrstuvwxyz");

  //initialize dq with 26 copies of the letter x:
  deque<char> dq(26,'x');

  //merge array s and l, put the result in dq:
  merge(&s[0], &s[len], all(l), dq.begin());
  assert(dq == make< deque<char> >"abcdefghijklmnopqrstuvwxyz");
  cout<<"Its all okay.";
  return 0; 
}
