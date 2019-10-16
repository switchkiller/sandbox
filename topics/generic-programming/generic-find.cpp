//Generic Find algorithm with an array
#include<iostream>
#include<cassert>
#include<algorithm>
#include<string.h>
using namespace std;

int main(){
  char s[] = "C++ is a better C";
  int len = strlen(s);
  const char* where = find(&s[0], &s[len], 'e');
  assert(*where == 'e' && *(where + 1) == 't');
  cout<<"Its all okay.";
  return 0; 
}
