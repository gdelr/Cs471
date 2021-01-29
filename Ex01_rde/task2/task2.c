#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
  fork();
  fork();
  fork();
  printf("Gabriel Del Razo\n");
  return 0;
}
