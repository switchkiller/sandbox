#include <iostream>
using namespace std;
string temp;
char str[100];
void recur(char *s, char str[],int i, int j, int k){
    if (str[j] == '\0' ){
        cout << s << endl;
        return;
    }
    if (str[j] == temp[k]){
        s[i] = str[j];
        recur(s,str,i+1,j+1,k+1);
    }
    else if ((k-1) >= 0 && str[j] == temp[k-1]){
        s[i] = str[j];
        recur(s,str,i+1,j+1,k);
    }
    s[i] = '\0';
    recur(s,str,i,j+1,k);
}

int main() {
	//code
	temp = "abc";
	char s[100];
	cin >> str;
	recur(s,str,0,0,0);
	return 0;
}
