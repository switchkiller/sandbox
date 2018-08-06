#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void replace(char *string, char *from, char *to){
char *result;
int i, cnt = 0;
int newWlen = strlen(to);
int oldWlen = strlen(from);

for(i = 0; string[i] != '\0'; i++){
 if (strstr(&string[i], from) == &string[i]){
  cnt++;
  i += oldWlen - 1;
 }
}
result = (char *) malloc(i+cnt*(newWlen-oldWlen)+1);
i = 0;
while (*string){
 if (strstr(string, from) == string){
 strcpy(&result[i], to);
 i += newWlen;
 s += oldWlen;
 }
 else
  result[i++] = *string++;
}
result[i] = '\0';
string = result;
}

int main(){
         char string[] = "reoragnize";
         printf("String is %s Before Replacement\n",string);
         replace(string, "ag", "ga");
         printf("String is %s After Replacement\n",string);
         strcpy(string,"Hello World");
         printf("String is %s Before Replacement\n",string);
         replace(string, "Hello", "Hi");
         printf("String is %s After Replacement\n",string);
         printf("String is %s Before Replacement\n",string);
         replace(string, "Hi World", "Hello");
         printf("String is %s After Replacement\n",string);
         return 0;
}
