#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
  pid_t pid=fork();
  //child process - return value is zero
  if(pid==0)
    printf("Child Print: Gabriel \n");

  //Parent process -return value is not zero
  else if(pid!=0)
    printf("ParentPrint: Del Razo\n");

  return 0;
}
