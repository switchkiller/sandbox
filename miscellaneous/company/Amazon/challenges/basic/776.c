// Used queue to generate binary numbers from 1 to n.
//          1
//        /   \
//      0      1
//     /\      /\
//    0  1    0  1
//
// Create a queue. First add 1. Now pop it, print, append 0 and 1 and form new numbers
// and push into queue. Do same for new elements in the queue. 
//

#include<stdio.h>
#include<string.h>

#define N 550

void enqueue(char queue[][10], int n, int *front, int *rear, char item[]){
  if (*rear >= n) return;

  if (*front == -1)
    *front = 0;

  strcpy(queue[++(*rear)], item);
}

char *dequeue(char queue[][10], int n, int *front){
  if (*front == n) return;

  return queue[(*front)++];
}



int main(){
  int t, n;
  scanf("%d",&t );
  while (t--){
    scanf("%d",&n );
    char queue[N][10];
    int front = -1, rear = -1;
    memset(queue, '\0',sizeof queue);
    int size = n;
    enqueue(queue, size, &front, &rear, "1");

    while (n--){
      char tmp[10];
      strcpy(tmp, dequeue(queue,size,&front));
      printf("%s ", tmp);
      int len = strlen(tmp);
      tmp[len] = '0';
      tmp[len+1] = '\0';

      enqueue(queue, size, &front, &rear, tmp );

      tmp[len] = '1';

      enqueue(queue, size, &front, &rear, tmp );
    }
    printf("\n");

  }
  return 0;
}
