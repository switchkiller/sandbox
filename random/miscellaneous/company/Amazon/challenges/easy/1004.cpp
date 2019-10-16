// Concept: Remove all the trailing spaces. Now as you hit a string, store it...
// As soon as you hit first space, store it, but not for trailing spaces.
// Now to remove space before .?!, as soon as you hit it, check if before there was a space
// If yes, overwrite to that index. We are sure at max one space is going to present.

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

void removeSpaces(string &str){
  int i = 0, j = -1;
  int n = str.length();
  bool spacefound = false;
  while (++j < n && str[j] == ' ');
  while (j < n){
    if (str[j] != ' '){
      if ((str[j] == '.' || str[j] == '!' || str[j] == '?') && (str[i-1] == ' ') && (i-1) >= 0)
        str[i-1] = str[j++];
      else
        str[i++] = str[j++];
      spacefound = false;
    }
    else if (str[j++] == ' '){
      if (!spacefound){
        str[i++] = ' ';
        spacefound = true;
      }
    }
  }
  str.erase(str.begin()+i-1, str.end());
}

int main(){
  string s = "   Hello Geeks . Welcome   to  GeeksforGeeks   .    ";
  removeSpaces(s);
  cout << s;
  return 0;
}
