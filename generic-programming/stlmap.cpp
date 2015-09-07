//STL map
#include<iostream>
#include<map>
#include<string.h>

using namespace std;

int main(){
  map<string, long> directory;
  directory["Bogart"] = 1234567;
  directory["Bacall"] = 9876543;
  directory["Cagney"] = 3456789;
  //blah blah

  string name;
  while (cin >> name)
    if (directory.find(name) != directory.end())
      cout << "The phone number for " << name <<" is " << directory[name] << "\n";
    else
      cout << "No listing for " << name << "\n";
  return 0;
}
