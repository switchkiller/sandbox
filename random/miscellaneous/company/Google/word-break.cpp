#include<iostream>
#include<set>
#include<string.h>
using namespace std;

const int N = 100;
set<string> dictionary{"Me","at","google"}; // in c++11

bool wordBreak(string str){
  int n = str.length();
  bool dp[N];
  for (int i = 0; i < n; i++){
    set<string>::iterator it;
    it = dictionary.find(str.substr(0,i+1));
    if (it != dictionary.end())
      dp[i] = true;
    if (dp[i] == true){
      for (int j = i + 1; j < n; j++){
        set<string>::iterator it;
        it = dictionary.find(str.substr(i+1,j));
        if (it != dictionary.end())
          dp[j] = true;
        if (j == n-1 && dp[n-1] == true)
          return true;
      }
    }
  }

  // for (int i = 0; i < n; i++)
  //   cout << dp[i] << " ";

  return false;
}

int main(){
  string s = "Meatgoogl";

  cout << wordBreak(s);

  return 0;
}
