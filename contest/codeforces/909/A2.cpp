#include <bits/stdc++.h>
using namespace std;

int main() {
	int i,w;
	char str[20];
	char ch[20];
	scanf("%s",str);
	scanf("%s",ch);
	w=strlen(str);
	printf("%c",str[0]);
	for (i=1;i<w;i++){
		if (str[i]<ch[0]){
			printf("%c",str[i]);
		}

	}
	printf("%c",ch[0]);
	return 0;
}
