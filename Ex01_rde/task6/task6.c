#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
  //call fork() from a loop
  for(int count=0;count<3;count++)
    fork();

  printf("Gabriel Del Razo\n");
  return 0;
}
