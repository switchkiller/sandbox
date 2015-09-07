//Using the STL generic reverse algorithm with a vector
#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<string.h>
using namespace std;
#define add(x) x.begin(), x.end()
template <typename Container>
Container make(const char s[]){
  return Container(&s[0], &s[strlen(s)]);
}
int main(){
    //Using reverse algorithm with a vector
    vector<char> v = make< vector<char> > ("Allahdin");
    reverse(add(v));
    assert(v == make< vector<char> > ("nidhallA"));
    cout<<"Okay.";
    return 0;
}
