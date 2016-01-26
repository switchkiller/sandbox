#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int vals[] = {1, 2, 3};
  sort(vals, vals+3);
  cout << "Generating Permutation: ";
  do{
    cout << vals[0] << vals[1] << vals[2];
  }while(next_permutation(vals, vals+3));
  return 0;
}
