/* Problem Description:
  Recursively remove all adjacent duplicates
*/

#include<bits/stdc++.h>

using namespace std;

string recurdelete(string str, int idx){
  if (idx == str.length()) return "\0";
  return (str[idx] == str[idx-1] || str[idx] == str[idx+1]) ? recurdelete(str,idx+1) : str[idx] + recurdelete(str,idx+1);
}

int dulforever(string str){
  int cnt = 0;
  if (str.length() == 1) return 1;
  // case 1
  if (str[0] != str[1]) cnt++;
  for (int i = 1; i < str.length()-1; i++)
    if (str[i] != str[i-1] && str[i] != str[i+1]) cnt++;
  // case 2
  if (str[str.length()-1] != str[str.length()-2]) cnt++;
  return (cnt >= 1);
}

string untilunique(string str, int idx){
  if (!dulforever(str)) return "";
  string res = recurdelete(str,idx);
  for (int i = 0; i < res.length()-1; i++)
  if (res[i] == res[i+1]) return untilunique(res,idx);
  return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--){
      string str;
      cin >> str;
      // cout << dulforever(str);
      cout << untilunique(str, 0) << endl;
    }
    return 0;
 }
