// Given stream of data, Date and name, check if name appeared on the same date twice

#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  string str;
  unordered_map<string, int> mp;
  while(getline(cin,str)){
    stringstream ss(str);
    string key, value;
    ss >> key;
    ss >> value;
    key.append(value);
    if (mp.find(key) != mp.end()){
      cout << 0;
      return 0;
    }
    else
      mp[key] = 1;
  }
  cout << 1;
  return 0;
}
