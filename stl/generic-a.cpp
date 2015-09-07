//Using the STL generic reverse algorithm with string and an array
#include<iostream>
#include<string.h>
#include<cassert>
#include<algorithm>
#define all(x) x.begin(), x.end()
using namespace std;
int main(){
  string string1 = "Allahdin";
  reverse(all(string1));
  assert(string1 == "nidhallA");

  //True.
  cout<<"1.";
  //---
  char arr[] = "Allahdin";
  int n = strlen(arr);
  reverse(&arr[0], &arr[n]);
  assert(string(arr) == "nidhallA");
  //True.
  cout<<"2.";
  return 0;
}
