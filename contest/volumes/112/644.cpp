/*---------------------
| Author: switchkiller |
| Problem: UVa 644     |
| Tags: general        |
----------------------*/
#include<bits/stdc++.h>
vector<string> vec;
#define all(X) X.begin(), X.end()
bool ans;
bool cmp(string a, string b){
  return a.size() < b.size();
}
bool isPrefix(strig toSearch, string target){
  for (int i = 0; i < toSearch.size(); i++){
    if (toSearch[i] != target[i])
      return false;
  }
  return true;
}
int main(){
  string str;
  while(cin >> str){
    if (str == "9"){
      ans = false;
      sort(all(vec), cmp);
      for (int x = 0; x < vec.size() && !ans; x++){
        for (int y = x + 1; y < vec.size() && !ans; y++){
          toSearch = vec[x], target = vec[y];
          if (!isPrefix(toSearch, target)){
            ans = true;
            break;
          }
        }
      }
      if (ans)
        printf("Set %d is not immediately decodable\n",gL++);
      else
        printf("Set %d is immediately decodable\n", gL++);
      vec.clear();
    }
    else{
      vec.push_back(str);
    }
  }
  return 0;
}
