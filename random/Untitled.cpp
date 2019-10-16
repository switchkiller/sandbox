#include<iostream>
using namespace std;
class base{
public:
  virtual void show()=0;
};
int main(void){
base b;
base *b;
return 0;
}
