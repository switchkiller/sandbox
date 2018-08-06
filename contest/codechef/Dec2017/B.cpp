#include <iostream>
using namespace std;
int main(){
  bool f=true;
  while(f){
    string s;
      cin>>s;
      if(s=="") f=false;
      else{
      int cs=0; // chef shot;
      int bs=0; // team B shot;
      int cg=0; // chef goal;
      int bg=0; // team B goal;
      int i;    // iteration;
      for(i=0;i<10;i++){
      if(i%2==0){
           cs++;
           if(s.at(i)=='1') cg++;
                 }
      else{  bs++;
             if(s.at(i)=='1') bg++;
                  }
     if((cg-bg>=3)&& bs>=3||((cg-bg)>=2&&bs>=4))
       {
          cout<<"TEAM-A "<<i+1<<endl;
          i=100; }
      if((bg-cg>=3)||((bg-cg)>=2&&cs>=4)) {
               cout<<"TEAM-B "<<i+1<<endl;
               i=100;}
      if(i==9)  {
        if(cg>bg) cout<<"TEAM-A "<<i+1<<endl;
        if(cg<bg) cout<<"TEAM-B "<<i+1<<endl;
      }
      }
     if(i==10&&cg==bg){
      for(;i<20;i++){
        if(i%2==0&& s.at(i)=='1'&&s.at(i+1)!='1')  {
                    cout<<"TEAM-A "<<i+2<<endl;
                      i=24;
                      }
            if(i%2==1&& s.at(i-1)!='1'&&s.at(i)=='1'){
              cout<<"TEAM-B "<<i+1<<endl;
                      i=25;    }
      }
     }
      if(i==20)  cout<<"TIE"<<endl;
       }
      }}
