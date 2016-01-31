#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
char * division(char dividend[],int divisor){
    static char quotient[MAX];
    long temp=0;
    int i=0,j=0;
    while(dividend[i]){
         temp = temp*10 + (dividend[i] -48);
         if(temp<divisor){
             quotient[j++] = 48;
         }
         else{
             quotient[j++] = (temp / divisor) + 48;;
             temp = temp % divisor;
         }
         i++;
    }
    quotient[j] = '\0';
    return quotient;
}

int main(){
  ios_base::sync_with_stdio(0);
  char *quotient;
  char N[MAX];
  int T, K;
  int val = 0;
  cin >> T;
  while(T--){
    cin >> N >> K;
    quotient = division(N,K);
    while(*quotient)
             if(*quotient == 48){
                 val = 1;
                 quotient++;}
             else{
                 val = 0;
                 break;
               }
  if (val == 1) cout << "NO";

  else if (val == 0)
    cout << "YES";
  cout << endl;
  }
  return 0;
}
