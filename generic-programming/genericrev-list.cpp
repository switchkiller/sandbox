#include<iostream>
#include<list>
#include<algorithm>
#include<string.h>

using namespace std;

template <typename Container>
Container make(const char s[]){
  return Container(&s[0], &s[strlen(s)]);
}
int main(){
  //Demonstrating generic reverse algorithm on a list
  list<char> list = make< list<char> > ("Allahdin");
  reverse(list.begin(), list.end());
  return 0;
}
