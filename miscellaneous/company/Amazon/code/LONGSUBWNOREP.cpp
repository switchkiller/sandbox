// Find the longest substring with no repeatation characters.
#include<iostream>
#include<string.h>
#include<map>
using namespace std;

void longestSubstringNoRep(string &str){
  map<char, int> mp;
  for (char i = 'A'; i <= 'Z'; i++ )
    mp[i] = -1;
  int currentLength = 1;
  int prev = 0;
  int maxLength = 1;
  int strIdx = 0;
  mp[str[0]] = 0;

  for (int i = 1; i < str.size(); i++){
    prev = mp[str[i]];

    if (prev == -1 || i - currentLength > prev)
      currentLength++;
    else{
      if (currentLength > maxLength){
        strIdx = i - currentLength;
        maxLength = currentLength;
      }

      currentLength = i - prev;
    }
    mp[str[i]] = i;
    // cout << currentLength << " ";
  }

  str = str.substr(strIdx, maxLength);
}

int main(){
  string s;
  cin >> s;
  longestSubstringNoRep(s);
  cout << s;
  return 0;
}
