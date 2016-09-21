#include<iostream>
#include<string>
using namespace std;
int main(){
    int t,zeroes=0,ones=0,lastdigit,darray[100],length;
    string d;
    cin>>t;
    // if(t>=1 && t<=50)
       for(int i=0;i<t;i++){
        zeroes=0;
        ones=0;
        cin>>d;
        length=d.size();
        if(length>=1 && length<=50){
        for(int i = 0; i < length; i++){
            darray[i] = d[i]-48;
        }
        while(true){
            if(darray[0]==0)
                break;
            else{
                lastdigit = darray[length-1];
                darray[length-1]=0;
                if(lastdigit == 0)
                    zeroes++;
                else if(lastdigit==1)
                    ones++;
            }
            length--;
        }
        }
        else
            continue;
        if(ones==1|| zeroes==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

        cout<<"Number of Ones are "<<ones<<" And Number of Zeroes are "<<zeroes<<endl;
        }
    return 0;
}
