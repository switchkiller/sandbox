#include<iostream>

using namespace std;

#define A 1000
void bcdto7seg(int num){
  //char a = '_', b = '|';
  int a[7];
  int m,n,o,p;
  p = num & 1;
  o = (num & 2) / 2;
  n = (num & 4) / 4;
  m = (num & 8) / 8;
  cout<<m<<n<<o<<p<<endl;
  a[0] = (~(n ^ p)) | (m & n & o);
  a[1] = ~(o ^ p) | n;
  a[2] = m | (~o) | n | p;
  a[3] = (~m) & (~p) & (~(n ^ o));
  a[4] = (~n) & (~p) | m & (~o) & (~p) | o & (~p);
  a[5] = (~o) & (~p) | n & (~o) | m | n;
  a[6] = m | n & (~o) | (~m) & (~n) & o | o & (~p);

  for (int i = 0; i < 7; i++){
    cout << a[i];
  }
}

int main(){
  int num = 0;
  cin >> num;
  bcdto7seg(num);
  return 0;
}
