#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i < (b); i++)
class tag{
public:
    string tag;
    std::map<char, char> mp;
    void push_tag(string str){
        REP(i,0,str.size())
          if (str[0] == '<'){
            tag[i] = str[i+1];
          }
    }
    void push_att(string attname, string attval){
        //mp.insert( std::pair<string, string> (attname, attval) );
    }

    void print_data(){
      cout << tag;
    }
};

int main(){
    int N,Q, cnt = 0, lt = 0, tagend;
    stack<tag> st;
    tag t[100];
    string tag;
    string attname;
    string attval;
    cin >> N >> Q;
    while(N--){
      string str;
      cin >> str;
      istringstream iss(str);
      do{
        string process;
        iss >> process;
        if (cnt == 0){
          t[lt].push_tag(process);
        }
        t[lt].print_data();
        cnt++;
      }while(iss);
      t[lt].print_data();
      lt++;
      cnt = 0;
    }
    return 0;
}
        /*while (cin >> str){
            if (str[1] == '/') break;
            tagend=0;
            REP(i,1,str.size()){
                if (str[i] == ' '){
                    tagend = ++i;
                    break;
                }
                tag += str[i];
            }
            cout << tag;
            tag.clear();*/
         /*  t[cnt].push_tag(tag);
            while (str[tagend] != '>'){
                while (tagend != str.size()){
                    while (str[tagend] != '=')
                        attname += str[tagend++];
                    while (str[tagend] != ' '){
                        attval += str[tagend++];
                    }
                    cout << attname << attval;
                    t[cnt].push_att(attname, attval);
                    attname.clear();
                    attval.clear();
            }
        }
        */
        //st.push(t[cnt]);
      //  cnt++;
    //}
