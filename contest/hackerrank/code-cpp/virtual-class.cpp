#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100
class Person{
public:
  char name[100];
  int age;
  virtual void getdata(){  };
  virtual void putdata(){  };
};
class Professor: public Person{
public:
  int publications;
  static int current_id;
  int val;
  void getdata(){
    cin >> name;
    cin >> age;
    cin >> publications;
    current_id += 1;
    val = current_id;
  }
  void putdata(){
    cout << name << " " << age << " " << publications << " " << val << endl;
  }
};
class Student: public Person{
public:
  int mark[6];
  int sum;
  int val;
  static int current_id;
  void getdata(){
      sum = 0;
      cin >> name;
      cin >> age;
      for (int i = 0; i < 6; i++){
        cin >> mark[i];
        sum += mark[i];
      }
      current_id += 1;
      val = current_id;
  }
  void putdata(){
    cout << name << " " << age << " "<< sum << " " << val << endl;
  }
};
int Professor::current_id = 0;
int Student::current_id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
