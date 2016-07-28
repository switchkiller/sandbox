#include<stdio.h>


void reverse(char *a, char *b){
  char temp;
  while (a < b){
    temp = *a;
    *a++ = *b;
    *b-- = temp;
  }
}

char *reversePrint(char *s){
  char *word_begin = NULL;
  char *temp = s;

  while (*temp){
    if (word_begin == NULL && (*temp) != ' ')
      word_begin = temp;
    if (word_begin && (*(temp+1) == '\0' || *(temp+1) == ' ')){
      reverse(word_begin, temp);
      word_begin = NULL;
    }
    temp++;
  }
  printf("%s\n",s);
  reverse(s,temp-1);
}

int main(){
  char s[] = "I love my planet earth";
  reversePrint(s);
  printf("%s\n",s);
  return 0;
}
